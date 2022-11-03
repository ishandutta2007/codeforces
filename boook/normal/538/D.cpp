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
#define MAX 200
#define INF 0x3f3f3f3f

string p[MAX];
int n , use[MAX][MAX] , ans[MAX][MAX];
vector<PII> v;
int IN(int a , int b){
    return (a >= 0 && a < n && b >= 0 && b < n);
}
int check(int a , int b){
    REP(i , 0 , n){
        REP(j , 0 , n){
            if(p[i][j] == 'o'){
                int x = i + a , y = j + b;
                if(IN(x , y) && p[x][y] == '.') return 0;
            }
        }
    }
    REP(i , 0 , n){
        REP(j , 0 , n){
            if(p[i][j] == 'o'){
                int x = i + a , y = j + b;
                if(IN(x , y) && p[x][y] == 'x') use[x][y] = 1;
            }
        }
    }
    return 1;
}
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 0 , n) cin >> p[i];
    // DBGG("check = " , check(-1 , 1));
    REP(i , -n , n + 1){
        REP(j , -n , n + 1){
            if(i == 0 && j == 0) continue;
            if(check(i , j) == 1){
                // DBGG(i , j);
                v.pb(mp(i , j));
            }
        }
    }
    REP(i , 0 , n){
        REP(j , 0 , n){
            // cout << use[i][j];
            if(p[i][j] == 'x' && use[i][j] == 0){
                cout << "NO" << endl;
                return 0;
            }
        }
        // cout << endl;
    }
    cout << "YES" << endl;
    ans[n - 1][n - 1] = -2;
    for(auto to : v){
        int a = n - 1 + to.A;
        int b = n - 1 + to.B;
        if(a >= 0 && b >= 0 && a < MAX && b < MAX)
            ans[a][b] = -1;
    }
    REP(a , 0 , n + n - 1){
        REP(b , 0 , n + n - 1){
            if(ans[a][b] == 0) cout << '.';
            else if(ans[a][b] == -1) cout << 'x';
            else if(ans[a][b] == -2) cout << 'o';
        }
        cout << endl;
    }
    return 0;
}