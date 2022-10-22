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
typedef long double ld;
//#define size(x) ((int)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define pb push_back
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)
#define PQ priority_queue;
#define to_string(x) ({ string _str; stringstream _ss; _ss << x;  _ss >> _str; _str; })
#define to_int(x) ({ int _x; stringstream _ss; _ss << x; _ss >> _x; _x; })

ll n, a, b, x, ans;
bool flag;

void get(){
	ll g = __gcd(a, b);
	ll ta = a, tb = b;
	ta /= g;
	if (n/ta < tb)	flag = 1;
	x = ta * tb;
}

int main(){
	cin >> n >> a >> b;
	if (a == b){
		cout << "1/1" << endl;
		return 0;
	}	
	get();
	if (flag){
		ans = min(a, b) - 1;
		ans = min(ans, n);
		if (ans == 0){
			cout << "0/1" << endl;
			return 0;
		}
		x = __gcd(ans, n);
		ans /= x;
		n /= x;
		cout << ans << "/" << n << endl;
		return 0;
	}
	ans += n / x;
	ll y = n/ x;
	ans += y * min(a-1, b-1);

	ll t = n % x;
	ans += min(t, min(a, b) - 1);
	if (ans == 0){
		cout << "0/1" << endl;
		return 0;
	}
	x = __gcd(ans, n);
	ans /= x;
	n /= x;
	cout << ans << "/" << n << endl;
    return 0;
}