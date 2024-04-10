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
#define int long long
#define MAX 500
#define INF 10000000000LL

int n , m , p[MAX][MAX];

int32_t main(){
    cin >> n >> m;
    REP(i , 0 , m){
        int q , w;
        cin >> q >> w;
        p[q][w] = 1 , p[w][q] = 1;
    }
    if(p[1][n] == 1){
        REP(i , 1 , n + 1) REP(j , 1 , n + 1){
            p[i][j] ^= 1;
        }
    }
    REP(i , 1 , n + 1) REP(j , 1 , n + 1)
        if(p[i][j] == 0) p[i][j] = INF;
    REP(k , 1 , n + 1){
        REP(i , 1 , n + 1){
            REP(j , 1 , n + 1){
                p[i][j] = min(p[i][j] , p[i][k] + p[k][j]);
            }
        }
    }
    if(p[1][n] == INF) p[1][n] = -1;
    cout << p[1][n] << endl;
    return 0;
}