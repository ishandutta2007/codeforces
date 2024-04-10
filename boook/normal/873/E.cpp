/*input
6
7 7 7 7 6 7
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
#define MAX 3030
#define INF 0x3f3f3f3f
typedef pair<int , PII> PIII;
typedef pair<PIII , PIII> ANS;

int n , ans[MAX];
PII x[MAX] , big[MAX][MAX] , v[MAX];
PIII GET(int a , int b , int c){
	return mp(a , mp(b , c));
}
int32_t main(){
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i].A , x[i].B = i;
	sort(x + 1 , x + 1 + n , greater<PII>());

	REP(i , 1 , n + 1) v[i] = mp(x[i].A - x[i + 1].A , i);

	REP(i , 1 , n + 1){
		big[i][i] = v[i];
		REP(j , i + 1 , n + 1){
			big[i][j] = max(big[i][j - 1] , v[j]);
		}
	}
	ANS vvv = mp(GET(-INF , -INF , -INF) , GET(-INF , -INF , -INF));
	REP(i , 1 , n + 0){
		REP(j , i + 1 , n + 0){
			int fr = i , ba = j - i;
			if(fr * 2 < ba || ba * 2 < fr) continue;
			int h = min(fr * 2 , ba * 2);
			int d = max((fr + 1) / 2 , (ba + 1) / 2);
			int l = j + d , r = min(n , j + h);
			if(d > h || l > r) continue;
			PII tmp = big[l][r];
			PIII val = GET(v[i].A , v[j].A , tmp.A);
			PIII id = GET(i , j , tmp.B);
			vvv = max(vvv , mp(val , id));
		}
	}
	PIII tmp = vvv.B;
	int aa = tmp.A , bb = tmp.B.A , cc = tmp.B.B;
	// DB4(aa , bb , cc , "-1");
	REP(i ,      1 , aa + 1) ans[x[i].B] = 1;
	REP(i , aa + 1 , bb + 1) ans[x[i].B] = 2;
	REP(i , bb + 1 , cc + 1) ans[x[i].B] = 3;
	REP(i , cc + 1 ,  n + 1) ans[x[i].B] = -1;
	REP(i , 1 , n + 1) cout << ans[i] << " " ;cout << endl;
    return 0;
}