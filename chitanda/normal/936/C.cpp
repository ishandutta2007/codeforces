#include<bits/stdc++.h>
using namespace std;

int n;
char s[2100], ss[2100], t[2100];
int cnt[26];
vector<int> q;

void work(int l){
	for(int i = 0; i < l; ++i)
		ss[i] = s[n - 1 - i];
	for(int i = 0; i < n - l; ++i)
		ss[l + i] = s[i];
	for(int i = 0; i < n; ++i) s[i] = ss[i];
	//printf("%d: %s\n", l, s);
	q.push_back(l);
}

int main(){
	scanf("%d", &n);
	scanf("%s%s", s, t);
	for(int i = 0; i < n; ++i) ++cnt[s[i] - 'a'];
	for(int i = 0; i < n; ++i) --cnt[t[i] - 'a'];
	for(int i = 0; i < 26; ++i)
		if(cnt[i]){
			puts("-1");
			return 0;
		}

	for(int i = 0; i < n; ++i)
		if(s[i] == t[0]){
			if(i < n - 1) work(n - i - 1);
			break;
		}
	for(int i = 1; i < n; ++i){
		for(int j = 0; j < n - i; ++j)
			if(s[j] == t[i]){
				work(n - j - 1);
				work(1);
				work(n);
				break;
			}
	}
	printf("%d\n", (int)q.size());
	for(int v : q) printf("%d ", v);
	return 0;
}