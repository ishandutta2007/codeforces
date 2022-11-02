/*input
2
1 3
1 3
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
#define MAX 1000
#define INF 0x3f3f3f3f

int n , x[MAX][2] , sol[MAX] , ans[MAX];
int cmp(int a , int b){
	return x[a][1] < x[b][1];
}
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i][0] >> x[i][1];
	REP(i , 1 , n + 1) sol[i] = i;
	sort(sol + 1 , sol + 1 + n , cmp);
	set<int> cc;
	REP(idx , 1 , n + 1){
		int i = sol[idx];
		REP(j , x[i][0] , x[i][1] + 1){
			if(cc.count(j)) continue;
			else {
				cc.insert(j);
				ans[i] = j;
				break;
			}
		}
	}
	REP(i , 1 , n + 1) cout << ans[i] << " ";cout << endl;
    return 0;
}