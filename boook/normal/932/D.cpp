/*input
6
1 1 1
2 2 0
2 2 1
1 3 0
2 2 0
2 2 2
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
#define MAX 400900
#define INF 0x3f3f3f3f

int n , sp[MAX][20] , vv[MAX][20] , po = 2;
int las = 0;
int32_t main(){
	IOS;
	cin >> n;

	REP(tiems , 1 , n + 1){
		int ty , a , b;
		cin >> ty >> a >> b;
		a = a ^ las , b = b ^ las;
		// cout << "ty = " << ty << " " ; DB4("real a = " , a , "b = " , b);
		if(ty == 1){
			int now = a;
			if(vv[now][0] >= b) sp[po][0] = now;
			else {
				RREP(i , 19 , 0){
					if(sp[now][i] != 0 && vv[ sp[now][i] ][0] < b) now = sp[now][i];
				} now = sp[now][0];
				// DB4("pos = " , po , "now = " , now);
				if(vv[now][0] >= b) sp[po][0] = now;
				else sp[po][0] = 0;
			}
			// DB4("now = " , po , "fa = " , sp[po][0]);
			vv[po][0] = b;
			REP(i , 1 , 20){
				int to = sp[po][i - 1];
				sp[po][i] = sp[to][i - 1];
				if(to != po){
					vv[po][i] = vv[po][i - 1] + vv[to][i - 1];	
				}
			}
			po ++;
		}
		else {
			int ans = 0 , sum = 0 , now = a;
			RREP(i , 19 , 0){
				if(sp[now][i] != 0 && sum + vv[now][i] <= b){
					ans += (1 << i);
					sum += vv[now][i];
					now  = sp[now][i];
				}
			}
			while(now != 0 && sum + vv[now][0] <= b){
				ans ++;
				now  = sp[now][0];
				sum += vv[now][0];
			}
			las = ans;
			cout << ans << endl;
		}
	}
    return 0;
}