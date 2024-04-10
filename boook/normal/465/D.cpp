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
#define MAX 10
#define INF 0x3f3f3f3f

int x[MAX][3] , ok = 0;
int q[MAX][3];
void DFS(int fl){
    if(ok) return;
    if(fl == 8){
        vector<int> sol;
        REP(i , 0 , 8){
            REP(j , i + 1 , 8){
                int tmp = 0;
                REP(k , 0 , 3) tmp += (q[i][k] - q[j][k]) * (q[i][k] - q[j][k]);
                sol.pb(tmp);
            }
        }
        int mm = sol[0] , a = 0 , b = 0 , c = 0;
        for(auto to : sol) mm = min(mm , to);
        for(auto to : sol){
            if(to == mm * 1) a ++;
            else if(to == mm * 2) b ++;
            else if(to == mm * 3) c ++;
        }
        if(a == 12 && b == 12 && c == 4){
            ok = 1;
            cout << "YES" << endl;
            REP(i , 0 , 8){
                REP(j , 0 , 3)
                    cout << q[i][j] << " ";
                cout << endl;
            }
        }
    }
    else {
        q[fl][0] = x[fl][0] , q[fl][1] = x[fl][1] , q[fl][2] = x[fl][2];
        DFS(fl + 1);
        q[fl][0] = x[fl][0] , q[fl][1] = x[fl][2] , q[fl][2] = x[fl][1];
        DFS(fl + 1);
        q[fl][0] = x[fl][1] , q[fl][1] = x[fl][0] , q[fl][2] = x[fl][2];
        DFS(fl + 1);
        q[fl][0] = x[fl][1] , q[fl][1] = x[fl][2] , q[fl][2] = x[fl][0];
        DFS(fl + 1);
        q[fl][0] = x[fl][2] , q[fl][1] = x[fl][0] , q[fl][2] = x[fl][1];
        DFS(fl + 1);
        q[fl][0] = x[fl][2] , q[fl][1] = x[fl][1] , q[fl][2] = x[fl][0];
        DFS(fl + 1);
    }
}
int32_t main(){
    REP(i , 0 , 8) REP(j , 0 , 3) cin >> x[i][j];
    q[0][0] = x[0][0] , q[0][1] = x[0][1] , q[0][2] = x[0][2];
    DFS(1);
    if(ok == 0) cout << "NO" << endl;
    return 0;
}