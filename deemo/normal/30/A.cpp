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

int main(){
	ll a, b, n;
	cin >> a >> b >> n;
	if (b == 0){
		cout << 0 << endl;
		return 0;
	}
	for (ll i = -1000; i <= 1000; i++){
		ll t = 1, fl = 0;
		for (ll j = 0; j < n; j++, t *= i){
			if (abs(a * t) > abs(b)){
				fl = 1;
				break;
			}
		}
		if (fl)	continue;
		if (a * t == b){
			cout << i << endl;
			return 0;
		}
	}
	cout << "No solution" << endl;
    return 0;
}