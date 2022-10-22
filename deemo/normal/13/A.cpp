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

int get(int a, int b){
	int z = b;
	while (z <= a)
		z *= b;
	int ret = 0;
	while (z){
		ret += a / z;
		a %= z;
		if (z == 1)	z = 0;
		else	z /= b;
	}
	return	ret;
}

int main(){
	int n;
	cin >> n;
	int a = 0;
	for (int i = 2; i < n; i++){
		int t = get(n, i);
		a += t;
	}
	n -= 2;
	int z = __gcd(a, n);
	a /= z;
	n /= z;
	cout << a << "/" << n << endl;
    return 0;
}