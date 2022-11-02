#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 110
#define INF 0x3f3f3f3f

int t[15][MAX][MAX] , pre[15][MAX][MAX];
int n , k , mm;
int32_t main(){
	IOS;
	cin >> n >> k >> mm;
	REP(i , 0 , n){
		int q , w , e;
		cin >> q >> w >> e;
		int cnt = 0;
		REP(i , 0 , mm + 1){
			t[cnt][q][w] += e;
			if(e + 1 > mm) e = 0;
			else e++;
			cnt ++;
		}
	}
	REP(i , 0 , 13){
		REP(j , 1 , MAX){
			REP(k , 1 , MAX){
				pre[i][j][k] = pre[i][j - 1][k] + 
					pre[i][j][k - 1] - pre[i][j - 1][k - 1];
				pre[i][j][k] += t[i][j][k];
			}
		}
	}
	REP(i , 0 , k){
		int tt , a , b , x , y;
		cin >> tt >> a >> b >> x >> y;
		tt = tt % (mm + 1);
		int val = 0;
		val += pre[tt][x][y];
		val -= pre[tt][a - 1][y];
		val -= pre[tt][x][b - 1];
		val += pre[tt][a - 1][b - 1];
		cout << val << endl;
	}
    return 0;
}