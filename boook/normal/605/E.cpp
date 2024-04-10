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
#define MAX 1010
#define INF 0x3f3f3f3f

int n , use[MAX];
double p[MAX][MAX] , dis[MAX] , a[MAX] , b[MAX];
int32_t main(){
    scanf("%d" , &n);
    REP(i , 1 , n + 1) REP(j , 1 , n + 1)
        scanf("%lf" , &p[i][j]) , p[i][j] /= 100;
    REP(i , 1 , n + 1) a[i] = 1;
    REP(i , 1 , n + 1) b[i] = 1;
    REP(i , 0 , n + 1) dis[i] = 1e30;
    dis[n] = 0;
    REP(times , 1 , n + 1){
        int now = 0;
        REP(i , 1 , n + 1){
            if(use[i]) continue;
            if(dis[i] < dis[now]) now = i;
        }
        use[now] = 1;
        REP(from , 1 , n + 1){
            if(use[from]) continue;
            a[from] += b[from] * p[from][now] * dis[now];
            b[from] *= (1.0 - p[from][now]);
            dis[from] = a[from] / (1 - b[from]);
        }
    }
    printf("%.11f\n", dis[1]);
    return 0;
}