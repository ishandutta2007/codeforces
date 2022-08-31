#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, m, q;
string s[25], t[25];

int main()
{
	cin >> n >> m;
	rep(i, n) cin >> s[i];
	rep(i, m) cin >> t[i];
	cin >> q;
	rep(i, q) {
		int ct;
		cin >> ct;
		ct --;
		cout << s[ct % n] << t[ct % m] << '\n';
	}
	return 0;
}