/*input
2 3
00 10 1
01 11 1
10 01 1
10 01 1
*/
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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 330
#define INF 0x3f3f3f3f

// string ss[MAX][MAX];
vector<pair<PII , PII>> ans;
void add(int a , int b , int c , int d){
    ans.pb(mp(mp(a , b) , mp(c , d)));
    // if(ss[a][b].size() == 0) {DBGG("WA" , "0");exit(0);}
    // if(ss[a][b].back() == '0') ss[c][d].insert(0 , "0");
    // if(ss[a][b].back() == '1') ss[c][d].insert(0 , "1");
    // ss[a][b].pop_back();
}

int n , m;
PII x[MAX][MAX] , sum[MAX][MAX]; // 0 , 1
string s[MAX][MAX] , p[MAX][MAX];
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) REP(j , 1 , m + 1) cin >> s[i][j];
    // , ss[i][j] = s[i][j];
    REP(i , 1 , n + 1) REP(j , 1 , m + 1) cin >> p[i][j];
    REP(i , 1 , n + 1) REP(j , 1 , m + 1){
        RREP(k , int(s[i][j].size()) - 1 , 0){
            int tox = i , toy = j;
            if(s[i][j][k] == '0'){
                if(j % 2 == 1) tox = i == 1 ? 2 : i - 1;
                else toy = j == 1 ? 2 : j - 1;
                x[tox][toy].A ++;
            }
            if(s[i][j][k] == '1'){
                if(j % 2 == 1) toy = j == 1 ? 2 : j - 1;
                else tox = i == 1 ? 2 : i - 1;
                x[tox][toy].B ++;
            }
            add(i , j , tox , toy);
        }
    }

    REP(i , 1 , n + 1) REP(j , 1 , m + 1){
        if(j != 1){
            while(x[i][j].A) add(i , j , i , 1) , x[i][j].A -- , x[i][1].A ++;
        }
        if(j != m){
            while(x[i][j].B) add(i , j , i , m) , x[i][j].B -- , x[i][m].B ++;
        }
    }

    REP(i , 1 , n + 1) REP(j , 1 , m + 1){
        REP(k , 0 , p[i][j].size()){
            if(p[i][j][k] == '0'){
                if(j != 1)      sum[i][1].A ++;
                else if(i != 1) sum[1][1].A ++;
                else            sum[2][1].A ++;
            }
            if(p[i][j][k] == '1'){
                if(j != m)      sum[i][m].B ++;
                else if(i != 1) sum[1][m].B ++;
                else            sum[2][m].B ++;
            }
        }
    }

    int pos = 1;
    REP(i , 1 , n + 1){
        while(pos <= n && x[i][1].A > sum[i][1].A){
            while(pos <= n && x[pos][1].A >= sum[pos][1].A) pos ++;
            add(i , 1 , pos , 1) , x[i][1].A -- , x[pos][1].A ++;
        }
    }
    pos = 1;
    REP(i , 1 , n + 1){
        while(pos <= n && x[i][m].B > sum[i][m].B){
            while(pos <= n && x[pos][m].B >= sum[pos][m].B) pos ++;
            add(i , m , pos , m) , x[i][m].B -- , x[pos][m].B ++;
        }
    }
    // REP(i , 1 , n + 1){
    //     REP(j , 1 , m + 1) cout << ss[i][j] << "-"; cout << endl;
    // }


    REP(i , 1 , n + 1) REP(j , 1 , m + 1){
        RREP(k , int(p[i][j].size()) - 1 , 0){
            if(p[i][j][k] == '0'){
                if(j != 1)      add(i , 1 , i , j);
                else if(i == 1) add(2 , 1 , i , j);
                else            add(1 , 1 , i , j); 
            }
            if(p[i][j][k] == '1'){
                if(j != m)      add(i , m , i , j);
                else if(i == 1) add(2 , m , i , j);
                else            add(1 , m , i , j);
            }
        }
    }
    // REP(i , 1 , n + 1){
    //     REP(j , 1 , m + 1) cout << x[i][j].A << " " << x[i][j].B << "-"; cout << endl;
    // }
    // REP(i , 1 , n + 1){
    //     REP(j , 1 , m + 1) cout << ss[i][j] << "-"; cout << endl;
    // }
    cout << ans.size() << endl;
    for(auto to : ans){
        cout << to.A.A << " " << to.A.B << " " << to.B.A << " " << to.B.B << endl;
    }
    return 0;
}