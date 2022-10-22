#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;

int n;
string s;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s; n = s.size();
	int ans = 0, cur = 0;
	for (int i = n-1; ~i; i--)
		if (s[i] == 'a'){
			ans += cur;
			while (ans >= MOD) ans -= MOD;

			cur += cur;
			while (cur >= MOD) cur -= MOD;
		}
		else{
			cur++;
			while (cur >= MOD) cur -= MOD;
		}

	cout << ans << "\n";
	return 0;
}