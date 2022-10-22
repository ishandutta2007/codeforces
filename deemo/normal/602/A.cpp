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
	read_fast;
	ll n, x, a = 0;	cin >> n >> x;
	ll t = 1;
	vector<ll>	vec(n);
	for (ll i = 0; i < n; i++)
		cin >> vec[i];
	reverse(vec.begin(), vec.end());
	for (ll i = 0; i < n; i++){
		a += vec[i] * t;
		t *= x;
	}

	ll m, y, b = 0;	cin >> m >> y;
	vec.resize(m);
	t = 1;
	for (ll i = 0; i < m; i++)
		cin >> vec[i];
	reverse(vec.begin(), vec.end());
	for (ll i = 0; i < m; i++){
		b += vec[i] * t;
		t *= y;
	}
	if (a < b)	cout << "<" << endl;
	else if (a > b)	cout << ">" << endl;
	else	cout << "=" << endl;
    return 0;
}