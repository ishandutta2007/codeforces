//It doesn't matter who's right or wrong

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
const ll max_n = 1e6 + 20;

ll n, l, k, maxi;
map<ll, ll>	mp, cnt;
map<pair<ll, ll>, ll>	dp;
vector<ll>	vec, sec;

void init(){
	for (ll i = 1; i <= k; i++)
		for (ll j = 0; j < sec.size(); j++){
			if (i == 1){
				dp[{i, sec[j]}] = cnt[sec[j]];
				if (j != 0)	dp[{i, sec[j]}] = (dp[{i, sec[j]}] + dp[{i, sec[j - 1]}]) % MOD;
				continue;
			}
			else{
				if (j == 0)	dp[{i, sec[j]}] = (cnt[sec[0]] * dp[{i - 1, sec[j]}]) % MOD;	
				else dp[{i, sec[j]}] = (cnt[sec[j]] * dp[{i - 1, sec[j]}] + dp[{i, sec[j - 1]}]) % MOD;
			}
		}
}

ll cal(ll v){
	if (l < (v - 1) * n)	return	0;
	l -= (v - 1) * n;
	ll z = l / n;
	z %= MOD;
	ll ret = (z * dp[{v, maxi}]) % MOD;
	for (ll i = 0; i < l % n; i++)
		if (v != 1)	ret = (ret + dp[{v - 1, vec[i]}]) % MOD;
		else	ret = (ret + 1) % MOD;
	return	ret;
}

int main(){
    scanf("%I64d%I64d%I64d", &n, &l, &k);
	vec.resize(n);
	for (ll i = 0; i < n; i++){
		scanf("%I64d", &vec[i]);
		cnt[vec[i]]++;
		maxi = max(maxi, vec[i]);
	}
	sec.assign(vec.begin(), vec.end());
	sort(sec.begin(), sec.end());	
	sec.resize(unique(sec.begin(), sec.end()) - sec.begin());
	init();

	ll ans = 0;
	ll secl = l;
	for (ll i = 1; i <= k; i++){
		l = secl;
		ans = (ans + cal(i)) % MOD;
	}
	printf("%I64d\n", ans);
	return 0;
}