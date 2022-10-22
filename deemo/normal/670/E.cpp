#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>

using namespace std;

const int MAXN = 5e5 + 10;

int n, q, pos, sec[MAXN], tt;
string s, t;
char ch[MAXN];
set<int>	st;

int main(){
	scanf("%d %d %d", &n, &q, &pos), pos--;
	scanf("%s", ch);	s = ch;
	for (int i = 0; i < n; i++)	st.insert(i);
	scanf("%s", ch);	t = ch;
	for (int i = 0; i < q; i++){
		char type = t[i];
		if (type == 'L'){
			auto it = st.lower_bound(pos);
			it--;
			pos = *it;
		}
		else if (type == 'R'){
			auto it = st.upper_bound(pos);
			pos = *it;
		}
		else{
			if (s[pos] == ')'){
				auto it = st.lower_bound(pos);
				int sm = 0;
				do{
					sec[tt++] = *it;
					if (s[*it] == '(')	sm++;
					else	sm--;
					if (it != st.begin())	it--;
				}while (sm != 0);
			}
			else{
				auto it = st.lower_bound(pos);
				int sm = 0;
				do{
					sec[tt++] = *it;
					if (s[*it] == '(')	sm++;
					else	sm--;
					if (it != st.end())	it++;
				}while (sm != 0);
			}
			while (tt--)
				st.erase(sec[tt]);
			auto it = st.lower_bound(pos);
			if (it != st.end())	pos = *it;
			else{
				it--;
				pos = *it;
			}
		}
		tt = 0;
	}
	for (auto it:st)
		printf("%c", s[it]);
	printf("\n");
	return 0;
}