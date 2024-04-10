#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, p[10005];
bool vis[10005];
int query(int x)
{
	int ret;
	cout << '?' << ' ' << x << endl;
	cin >> ret;
	return ret;
}
void solve()
{
	cin >> n;
	rep1(i, n) vis[i] = false;
	
	rep1(i, n) if(!vis[i]) {
		int x, y;
		do x = query(i);
		while(x != i);
		do {
			y = query(i);
			p[x] = y; vis[x] = true;
			x = y;
		} while(x != i);
	}
	
	cout << '!'; rep1(i, n) cout << ' ' << p[i]; cout << endl;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	
	int T;
	cin >> T;
	while(T --) solve();
	return 0;
}