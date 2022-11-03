#include <bits/stdc++.h>
                     
using namespace std;

typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double

int n;
int a[22];
ll k;

const ll MAXVAL = (ll)2e18;

ll mult(ll a, ll b){
	ll can = MAXVAL / a;
	if (b > can) return -1;
	return a * b;
}

vector<ll> build(vector<ll> a){
	vector<ll> ans;
	ans.pub(1);
	for (int i = 0; i < a.size(); i++){
		int sz = ans.size();
		for (int j = 0; j < sz; j++){
			ll val = ans[j];
			while(1){
				ll gg = mult(val, a[i]);
				if (gg == -1) break;
				ans.pub(gg);
				val = gg;
			}
		}
	}
	return ans;
}

vector<ll> d1, d2;

ll calc(ll val){
	ll ans = 0;

	int uk = (int)d2.size() - 1;

	for (int i = 0; i < d1.size(); i++){
		while(uk >= 0){
			ll now = mult(d1[i], d2[uk]);
			if (now == -1 || now > val) uk--;
			else break;
		}
		ans += uk + 1;
	}

	return ans;
}

int main(){
   // freopen("input.txt", "r", stdin);
    //freopen("output2.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

	vector<ll> w1, w2;
	for (int i = 0; i < n; i++){
		if (i % 2 == 0) w1.pub(a[i]);
		else w2.pub(a[i]);
	}

   	cin >> k;
   	d1 = build(w1);
   	d2 = build(w2);
   	sort(all(d1));
   	sort(all(d2));

   	ll vl = 0, vr = 1e18 + 7;
   	while(vl + 1 < vr){
   		ll vm = (vl + vr) >> 1;
   		if (calc(vm) >= k)
   			vr = vm;
   		else
   			vl = vm;
   	}
   	cout << vr;
}