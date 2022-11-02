#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j)       for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)   for(int i = j ; i < k ; i++)
#define RREP(i,j,k)    for(int i = j ; i >=k ; i--)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define VI  vector<int> 
#define VPII vector<PII>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define int long long
#define MAX 200090
#define INF 0x3f3f3f3f

int n , x[MAX];
int solve(){
    int ok = 0 , d = 87 , stpo = 0 , valpo = 87;
    int ans = 1;
    if(x[0] == -1){
        ok = 0 , stpo = 0;
    }
    else ok = 1 , stpo = 0 , valpo = 0;
    REPNM(i , 1 , n){
        if(ok == 0){
            if(x[i] == -1) continue;
            else ok = 1 , valpo = i;
        }
        else if(ok == 1){
            if(x[i] == -1) continue;
            else {
                int tmp = x[i] - x[valpo];
                if(tmp % (i - valpo) != 0){
                    ans ++ , ok = 1 , stpo = i , valpo = i;
                }
                else {
                    d = tmp / (i - valpo);
                    int ffr = x[valpo] - (valpo - stpo) * d;
                    if(ffr <= 0) ans ++ , ok = 1 , stpo = i , valpo = i;
                    else ok = 2;
                }
            }
        }
        else if(ok == 2){
            int tmp = (i - valpo) * d + x[valpo];
            if(x[i] == -1 && tmp > 0) continue;
            else if(tmp == x[i] && tmp > 0) continue;
            else {
                if(x[i] == -1) ans ++ , ok = 0 , stpo = i;
                else ans ++ , ok = 1 , stpo = i , valpo = i;
            }
        }
    }
    return ans;
}
int32_t main(){
    cin >> n;
    REP(i , n) cin >> x[i];
    int ans = solve();
    cout << ans << "\n";
    
    return 0;
}