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
#define MAX 210
#define INF 0x3f3f3f3f

int n , m , k , use[MAX][MAX];
string p[MAX];
PII to[MAX];
PII dp[MAX][MAX][11];
PII TO(PII now){
    int ty = p[now.A][now.B] - '0';
    PII xy = mp(now.A + to[ty].A , now.B + to[ty].B);
    if(xy.A >= 0 && xy.A < n && xy.B >= 0 && xy.B < m) return xy;
    else return now;
}
void DP(int a , int b){
    use[a][b] = 1;
    PII tmp = TO(mp(a , b));
    if(tmp.A == a && tmp.B == b){
        dp[a][b][p[a][b] - '0'] = mp(a , b);
    }
    else {
        dp[a][b][p[a][b] - '0'] = tmp;
        if(use[tmp.A][tmp.B] == 0) DP(tmp.A , tmp.B);
        REP(k , 0 , 10)
            if(k != p[a][b] - '0') dp[a][b][k] = dp[tmp.A][tmp.B][k];
    }
}
vector<PII> fr;

int check(string s){
    for(auto now : fr){
        PII tmp = now;
        int ok = 1;
        REP(i , 0 , s.size()){
            if(dp[tmp.A][tmp.B][s[i] - '0'].A != -1 && tmp.A != -1){
                tmp = dp[tmp.A][tmp.B][s[i] - '0'];
            }
            else { ok = 0; break; }
        }
        if(ok) return 1;
    }
    return 0;
}
int32_t main(){
    IOS;
    cin >> n >> m >> k;

    REP(i , 0 , n) cin >> p[i];

    REP(i , 0 , 10)
        cin >> to[i].A >> to[i].B;

    REP(i , 0 , n) REP(j , 0 , m) REP(k , 0 , 10)
        dp[i][j][k] = mp(-1 , -1);

    REP(i , 0 , n) REP(j , 0 , m) {
        if(use[i][j] == 0){
            fr.pb(mp(i , j));
            DP(i , j);
        } 
    }

    string s;
    REP(i , 0 , k){
        cin >> s;
        cout << ((check(s) == 1) ? "YES" : "NO") << endl;
    }
    return 0;
}