/*input
3
4 5
1 2
9 20
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
#define int long long
#define MAX 300900
#define INF 0x3f3f3f3f

int n , x[MAX][2];
PII fr[MAX] , ba[MAX];
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i][0] >> x[i][1];
	fr[    0] = mp(-INF , INF);
	ba[n + 1] = mp(-INF , INF);
	REP(i , 1 , n + 1) fr[i] = mp(max(fr[i - 1].A , x[i][0]) , min(fr[i - 1].B , x[i][1]));
	RREP(i , n , 1)    ba[i] = mp(max(ba[i + 1].A , x[i][0]) , min(ba[i + 1].B , x[i][1]));
	int ans = 0;
	REP(i , 1 , n + 1){
		PII tmp = mp(max(fr[i - 1].A , ba[i + 1].A) , min(fr[i - 1].B , ba[i + 1].B));
		// DBGG(tmp.A , tmp.B);
		if(tmp.A <= tmp.B) ans = max(ans , tmp.B - tmp.A);
	}
	cout << ans << endl;
    return 0;
}