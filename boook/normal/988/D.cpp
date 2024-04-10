/*input
5
-1 2 5 8 11
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
#define int long long
#define MAX 200900
#define INF 0x3f3f3f3f

int n , x[MAX] , u[MAX];
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    set<int> cc;
    REP(i , 1 , n + 1) cc.insert(x[i]);
    REP(i , 1 , n + 1){
        REP(j , 0 , 40){
            int fr = x[i] - (1LL << j);
            int ba = x[i] + (1LL << j);
            if(cc.count(fr) && cc.count(ba)){
                cout << 3 << endl;
                cout << fr << " " << x[i] << " " << ba << endl;
                return 0;
            }
        }
    }
    REP(i , 1 , n + 1){
        REP(j , 0 , 40){
            int fr = x[i] - (1LL << j);
            int ba = x[i] + (1LL << j);
            if(cc.count(fr)){
                cout << 2 << endl;
                cout << fr << " " << x[i] << endl;
                return 0;
            }
            if(cc.count(ba)){
                cout << 2 << endl;
                cout << ba << " " << x[i] << endl;
                return 0;
            }
        }
    }
    cout << 1 << endl;
    cout << x[1] << endl;
    return 0;
}