/*input
5 2
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
#define INF 0x3f3f3f3f
#define mod 1000000009LL

int n , k , dp[2][35][35][35][2];
void ADD(int &val , int add){
	val = val + add;
	if(val >= mod) val -= mod;
}
void update(int now , int a , int b , int c , int d , int val){
	int x[] = {a , b , c , d};
	sort(x , x + 4);
	ADD(dp[now][x[3]][x[2]][x[1]][x[0]] , val);
}
int32_t main(){
	IOS;
	cin >> n >> k;
	dp[1][1][1][1][1] = 1; // 1 haven't been put
	REP(i , 1 , n + 1){
		int now = (i + 0) % 2 , nxt = now ^ 1;

		REP(a , 0 , k + 1) REP(b , 0 , k + 1) REP(c , 0 , k + 1) REP(d , 0 , 2)
			dp[nxt][a][b][c][d] = 0;

		REP(a , 0 , k + 1){
			REP(b , 0 , a + 1){
				REP(c , 0 , b + 1){
					REP(d , 0 , min(1LL , c) + 1){
						// printf("dp[%lld][%lld][%lld][%lld][%lld] = %lld\n"
						// 	, i , a , b , c , d , dp[now][a][b][c][d]);
						// puta
						int aa = (a == 0) ? 0 : (a == k ? 0 : a + 1);
						int bb = (b == 0) ? 0 : (b == k ? 0 : b + 1);
						int cc = (c == 0) ? 0 : (c == k ? 0 : c + 1);
						int dd = (d == 0) ? 0 : (d == k ? 0 : d + 1);
						// DB4(aa , bb , cc , dd);
						update(nxt , a > 0 , bb , cc , dd , dp[now][a][b][c][d]);
						update(nxt , aa , b > 0 , cc , dd , dp[now][a][b][c][d]);
						update(nxt , aa , bb , c > 0 , dd , dp[now][a][b][c][d]);
						update(nxt , aa , bb , cc , d > 0 , dp[now][a][b][c][d]);
					}
				}
			}
		}
	}
	int ans = 0 , pat = (n + 1) % 2;
	REP(a , 0 , k + 1) REP(b , 0 , a + 1) REP(c , 0 , b + 1) REP(d , 0 , min(1LL , c) + 1){
		if(a || b || c || d) ADD(ans , dp[pat][a][b][c][d]);
	}
	cout << ans << endl;
    return 0;
}