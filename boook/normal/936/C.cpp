/*input
6
abacbb
babcba
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 6600
#define INF 0x3f3f3f3f

int n;
string a , b;
void check(string a , string b){
	sort(ALL(a));
	sort(ALL(b));
	if(a != b){
		cout << -1 << endl;
		exit(0);
	}
}
vector<int> ans , x;
vector<int> v[MAX];
void solve(int to){
	string vv1 = a.substr(0 , n - to);
	string vv2 = a.substr(n - to , a.size());
	reverse(ALL(vv2));
	a = vv2 + vv1;

	vector<int> v1 , v2;
	REP(i , 0 , x.size()){
		if(i < n - to) v1.pb(x[i]);
		else v2.pb(x[i]);
	}
	reverse(ALL(v2)) , x.clear();
	for(auto to : v2) x.pb(to);
	for(auto to : v1) x.pb(to);
	ans.pb(to);
}
int32_t main(){
	IOS;
	cin >> n >> a >> b;
	check(a , b);

	REP(i , 0 , b.size()) v[b[i] - 'a'].pb(i);
	REP(i , 0 , a.size()){
		x.pb(v[a[i] - 'a'].back());
		v[a[i] - 'a'].pop_back();
	}
	// for(auto to : x) cout << to << " " ; cout << endl;

	// REP(i , 0 , x.size()) a[i] = x[i] + '0';
	// cout << a << endl;
	RREP(i , n - 1 , 0){
		int idx = -1;
		REP(j , 0 , x.size()) if(x[j] == i) idx = j;
		// DBGG("idx = " , idx);
		if(idx != 0){
			solve(n - 0);
			idx = n - idx;
			solve(n - idx);
			solve(n - (n - 1));
			// cout << a << endl;
		}
	}
	// cout << a << endl;
	// // for(auto to : ans){
		
	// // 	cout << "to = " << to << endl;
	// // 	cout << a << endl;
	// // }
	// cout << a << endl;
	// cout << b << endl;
	cout << ans.size() << endl;
	for(auto to : ans) cout << to << " "; cout << endl;
    return 0;
}