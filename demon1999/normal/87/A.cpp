#include <bits/stdc++.h>  
using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
#define prev previ
#define tm tmmm
#define div divv
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const ll mod = ll(1e9) + 7;
const int mak = 8, ma = 1024 * 128 * 2;
ll a, b, sm1, sm2;

vector<ll> q;
int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	cin >> a >> b;
	for (ll i = 1; i <= b; i++)
		q.push_back(i * a);
	for (ll i = 1; i <= a; i++)
		q.push_back(i * b);
	q.push_back(0);
	sort(q.begin(), q.end());
	for (int i = 1; i < sz(q); i++) {
		int tm = int(1e9);
		if (q[i] % a == 0 && q[i] % b == 0) {
			if (a > b)
				sm1 += q[i] - q[i - 1];
			else
				sm2 += q[i] - q[i - 1];
		} else {
			if (q[i] %a == 0) sm1 += q[i] - q[i - 1];
			else
				sm2 += q[i] - q[i - 1];
		}
	}
	if (sm1 < sm2) {
		cout << "Masha";
	} else
	if (sm1 > sm2)
		cout << "Dasha";
	else
		cout << "Equal";
	re 0;
}