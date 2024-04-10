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
#define MAX 100090
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int jan[MAX] , mo[MAX] , u[MAX];
int mypow(int now , int k){
    if(k == 0) return 1;
    if(k & 1) return mypow(now * now % mod , k / 2) % mod * now % mod;
    return mypow(now * now % mod , k / 2);
}
void pre(){
    mo[0] = mo[1] = jan[0] = jan[1] = 1;
    REPNM(i , 2 , MAX) jan[i] = (jan[i - 1] * i) % mod;
    REPNM(i , 2 , MAX) mo[i] = mypow(jan[i] , mod - 2);
    u[1] = 1;
    REPNM(i , 1 , MAX) for(int j = i + i ; j < MAX ; j += i) u[j] -= u[i];
}

int C(int q , int w){
    return jan[q] * mo[w] % mod * mo[q - w] % mod * (q >= w);
}
int P(int n , int f){
    // DB4(n - 1 , f - 1 , "ans = " , C(n - 1 , f - 1));
    return C(n - 1 , f - 1);
}
int t , n , m;
int32_t main(){
    pre();
    IOS;
    cin >> t;
    REPNM(times , 1 , t + 1){
        cin >> n >> m;
        int ans = 0;
        REPNM(i , 1 , n + 1){
            if(i * i > n) break;
            else if(i * i == n){
                ans = (ans + u[i] * P(i , m)) % mod;
            }
            else if(n % i == 0){
                // DB4(i , u[i] , P(n / i , m) , u[i] * P(n / i , m));
                ans = (ans + u[i] * P(n / i , m)) % mod;
                ans = (ans + u[n / i] * P(i , m)) % mod;
            }
        }
        ans = (ans + mod) % mod;
        cout << ans << "\n";
    }
    return 0;
}