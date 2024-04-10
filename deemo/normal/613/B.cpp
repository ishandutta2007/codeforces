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

const ll MAXN = 1e5 + 10;

ll n, A, c1, c2, k;
pair<ll, ll> vec[MAXN];
ll sec[MAXN], par[MAXN];

int main(){
	read_fast;
	cin >> n >> A >> c1 >> c2 >> k;
	for (ll i = 0; i < n; i++){
		cin >> vec[i].first;
		vec[i].second = i;
	}
	sort(vec, vec + n);
	for (ll i = 0; i < n; i++)
		par[i + 1] = par[i] + vec[i].first;

	ll ind = -1, rr = -1, rt = -1;
	ll ans = -1;
	ll p = 0;
	for (ll i = n; i >= 0; i--){
		if (p > k)	break;
		if (i == 0){
			if (ans < n * c1 + A * c2){
				ans = n * c1 + A * c2;
				ind = 0;
				rr = rt = 0;
			}
			break;
		}
		
		ll b = vec[0].first, e = A, ret, cc;
		while (b <= e){
			ll mid = (b + e)/ 2;
			ll pos = lower_bound(vec, vec + i, make_pair(mid, (ll)1e9)) - vec;
			if (pos * mid - par[pos] + p > k)	
				e = mid - 1;
			else{
				b = mid + 1;
				ret = mid;
				cc = pos;
			}
		}
		if (ans < (n - i) * c1 + ret * c2){
			ans = (n - i) * c1 + ret * c2;
			ind = i;
			rr = cc;
			rt = ret;
		}
		
		p += A - vec[i - 1].first;
	}
	cout << ans << "\n";
	for (ll i = ind; i < n; i++)	vec[i].first = A;
	for (ll i = 0; i < rr; i++)	vec[i].first = rt;
	for (ll i = 0; i < n; i++)
		sec[vec[i].second] = vec[i].first;
	for (ll i = 0; i < n; i++)
		cout << sec[i] << " ";
	cout << "\n";
    return 0;
}