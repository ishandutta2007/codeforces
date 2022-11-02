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
#define MAX 1010
#define INF 0x3f3f3f3f

int n , m;
string p[MAX];
int dis[MAX][MAX][4];
int IN(int a , int b){
    return (a >= 0 && a < n && b >= 0 && b < m);
}
typedef pair<PII , int> PIII;
int X[] = {-1 , 0 , 0 , 1};
int Y[] = {0 , -1 , 1 , 0};
int len[5][5];
void BFS(int ty){
    queue<PIII> pq;
    REP(i , 0 , n) REP(j , 0 , m)
        if(p[i][j] - '1' == ty) pq.push(mp(mp(i , j) , 0)) , dis[i][j][ty] = 0;
    while(pq.size()){
        PII now = pq.front().A;
        int step = pq.front().B; pq.pop();
        REP(i , 0 , 4){
            int q = now.A + X[i] , w = now.B + Y[i];
            if(IN(q , w) && p[q][w] != '#' && dis[q][w][ty] > step + 1){
                if(p[q][w] != '.'){
                    int to = p[q][w] - '1';
                    len[ty][to] = min(len[ty][to] , step);
                }
                else {
                    dis[q][w][ty] = step + 1;
                    pq.push(mp(mp(q , w) , dis[q][w][ty]));
                }
            }
        }
    }
}
int32_t main(){

    cin >> n >> m;
    REP(i , 0 , n) cin >> p[i];
    MEM(dis , INF) , MEM(len , INF);
    BFS(0) , BFS(1) , BFS(2);
    int ans = INF;

    // cout << endl;
    // REP(i , 0 , n){
    //     REP(j , 0 , m){
    //         if(dis[i][j][1] == INF) dis[i][j][1] = 9;
    //         cout << dis[i][j][1] << "   ";        
    //     }
    //     cout << endl;

    // }

    ans = min(ans , len[0][1] + len[0][2]);
    ans = min(ans , len[1][0] + len[1][2]);
    ans = min(ans , len[2][0] + len[2][1]);
    REP(i , 0 , n) REP(j , 0 , m){
        if(dis[i][j][0] >= INF) continue;
        if(dis[i][j][1] >= INF) continue;
        if(dis[i][j][2] >= INF) continue;
        ans = min(ans , dis[i][j][0] + dis[i][j][1] + dis[i][j][2] - 2);
    }
    if(ans >= INF) cout << "-1" << endl;
    else cout << ans << endl;
    return 0;
}