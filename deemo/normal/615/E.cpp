#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cassert>
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

ll n;

int main(){	
	cin >> n;
	ll b = 0, e = 6e8, ret;
	while (b <= e){
		ll mid = (b + e)/ 2;
		if ((mid * (mid + 1)) * 3 <= n){
			ret = mid;
			b = mid + 1;
		}
		else	e = mid - 1;
	}
	n -= (ret * (ret + 1)) * 3;

	ll x = ret * 2, y = 0;
	if (n < 1){
		x += (n == 1);
		y += 2 * (n == 1);
		cout << x << " " << y << endl;
		return	0;
	}
	n -= 1;
	x++, y += 2;
	if (n < ret){
		x -= n;
		y += 2 * n;
		cout << x << " " << y << endl;
		return	0;
	}
	n -= ret;
	x -= ret, y += 2 * ret;
	if (n < (ret + 1)){
		x -= 2 * n;
		cout << x << " " << y << endl;
		return	0;
	}
	n -= (ret + 1);
	x -= 2 * (ret + 1);

	if (n < (ret + 1)){
		x -= n;
		y -= 2 * n;
		cout << x << " " << y << endl;
		return	0;
	}
	n -= (ret + 1);
	x -= (ret + 1);
	y -= 2 * (ret + 1);
	
	if (n < (ret + 1)){
		x += n;
		y -= 2 * n;
		cout << x << " " << y << endl;
		return	0;
	}
	n -= (ret + 1);
	x += (ret + 1), y -= 2 * (ret + 1);

	if (n < (ret + 1)){
		x += 2 * n;
		cout << x << " " << y << endl;
		return	0;
	}
	n -= (ret + 1);
	x += 2 * (ret + 1);

	if (n < (ret + 1)){
		x += n;
		y += 2 * n;
		cout << x << " " << y << endl;
		return	0;
	}
	assert(0);
    return 0;
}