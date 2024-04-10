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
// #define DBGG(i,j)     cout << i << " " << j << endl
// #define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 16
#define INF 0x3f3f3f3f

int n , m , k;
int x[200][2] , a[200][3];
int dp[MAX][(1 << MAX)];
void PT(int now){
    bitset<MAX> qqq(now);
    REP(i , 0 , n + 1) cout << qqq[i] << " ";cout << endl;    
}
int check(int now , int gh , int newroot , int newgh){
    REP(i , 0 , m){
        if(x[i][0] == now && (newgh & (1 << x[i][1]))) return 0;
        if(x[i][1] == now && (newgh & (1 << x[i][0]))) return 0;

        if(x[i][0] == newroot && (gh & (1 << x[i][1]))) return 0;
        if(x[i][1] == newroot && (gh & (1 << x[i][0]))) return 0;

        if((newgh & (1 << x[i][0])) && (gh & (1 << x[i][1]))) return 0;
        if((newgh & (1 << x[i][1])) && (gh & (1 << x[i][0]))) return 0;
    }
    // DB4(now , gh , newroot , newgh);
    REP(i , 0 , k){
    	if(a[i][0] == a[i][1] && a[i][0] != a[i][2]) return 0;
        if(a[i][2] == now){
            int cnt = 0;
            if(newroot == a[i][0] || newroot == a[i][1]) cnt ++;
            if(newgh & (1 << a[i][0])) cnt ++;
            if(newgh & (1 << a[i][1])) cnt ++;
            if(cnt == 2) return 0;
        }
        if(a[i][2] == newroot){
            int cnt = 0;
            if(now == a[i][0] || now == a[i][1]) return 0;
            if(gh & (1 << a[i][0])) return 0;
            if(gh & (1 << a[i][1])) return 0;
            if((newgh & (1 << a[i][0])) == 0 && newroot != a[i][0]) return 0;
            if((newgh & (1 << a[i][1])) == 0 && newroot != a[i][1]) return 0;
        }
        if((newgh & (1 << a[i][2])) && (gh & (1 << a[i][0]))) return 0;
        if((newgh & (1 << a[i][2])) && (gh & (1 << a[i][1]))) return 0;
        if((newgh & (1 << a[i][2])) && (now == a[i][0] || now == a[i][1])) return 0;
        if((newgh & (1 << a[i][2])) && (newroot == a[i][0] || newroot == a[i][1])) return 0;
        
        // if((gh & (1 << a[i][2])) && (newgh & (1 << a[i][0]))) return 0;
        // if((gh & (1 << a[i][2])) && (newgh & (1 << a[i][1]))) return 0;
        // if((gh & (1 << a[i][2])) && (now == a[i][0] || now == a[i][1])) return 0;
        // if((gh & (1 << a[i][2])) && (newroot == a[i][0] || newroot == a[i][1])) return 0;
    }
    // cout << "ok : " ;DB4(now , gh , newroot , newgh);
    return 1;
}
int DFS(int now , int gh){
    // DB4("DFS now = " , now , gh , "");
    if(dp[now][gh] != -1) return dp[now][gh];
    if(gh == 0) return dp[now][gh] = 1;
    dp[now][gh] = 0;
    bitset<MAX> tmp(gh);
    int cnt = 0;
    RREP(i , MAX - 1 , 0) if(tmp.test(i)) cnt = i;
    // DBGG("cnt = " , cnt);
    int tgh = gh ^ (1 << cnt);
    for(int i = tgh ; ; i = (i - 1) & tgh){
  		bitset<MAX> newgh(i);

    	REP(j , 0 , MAX){
    		if(newgh.test(j)){
    			if(check(now , tgh ^ i , j , i ^ (1 << cnt) ^ (1 << j))){
    				dp[now][gh] += DFS(j , i ^ (1 << cnt) ^ (1 << j)) * DFS(now , tgh ^ i);
    				// if(now == 0 && tgh == ((1 << n) - 2) ^ 2){
    				// 	DB4("newroot = " , j , "now = " , now);
    				// 	PT(i ^ (1 << cnt) ^ (1 << j));
    				// 	PT(tgh ^ i);
    				// 	DB4("","GET = " , DFS(j , i ^ (1 << cnt) ^ (1 << j)) , DFS(now , tgh ^ i));
    				// }
    			}
    		}
    	}
    	if(check(now , tgh ^ i , cnt , i)){
			dp[now][gh] += DFS(cnt , i) * DFS(now , tgh ^ i);
			// if(now == 0 && tgh == ((1 << n) - 2) ^ 2){
			// 	DB4("newroot = " , cnt , "now = " , now);
			// 	PT(i);
			// 	PT(tgh ^ i);
			// 	DB4("","GET = " , DFS(cnt , i) , DFS(now , tgh ^ i));
			// }
		}
    	if(i == 0) break;
    }
    // printf("dp[%d][%d] = %d\n", now , gh , dp[now][gh]);
    return dp[now][gh];
}
int32_t main(){
    MEM(dp , -1);
    cin >> n >> m >> k;
    REP(i , 0 , m) REP(j , 0 , 2) cin >> x[i][j] , x[i][j] --;
    REP(i , 0 , k) REP(j , 0 , 3) cin >> a[i][j] , a[i][j] --;
    int now = (1 << n) - 2;
    int ans = DFS(0 , now);
    cout << ans << endl;
    return 0;
}