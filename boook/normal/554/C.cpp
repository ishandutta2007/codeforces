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
#define MAX 1010
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int n , x[MAX] , c[MAX] , cc[MAX];
int ppow(int now , int k){
    if(k == 0) return 1;
    if(k % 2 == 0) return ppow(now * now % mod , k >> 1);
    if(k % 2 == 1) return ppow(now * now % mod , k >> 1) * now % mod;
}
int C(int a , int b){
    return c[a] * cc[b] % mod * cc[a - b] % mod;
}
int32_t main(){

    c[0] = 1;
    REP(i , 1 , MAX) c[i] = c[i - 1] * i % mod;
    REP(i , 0 , MAX) cc[i] = ppow(c[i] , mod - 2);

    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];

    int ans = 1 , sum = 0;
    REP(i , 1 , n + 1){
        ans = (ans * C(sum + x[i] - 1 , sum) % mod);
        sum += x[i];
    }
    cout << ans << endl;
    return 0;
}