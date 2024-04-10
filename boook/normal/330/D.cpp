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

int n , m;
int dis[MAX][MAX];
string s[MAX];
int X[] = {-1 , 0 , 0 , 1};
int Y[] = {0 , -1 , 1 , 0};
void BFS(int q , int w){
    MEM(dis , -1);
    queue<PII> qu;
    dis[q][w] = 0;
    qu.push(mp(q , w));
    while(qu.size()){
        PII now = qu.front(); qu.pop();
        REP(i , 0 , 4){
            int xx = now.A + X[i];
            int yy = now.B + Y[i];
            if(xx >= 0 && xx < n && yy >= 0 && yy < m && s[xx][yy] != 'T'){
                if(dis[xx][yy] == -1){
                    dis[xx][yy] = dis[now.A][now.B] + 1;
                    qu.push(mp(xx , yy));
                }
            }
        }
    }
}
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 0 , n) cin >> s[i];
    int qq , ww;
    REP(i , 0 , n){
        REP(j , 0 , m){
            if(s[i][j] == 'E') BFS(i , j);
            if(s[i][j] == 'S') qq = i , ww = j;
        }
    }
    int val = dis[qq][ww] , cnt = 0;
    // DBGG("val =" , val);
    REP(i , 0 , n) REP(j , 0 , m){
        if(s[i][j] >= 0 && s[i][j] <= '9' && dis[i][j] >= 0){
            if(dis[i][j] <= val) cnt += s[i][j] - '0';
        }
    }
    // REP(i , 0 , n){
    //     REP(j , 0 , m) cout << dis[i][j] << " " ; cout << endl;
    // }
    cout << cnt << endl;
    return 0;
}