#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int n;
string s, t;
char ch[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s; n = s.size();
	for (int i = n-1; ~i; i--)
		if (i == n-1)
			ch[i] = s[i];
		else
			ch[i] = min(s[i], ch[i+1]);

	string temp;
	int cur = 0;
	while (t.size() < n){
		if (temp.empty() || (cur < n && ch[cur] < temp.back())){
			while (s[cur] != ch[cur]) temp.push_back(s[cur++]);
			t.push_back(s[cur++]);
		}
		else{
			t += temp.back();
			temp.pop_back();
		}
	}

	cout << t << "\n";
	return 0;
}