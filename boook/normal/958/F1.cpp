/*input
5 2
1 1 2 2 1
1 2
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
#define MAX 200
#define INF 0x3f3f3f3f

int n , m , a[MAX] , b[MAX] , cnt[MAX];
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , n + 1) cin >> a[i];
	REP(i , 1 , m + 1) cin >> b[i];
	REP(l , 1 , n + 1){
		REP(r , l , n + 1){
			MEM(cnt , 0);
			int ok = 1;
			REP(ii , l , r + 1) cnt[a[ii]] ++;
			REP(ii , 1 , m + 1) if(b[ii] != cnt[ii]) ok = 0;
			if(ok) return cout << "YES" << endl , 0;
		}
	}
	cout << "NO" << endl;
    return 0;
}