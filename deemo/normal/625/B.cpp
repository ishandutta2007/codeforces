#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e5 + 20;

int n, m, f[MAXN];
string s, t;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> t;	
	n = (int)s.size(), m = (int)t.size();
	
	int k = 0, ans = 0;
	for (int i = 1; i < m; i++){
		while (k && t[i] != t[k])	k = f[k];
		if (t[i] == t[k])	k++;
		f[i + 1] = k;
	}
	k = 0;
	for (int i = 0; i < n; i++){
		while (k && s[i] != t[k])	k = f[k];
		if (s[i] == t[k])	k++;
		if (k == m){
			ans++;
			k = 0;
		}
	}
	cout << ans << "\n";
	return	0;
}