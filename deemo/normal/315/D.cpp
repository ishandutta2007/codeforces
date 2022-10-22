#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const ll MAX = 200;
const ll INF = 1e18;
const ll LOG = 45;

ll b, d;
string a, c;
ll nxt[MAX][30];
ll f[LOG][MAX], g[LOG][MAX];
bool mark[MAX];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> b >> d;
	cin >> a >> c;

	for (ll i = 0; i < a.size(); i++)
		for (ll j = 0; j < 26; j++){
			ll z = i, cnt = 0;
			while (cnt < a.size() && a[z] - 'a' != j)	cnt++, z = (z + 1) % (ll)a.size();
			if (a[z] - 'a' != j)	z = -1;
			if (z == -1)
				nxt[i][j] = -1;
			else
				nxt[i][j] = (z + 1) % (int)a.size();
		}
	
	
	ll cur, last;
	for (ll i = 0; i < (ll)a.size(); i++){
		cur = i;
		ll cnt = 0;
		for (ll j = 0; j < (ll)c.size(); j++){
			ll z = cur;
			z = nxt[z][c[j] - 'a'];
			if (z == -1){
				cnt = -1;
				break;
			}
			if (cur >= z)	cnt += (z + a.size() - cur);
			else	cnt += z - cur;
			cur = z;
		}	
		g[0][i] = cnt;
	}
	
	for (ll i = 1; i < LOG; i++)
		for (ll j = 0; j < a.size(); j++)
			if (g[i - 1][j] == -1 || g[i - 1][(j + g[i - 1][j]) % (ll)a.size()] == -1)
				g[i][j] = -1;
			else g[i][j] = g[i - 1][j] + g[i - 1][(j + g[i - 1][j]) % (ll)a.size()];

	ll k = 0;
	cur = 0;
	ll ans = 0;
	for (ll i = LOG - 1; i >= 0; i--){
		if (g[i][cur] == -1 || k + g[i][cur] > b * (ll)a.size())	continue;
		ans += (ll(1LL) << ll(i));
		k += g[i][cur];
		cur = (cur + g[i][cur]) % (ll)a.size();
	}
	cout << ans / d << endl;
	return 0;
}