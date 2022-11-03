#include <bits/stdc++.h>
  
using namespace std;
  
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n;
pair<ll, ll> a[200007];
ll cnt[200007];

ll gcd(ll a, ll b){
	while(b){
		a %= b;
		swap(a, b);
	}
	return a;
}

ll gg[200007];

vector<vector<ll> > t;

vector<int> mod = {1000066153,1000025129,1000074059,1000156673,1000049989,1000009573,1000014761,1000077497,1000003577,1000164709,1000080127,1000089919,1000007479,1000128629,1000186501,1000069099,1000029619,1000180079,1000104887,1000162081};

bool check(ll x1, ll y1, ll x2, ll y2){
	for (int i = 0; i < 5; i++){
		ll xx1 = x1 % mod[i];
		ll xx2 = x2 % mod[i];
		ll yy1 = y1 % mod[i];
		ll yy2 = y2 % mod[i];
		if (xx1 * (ll)yy2 % mod[i] != xx2 * (ll)yy1 % mod[i]) return 0; 
	}
	return 1;
}

int main(){
   // freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
   	cin >> n;
   	set<ll> xx, yy;
   	for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y >> cnt[i];
   	set<pair<ll, ll> > se;
   	for (int i = 0; i < n; i++){
   		xx.insert(a[i].x);
   		yy.insert(a[i].y);
   		se.insert(a[i]);
   	}
   	if ((ll)xx.size() * (ll)yy.size() != n) cout << 0, exit(0);
   	for (ll x : xx) for (ll y : yy) if (se.find(mp(x, y)) == se.end()) cout << 0, exit(0);
   	if (xx.size() > yy.size()){
   		for (int i = 0; i < n; i++) swap(a[i].x, a[i].y);
   		swap(xx, yy);
   	}
   	vector<ll> fy, fx;
   	for (ll y : yy) fy.pb(y);
   	for (ll x : xx) fx.pb(x);
   	t.resize(xx.size());
   	for (int i = 0; i < xx.size(); i++) t[i].resize(yy.size());
   	for (int i = 0; i < n; i++){
   		int posy = lower_bound(all(fy), a[i].y) - fy.begin();
   		int posx = lower_bound(all(fx), a[i].x) - fx.begin();
   		t[posx][posy] = cnt[i];
   	}


   	ll tmp = t[0][0];
   	for (int j = 0; j < yy.size(); j++) tmp = gcd(tmp, t[0][j]);

   	for (int j = 0; j < yy.size(); j++){
   		gg[j] = t[0][j];
   		for (int i = 0; i < xx.size(); i++) gg[j] = gcd(gg[j], t[i][j]);
   	}

   	for (int i = 1; i < xx.size(); i++){
   		for (int j = 1; j < yy.size(); j++){
   			if (!check(t[0][0], t[i][0], t[0][j], t[i][j])) cout << 0, exit(0);
   		}
   	}


   	int ans = 0;
   	for (ll i = 1; i * (ll)i <= tmp; i++) if (tmp % i == 0){
   		ll val = i;

   		int ok = 1;

   		for (int j = 0; j < yy.size(); j++){
   			ll now = t[0][j] / val;
   			if (gg[j] % now != 0){
   				ok = 0;
   				break;
   			}
   		}

   		ans += ok;

   		if (i * (ll)i != tmp){
   			val = tmp / i;
   			int ok = 1;

	   		for (int j = 0; j < yy.size(); j++){
	   			ll now = t[0][j] / val;
	   			if (gg[j] % now != 0){
	   				ok = 0;
	   				break;
	   			}
	   		}

	   		ans += ok;
   		}
   	}
   	cout << ans;
}