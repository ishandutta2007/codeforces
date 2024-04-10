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

ll get(ll r){
	if (r == 0)	return	0;

	ll ans = 0;
	for (ll i = 1; i <= 62; i++){
		ll temp = (ll(1) << ll(i)) - 1;
		for (ll j = 0; j < i - 1; j++){
			ll z = temp ^ (ll(1) << ll(j));
			if (z <= r)	ans++;
		}
	}
	return	ans;
}

int main(){
	ll l, r;	cin >> l >> r;
	cout << get(r) - get(l - 1) << endl;
	return 0;
}