/*input
5
-1 2
2 3
4 1
3 -2
0 -3
5
1 0
1 1
3 1
5 -1
2 -1
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
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 
#define INF 0x3f3f3f3f

int n , m;
vector<PII> x , y , v , fr , ba;
PII STR(PII a , PII b){
	return mp(b.A - a.A , b.B - a.B);
}
int cross(PII a , PII b , PII c){
	PII s = STR(a , b);
	PII t = STR(a , c);
	return s.A * t.B - s.B * t.A;
}
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1){
		int a , b;
		cin >> a >> b;
		x.pb(mp(a , b));
		v.pb(mp(a , b));
	}
	cin >> m;
	REP(i , 1 , m + 1){
		int a , b;
		cin >> a >> b;
		y.pb(mp(a , b));
		v.pb(mp(a , b));
	}
	sort(ALL(v));

	for(auto to : v){
		while(fr.size() >= 2 && cross(fr[fr.size() - 2] , fr[fr.size() - 1] , to) < 0)
			fr.pop_back();
		fr.pb(to);
	}
	reverse(ALL(v));
	for(auto to : v){
		while(ba.size() >= 2 && cross(ba[ba.size() - 2] , ba[ba.size() - 1] , to) < 0)
			ba.pop_back();
		ba.pb(to);
	}
	set<PII> cc;
	for(auto to : fr) cc.insert(to);
	for(auto to : ba) cc.insert(to);
	for(auto to : y) if(cc.find(to) != cc.end()) return cout << "NO" << endl , 0;
	cout << "YES" << endl;
    return 0;
}