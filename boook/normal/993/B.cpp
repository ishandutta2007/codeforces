/*input
8 1
1 6 7 6 7 3 9 2 1 2 8 6 2 3 4 1
8 3
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
#define MAX 20
#define INF 0x3f3f3f3f

int n , m , a[MAX][2] , b[MAX][2];
set<int> ans;
int SIZ(int i , int j){
	set<int> cc;
	cc.insert(a[i][0]);
	cc.insert(a[i][1]);
	cc.insert(b[j][0]);
	cc.insert(b[j][1]);
	return cc.size();
}
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , n + 1) cin >> a[i][0] >> a[i][1];
	REP(i , 1 , n + 1) if(a[i][0] > a[i][1]) swap(a[i][0] , a[i][1]);

	REP(i , 1 , m + 1) cin >> b[i][0] >> b[i][1];
	REP(i , 1 , m + 1) if(b[i][0] > b[i][1]) swap(b[i][0] , b[i][1]);
	REP(i , 1 , n + 1){
		set<int> ok;
		REP(j , 1 , m + 1){
			int siz = SIZ(i , j);
			if(siz == 3){
				REP(ii , 0 , 2) REP(jj , 0 , 2) if(a[i][ii] == b[j][jj]) ok.insert(a[i][ii]);
			}
		}
		if(ok.size() > 1) return cout << -1 << endl , 0;
		else if(ok.size() == 1) ans.insert(*ok.begin());
	}
	REP(j , 1 , m + 1){
		set<int> ok;
		REP(i , 1 , n + 1){
			int siz = SIZ(i , j);
			if(siz == 3){
				REP(ii , 0 , 2) REP(jj , 0 , 2) if(a[i][ii] == b[j][jj]) ok.insert(a[i][ii]);
			}
		}
		if(ok.size() > 1) return cout << -1 << endl , 0;
		else if(ok.size() == 1) ans.insert(*ok.begin());
	}
	if(ans.size() == 1) cout << *ans.begin() << endl;
	else if(ans.size()) cout << 0 << endl;
	else cout << -1 << endl;
    return 0;
}