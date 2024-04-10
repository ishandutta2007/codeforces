/*input
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
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 50
#define INF 0x3f3f3f3f

int n , m , x[MAX] , b[MAX];
set<int> cc;
int32_t main(){
    cin >> n >> m;
    REP(i , 0 , n) cin >> x[i];

    if(n < 18){
        int big = 0;
        REP(i , 0 , (1 << n)){
            int val = 0;
            REP(j , 0 , n){
                if(i & (1 << j)) val += x[j];
            }
            big = max(big , val % m);
        }
        cout << big << endl;
    }
    else {
        int big = 0 , N = 16;
        REP(i , N , n) b[i - N] = x[i];
        REP(i , 0 , (1 << N)){
            int val = 0;
            REP(j , 0 , N){
                if(i & (1 << j)) val += x[j];
            }
            cc.insert(val % m);
            cc.insert(val % m - m);
        }
        // for(auto to : cc) cout << to << " " ; cout << endl;
        REP(i , 0 , (1 << (n - N))){
            int val = 0;
            REP(j , 0 , n - N){
                if(i & (1 << j)) val = (val + b[j]) % m;
            }
            auto tmp = cc.lower_bound(m - val); tmp --;
            big = max(big , ((*tmp) + m + val) % m);
        }
        cout << big << endl;
    }
    return 0;
}