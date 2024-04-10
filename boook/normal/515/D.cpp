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
#define MAX 2010
#define INF 0x3f3f3f3f

int n , m , use[MAX][MAX];
string p[MAX];
int X[] = {-1 , 0 , 0 , 1};
int Y[] = {0 , -1 , 1 , 0};
int IN(int q , int w){
    if(q >= 0 && q < n && w >= 0 && w < m) return 1;
    return 0;
}
int o[MAX][MAX];
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 0 , n) cin >> p[i];
    
        
    queue<PII> pq;
    int cnt = 0;
    REP(i , 0 , n) REP(j , 0 , m){
        if(p[i][j] == '.'){
            cnt ++;
            REP(k , 0 , 4){
                int q = i + X[k] , w = j + Y[k];
                if(IN(q , w) && p[q][w] == '.') o[i][j] ++;
            }
            if(o[i][j] == 0){ cout << "Not unique" << endl; return 0; }
            if(o[i][j] == 1) pq.push(mp(i , j));
        }
    }

    if(cnt == 0){
        REP(i , 0 , n) cout << p[i] << endl;
        return 0;
    }
    while(pq.size()){
        PII now = pq.front(); pq.pop();
        if(o[now.A][now.B] != 1) continue;
        // DB4(now.A , now.B , );
        o[now.A][now.B] = 0;
        cnt -= 2;
        REP(k , 0 , 4){
            int q = now.A + X[k] , w = now.B + Y[k];
            if(IN(q , w) && p[q][w] == '.'){
                if(now.A == q){
                    p[q][min(now.B , w)] = '<';
                    p[q][max(now.B , w)] = '>';
                }
                else {
                    p[min(now.A , q)][w] = '^';
                    p[max(now.A , q)][w] = 'v';
                }
                o[q][w] = 0;
                REP(qq , 0 , 4){
                    int a = q + X[qq] , b = w + Y[qq];
                    if(IN(a , b) && p[a][b] == '.'){
                        o[a][b] --;
                        if(o[a][b] == 1){
                            pq.push(mp(a , b));
                        }
                    }
                }
                break;
            }
        }
        // cout << "-0------" << endl;
        // REP(i , 0 , n) {REP(j , 0 , m) cout << o[i][j] ; cout << endl;} 
        // cout << endl;
        // REP(i , 0 , n) cout << p[i] << endl;

    }
    // DBGG("cnt = " , cnt);
    if(cnt != 0){ cout << "Not unique" << endl; return 0; }
    REP(i , 0 , n) cout << p[i] << endl;
    return 0;
}