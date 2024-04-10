#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j)       for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)   for(int i = j ; i < k ; i++)
#define RREP(i,j,k)    for(int i = j ; i >=k ; i--)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define VI  vector<int> 
#define VPII vector<PII>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define MAX 510
#define INF 0x3f3f3f3f

int n , m;
int p[MAX][MAX] , dis[MAX][MAX] , last[MAX][MAX];
void solve(){
    REPNM(i , 1 , n + 1)
        REPNM(j , 1 , n + 1)
            dis[i][j] = p[i][j];
    REPNM(k , 1 , n + 1){
        REPNM(i , 1 , n + 1){
            REPNM(j , 1 , n + 1)
                dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
        }
    }
    REPNM(i , 1 , n + 1){
        REPNM(j , 1 , n + 1){
            REPNM(k , 1 , n + 1){
                if(j != k && p[j][k] != INF && dis[i][j] + p[j][k] == dis[i][k]) last[i][k] ++;
            }
        }
    }
    REPNM(i , 1 , n + 1){
        REPNM(j , i + 1 , n + 1){
            if(dis[i][j] == INF) cout << "0 ";
            else {
                int res = 0;
                REPNM(k , 1 , n + 1){
                    if(dis[i][k] + dis[k][j] == dis[i][j]) res += last[i][k];
                }
                cout << res << " " ;
            }
        }
    }
    cout << "\n";
}
int32_t main(){
    cin >> n >> m;

    MEM(p , INF);
    REPNM(i , 1 , n + 1) p[i][i] = 0; 

    REP(i , m){
        int q , w , e;
        cin >> q >> w >> e;
        p[q][w] = p[w][q] = e;
    }

    solve();
    return 0;
}