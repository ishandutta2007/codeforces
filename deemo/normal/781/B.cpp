#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 10;

int n, ans[MAXN];
string s[MAXN], t[MAXN];
map<string, int> c1, c2;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		string a, b;	cin >> a >> b;
		s[i] = a.substr(0, 3);
		t[i] = a.substr(0, 2) + b[0];
		c1[s[i]]++;
	}

	for (int i = 0; i < n; i++){
		if (c1[s[i]] > 1){
			ans[i] = 1;
			c2[t[i]]++;
		}
		else c2[s[i]]++;
	}

	for (int i = 0; i <= n; i++){
		bool fl = 0;
		for (int j = 0; j < n; j++)
			if (ans[j]==0 && c2[s[j]] > 1){
				c2[s[j]]--;
				ans[j] = 1;
				c2[t[j]]++;
				fl = 1;
				break;
			}
		if (!fl) break;
	}

	for (auto &x:c2)
		if (x.second > 1){
			cout << "NO\n";
			return 0;
		}

	cout << "YES\n";
	for (int i = 0; i < n; i++)
		if (ans[i] == 0)
			cout << s[i] << "\n";
		else
			cout << t[i] << "\n";
	return 0;
}