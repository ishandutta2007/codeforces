#include<iostream>
#include<cstdio>
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

const ll MOD = 1e9 + 7;
const ll max_n = 1e5 + 10;

ll n, k, z;
ll cnt[max_n];
ll vec[max_n], sec[max_n];
ll ans = 1;

ll get(ll x, ll ind){
	ll a = vec[ind], b = sec[ind];
	ll ret = ((z - 1) / a) + 1;
	if (x == 1)	
		return ret - ll(b % a == 0);

	b *= (z / 10);
	ll t = b % a;
	t = (a - t) % a;
	if (z/10 - 1 - t < 0)	return	ret;
	ret -= (z/10 - 1 - t) / a + 1;
	return	ret;
}

int main(){
	read_fast;
	cin >> n >> k;
	for (ll i = 0; i < n/k; i++)
		cin >> vec[i];
	for (ll i = 0; i < n/k; i++)
		cin >> sec[i];

	z = 1;
	for (ll i = 0; i < k; i++)
		z *= 10;

	for (ll j = 0; j < n/k; j++)
		cnt[j] = get(k, j);

	for (ll i = 0; i < n/k; i++)
		ans = (ans * cnt[i]) % MOD;
	cout << ans << endl;
    return 0;
}