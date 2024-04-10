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

const ll MAXK = 13;
const ll max_n = 1e5 + 100;

ll n, k;
ll a[max_n];
ll fen[MAXK][max_n];

ll get(ll t, ll x){
	ll ret = 0;
	for (; x; x -= x & (-x))
		ret += fen[t][x];
	return	ret;
}	

void add(ll t, ll x, ll val){
	for (x++; x < max_n; x += x & (-x))
		fen[t][x] += val;
}

int main(){
	read_fast;
	cin >> n >> k;	k++;
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	add(1, a[0], 1);
	for (ll i = 1; i < n; i++){
		ll x = a[i];
		add(1, x, 1);
		for (ll j = 1; j < k; j++){
			ll y = get(j, x);
			add(j + 1, x, y);
		}
	}
	cout << get(k, max_n) << endl;
    return 0;
}