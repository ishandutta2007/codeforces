#include <bits/stdc++.h>
          
using namespace std;
          
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

struct vert{
	int to[2], pred;
	int cnt;
	vert() { to[0] = to[1] = -1; cnt = 0; pred = -1; }
};

int n;
ll a[100007];

vert d[100007 * 61];
int sz = 1;

void add(ll x){
	int v = 0;
	for (int i = 59; i >= 0; i--){
		int now = ((x >> i) & 1);
		d[v].cnt++;
		if (d[v].to[now] == -1) d[sz].pred = v, d[v].to[now] = sz++;
		v = d[v].to[now];
	}
	d[v].cnt++;
}

ll solve(ll x){
	for (int i = 0; i <= 59; i++) if ((x >> i) & 1){
		int v = 0;
		int pos = 60;
		int ok = 1;
		while(pos - 1 > i){
			if (d[v].to[0] == -1){
				ok = 0;
				break;
			}
			v = d[v].to[0];
			pos--;
		}
		if (!ok) continue;
		if (d[v].to[1] == -1) continue;
		v = d[v].to[1];
		if (d[v].cnt == 0) continue;
		ll ans = (ll)1 << i;
		for (int j = i - 1; j >= 0; j--){
			int b = ((x >> j) & 1);
			if (d[v].to[b ^ 1] == -1 || d[d[v].to[b ^ 1]].cnt == 0){
				if (b == 1) ans ^= (ll)1 << j;
				v = d[v].to[b];
			} else {
				if (b == 0) ans ^= (ll)1 << j;
				v = d[v].to[b ^ 1];
			}
		}
		//cout << i << ' ' << x << ' ' << ans << endl;
		while(1){
			d[v].cnt--;
			if (d[v].pred == -1) break;
			v = d[v].pred;
		}
		return ans;
	}
	cout << "No\n";
	exit(0);
}

int main(){
   // freopen("input.txt", "r", stdin);
    //freopen("output2.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> t;
	
	ll now = 0;
	for (int i = 0; i < n; i++) now ^= a[i];

	for (int i = 0; i < n; i++) add(a[i]);

	for (int it = 0; it < n; it++){
		ll gg = solve(now);
		t.pb(gg);
		now ^= gg;	
		//cout << gg << ' ' << now << endl;
		//exit(0);
		//if (gg == 20) exit(0);
	}

	cout << "Yes\n";
	reverse(all(t));
	for (ll x : t) cout << x << ' ';
}