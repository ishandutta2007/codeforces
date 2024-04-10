/*input
9 12 2 3
1 2
2 3
1 3
1 4
2 5
4 5
4 6
6 5
6 7
7 5
8 7
9 1
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
#define MAX 200000
#define INF 0x3f3f3f3f

int n , m , s , t , e[MAX][2] , cnt[MAX];
vector<int> v[MAX];
int32_t main(){
	IOS , cin >> n >> m >> s >> t;
	REP(i , 0 , m){
		int a , b;
		cin >> a >> b;
		e[i][0] = a , e[i][1] = b;
		v[a].pb(b);
		v[b].pb(a);
	}
	REP(i , 0 , m + m){
		int a = e[i % m][0] , b = e[i % m][1];
		if(i > m) swap(a , b);

		if(v[a].size() - 1 < s) continue;
		if(v[b].size() - 1 < t) continue;
		int tmp = 0;
		for(auto to : v[a]) if(to != b) cnt[to] = 1;
		for(auto to : v[b]) if(to != a && cnt[to]) tmp ++ , cnt[to] = 2;
		if(v[a].size() + v[b].size() >= s + t + 2 + tmp){
			cout << "YES" << endl;
			cout << a << " " << b << endl;
			vector<int> ss , tt;
			for(auto to : v[a]) if(cnt[to] == 1 && s && to != b) s -- , ss.pb(to);
			for(auto to : v[b]) if(cnt[to] == 0 && t && to != a) t -- , tt.pb(to);
			for(auto to : v[a]) if(cnt[to] == 2){
				if(to == a || to == b) continue;
					 if(s) s -- , ss.pb(to);
				else if(t) t -- , tt.pb(to);
			}
			for(auto to : ss) cout << to << " "; cout << endl;
			for(auto to : tt) cout << to << " "; cout << endl;
			return 0;
		}
		else for(auto to : v[a]) cnt[to] = 0;
	}
	cout << "NO" << endl;
    return 0;
}