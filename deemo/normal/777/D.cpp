//Where are you, hatter?

#include<bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 10;

int n;
string s[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> s[i];
	for (int i = n-2; ~i; i--)
		if (s[i] > s[i+1]){
			int lc = 0;
			while (lc < min(s[i].size(), s[i+1].size()) && s[i][lc] == s[i+1][lc]) lc++;
			s[i].resize(lc);
		}

	for (int i = 0; i < n; i++)
		cout << s[i] << "\n";
	return 0;
}