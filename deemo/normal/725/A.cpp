#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;	cin >> n;
	string s;	cin >> s;
	int ans = 0;
	int i = 0;
	while(i < n && s[i] == '<')	ans++, i++;
	i = n - 1;
	while (~i && s[i] == '>')	ans++, i--;
	cout << ans << endl;
	return 0;
}