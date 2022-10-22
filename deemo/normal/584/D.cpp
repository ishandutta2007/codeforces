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
//#define size(x) ((int)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define pb push_back
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)
#define PQ priority_queue;
#define to_string(x) ({ string _str; stringstream _ss; _ss << x;  _ss >> _str; _str; })
#define to_int(x) ({ int _x; stringstream _ss; _ss << x; _ss >> _x; _x; })

bool pr(ll x){
	for (ll i = 2; i * i <= x; i++)
		if (x % i == 0)	return	false;
	return	true;
}

int main(){
    int n;
	cin >> n;
	vector<int>	vec;
	
	if (pr(n)){
		cout << 1 << endl;
		cout << n << endl;
		return 0;
	}
	if (n == 4){
		cout << 2 << endl;
		cout << 2 << " " << 2 << endl;
		return 0;
	}
	
	vec.pb(3);
	n -= 3;

	for (int i = n - 2; i >= 0; i--){
		if (pr(i) && pr(n - i)){
			vec.pb(i);
			vec.pb(n - i);
			break;
		}
	}

	cout << vec.size() << endl;
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
	return 0;
}