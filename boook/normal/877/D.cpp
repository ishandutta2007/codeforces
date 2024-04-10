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
#define N 317

int n , m , k , dis[MAX][MAX];
PII st , en;
string s[MAX];
typedef pair<int , PII> PIII;
int X[] = {-1 , 0 , 0 , 1};
int Y[] = {0 , -1 , 1 , 0};
void solve(){
    MEM(dis , INF);
    priority_queue<PIII , vector<PIII> , greater<PIII>> pq;
    pq.push(mp(0 , st)) , dis[st.A][st.B] = 0;
    while(pq.size()){
        int step = pq.top().A;
        int x = pq.top().B.A;
        int y = pq.top().B.B;
        pq.pop();
        if(dis[x][y] != step) continue;
        REP(i , 0 , 4){
            int tox = x + X[i];
            int toy = y + Y[i];
            REP(times , 0 , k){
                if(tox >= 0 && tox < n && toy >= 0 && toy < m);
                else break;
                if(s[tox][toy] == '#') break;
                if(dis[tox][toy] == step) break;
                if(dis[tox][toy] > step + 1){
                    dis[tox][toy] = step + 1;
                    pq.push(mp(step + 1 , mp(tox , toy)));
                }
                tox += X[i];
                toy += Y[i];
            }
        }
    }
}
int32_t main(){
    IOS;
    cin >> n >> m >> k;
    REP(i , 0 , n) cin >> s[i];
    cin >> st.A >> st.B >> en.A >> en.B;
    st.A--, st.B--, en.A--, en.B--;
    solve();
    int ans = dis[en.A][en.B];

//    REP(i , 0 , n){
//        REP(j , 0 , m) cout << dis[i][j] << " " ;
//        cout << endl;
//    }

    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}