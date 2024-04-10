#include<iostream>
#include<cstdio>
#include<cassert>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<utility>
#include<iomanip>
#include<fstream>
#include<list>
#include<sstream> 
#include<cstring>
#include<bitset>
#include<functional>
#include<numeric>

using namespace std;

typedef long long ll;
//#define size(x) ((ll)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define pb push_back
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)
#define PQ priority_queue;
#define to_string(x) ({ string _str; stringstream _ss; _ss << x;  _ss >> _str; _str; })
#define to_ll(x) ({ ll _x; stringstream _ss; _ss << x; _ss >> _x; _x; })

const ll MAXM = 2e6 + 10;
const ll MOD = 1e9 + 7;
const ll MM = MOD - 1;

ll m, vec[MAXM], cnt[MAXM];
ll ans = 1, save[MAXM], ss[MAXM];

ll pw(ll a, ll b){
	ll ret = 1;
	while (b){
		if (b & 1)
			ret = (ret * a) % MOD;
		b >>= 1;
		a = (a * a) % MOD;
	}	
	ret %= MOD;
	return	ret;
}

int main(){
	read_fast;
	cin >> m;
	for (ll i = 0; i < m; i++){
		cin >> vec[i];
		cnt[vec[i]]++;
	}
	sort(vec, vec + m);
	m = unique(vec, vec + m) - vec;

	ss[0] = 1;
	for (ll i = 0; i < m; i++)
		ss[i + 1] = (ss[i] * ll(cnt[vec[i]] + 1)) % MM;
	
	save[m] = 1;
	for (ll i = m - 1; i > 0; i--)
		save[i] = (save[i + 1] * ll(cnt[vec[i]] + 1)) % MM;
	
	for (ll i = 0; i < m; i++){
		ll sum = 1;
		for (ll j = 0; j < cnt[vec[i]]; j++){
			sum = (sum * vec[i]) % MOD;

			ll temp = (ss[i] * save[i + 1]) % MM;
			temp = pw(sum, temp);
			ans = (ans * temp) % MOD;
		}
	}
	cout << ans << endl;
    return 0;
}