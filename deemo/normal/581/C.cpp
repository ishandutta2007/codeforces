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

int n, k;
vector<int>	vec;

bool help(int a, int b){
	return a % 10 > b % 10;
}

int main(){
	read_fast;
	cin >> n >> k;
	vec.resize(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	sort(vec.begin(), vec.end(), help);
	for (int i = 0; i < n && k; i++){
		int t = min(k, (10 - vec[i] % 10) % 10);
		vec[i] += t;
		k -= t;
	}
	ll ans = 0;
	for (int i = 0; i < n && k; i++){
		int t = min(100 - vec[i], k);
		vec[i] += t;
		k -= t;
	}
	for (int i = 0; i < n; i++)
		ans += vec[i] / 10;
	cout << ans << endl;
    return 0;
}