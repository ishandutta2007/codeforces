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
#define MAX 300000
#define INF 0x3f3f3f3f

int n , m , x[MAX];
set<int> cc;
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> x[i];
    int odd = 0 , even = 0;
    REP(i , 1 , n + 1){
        if(cc.find(x[i]) != cc.end()) x[i] = -1;
        else {
            int ok = 0;
            if(x[i] % 2 == 0 && even < n / 2){
                even ++ , ok = 1;
                cc.insert(x[i]);
            }
            if(x[i] % 2 == 1 && odd < n / 2){
                odd ++ , ok = 1;
                cc.insert(x[i]);
            }
            if(ok == 0) x[i] = -1;
        }
    }
    // REP(i , 1 , n + 1) cout << x[i] << " "; cout << endl;
    // DB4("even = " , even , "odd = " , odd);
    int po = 1 , cnt = 0;
    REP(i , 1 , n + 1){
        if(x[i] == -1){
            cnt ++;
            while(1){
                if(po > m) return cout << -1 << endl , 0;
                else if(cc.find(po) != cc.end()) po ++;
                else if(po % 2 == 0){
                    if(even == n / 2) po ++;
                    else { x[i] = po ++ , even ++; break; }
                }
                else if(po % 2 == 1){
                    if(odd == n / 2) po ++;
                    else { x[i] = po ++ , odd ++; break; }
                }
            }
        }
    }
    cout << cnt << endl;
    REP(i , 1 , n + 1) cout << x[i] << " " ; cout << endl;
    return 0;
}