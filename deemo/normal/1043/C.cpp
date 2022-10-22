#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e3 + 10;

int n, par[MAXN][2], ans[MAXN];
string s;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s; n = s.size();
	memset(par, -1, sizeof(par));
	string cur = "";
	for (int i = 1; i <= n; i++){
		if (s[i-1] + cur < cur + s[i-1])
			ans[i] = 1, ans[i-1] ^= 1, cur = s[i-1] + cur;
		else
			cur += s[i-1];
	}

	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	cout << "\n";
	return 0;
}