/*input
5 1 1 1 1 1
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
#define MAX 2000
#define INF 0x3f3f3f3f

int n , x[MAX] , b[MAX];
set<PII> cc , dd;
int32_t main(){
	IOS;
	cin >> n;
	int sum = 0 , big = -INF , sml = 0;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) sum += x[i];
	REP(i , 1 , n + 1){
		if(i % 2 == 1) b[i] = b[i - 1] + x[i];
		if(i % 2 == 0) b[i] = b[i - 1] - x[i];
	}
	int now = 1 , hei = 0;
	REP(i , 1 , n + 1){
		if(i % 2 == 1){
			REP(j , 0 , x[i]){
				big = max(big , hei);
				sml = min(sml , hei);
				cc.insert(mp(now ++ , hei ++));
			}
		}
		else {
			REP(j , 0 , x[i]){
				dd.insert(mp(now ++ , -- hei));
				big = max(big , hei);
				sml = min(sml , hei);
			}
		}
	}
	RREP(i , big , sml){
		REP(j , 1 , sum + 1){
			if(cc.find(mp(j , i)) != cc.end()) cout << "/" ;
			else if(dd.find(mp(j , i)) != dd.end()) cout << "\\" ;
			else cout << " ";
		}
		cout << endl;
	}
    return 0;
}