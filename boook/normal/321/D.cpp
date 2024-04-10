/*input
5
-2 0 0 0 -2
0 -2 0 -2 0
0 0 -2 0 0
0 -2 0 -2 0
-2 0 0 0 -2
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
#define MAX 50
#define INF 0x3f3f3f3f

int n , N , x[MAX][MAX] , f[MAX][MAX];
int query(int i , int j){ return x[i][j] * (f[i][j] * -2 + 1); }
int update(int i , int j){
	if(i > N) return f[i][j] = f[i - N][j] ^ f[N][j];
	if(j > N) return f[i][j] = f[i][j - N] ^ f[i][N];
}
int32_t main(){
	IOS;
	cin >> n , N = n / 2 + 1;
	REP(i , 1 , n + 1) REP(j , 1 , n + 1) cin >> x[i][j];
	if(n == 1) return cout << abs(x[1][1]) << endl , 0;
	int ans = -INF;
	REP(times , 0 , (1 << N)){
		int pat = times << 1 , sum = 0;
		
		REP(j , 1 , N + 1) f[N][j] = (pat & (1 << j)) != 0;
		REP(j , 1 , N + 0) f[N][N + j] = f[N][j] ^ f[N][N];
		REP(j , 1 , n + 1) sum += query(N , j);

		REP(i , 1 , N){
			int v[2] = {0 , 0};
			for(f[i][N] = 0 ; f[i][N] < 2 ; f[i][N] ++){
				update(i + N , N);
				v[f[i][N]] += query(i , N) + query(i + N , N);
				REP(j , 1 , N){
					f[i][j] = 0;
					update(i + N , j) , update(i , j + N) , update(i + N , j + N);
					int v1 = query(i , j) + query(i + N , j) 
						   + query(i , j + N) + query(i + N , j + N);
					f[i][j] = 1;
					update(i + N , j) , update(i , j + N) , update(i + N , j + N);
					int v2 = query(i , j) + query(i + N , j) 
						   + query(i , j + N) + query(i + N , j + N);
					v[f[i][N]] += max(v1 , v2);
				}
			}
			sum += max(v[0] , v[1]);
		}
		ans = max(ans , sum);
	}
	cout << ans << endl;
    return 0;
}