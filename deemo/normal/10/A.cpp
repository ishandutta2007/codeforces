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

int main(){
	read_fast;
	int n, p1, p2, p3, t1, t2;
	cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
	vector<pair<int, int>>	vec(n);

	ll ans = 0;
	for (int i = 0; i < n; i++){
		cin >> vec[i].first >> vec[i].second;
		ans += (vec[i].second - vec[i].first) * p1;
	}
	
	for (int i = 1; i < n; i++){
		int t = vec[i].first - vec[i - 1].second;
		ans += min(t1, t) * p1;
		t = max(0, t - t1);
		ans += min(t2, t) *  p2;
		t = max(0, t - t2);
		ans += t * p3;
	}
	cout << ans << endl;
	return 0;
}