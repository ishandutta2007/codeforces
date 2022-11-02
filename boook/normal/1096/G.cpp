/*input
1000 7
5 4 0 1 8 3 2
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
#define int int_fast64_t
#define MAX (1 << 20 | 10)
#define INF 0x3f3f3f3f
#define mod 998244353LL
#define inv 998243401LL

int n = (1 << 20) , base = 20;
int tmp[MAX] , x[MAX] , w[MAX] = {1 , 565042129};
string a , b;
void NTT(int now[MAX]){
    int siz = 0 , pat = (n >> 1) - 1;
    RREP(i , base - 1 , 0){
        REP(j , 0 , n){
            int fr = j >> i , ba = j & pat;
            int a = (fr & siz) << 1 | 0;
            int b = (fr & siz) << 1 | 1;
            tmp[j] = (now[a << i | ba] + now[b << i | ba] * w[fr << i]) % mod;
        }
        REP(j , 0 , n) now[j] = tmp[j];
        siz = (siz << 1 | 1) , pat >>= 1;
    }
}
int INTT(int now[MAX]){
    NTT(now) , reverse(now + 1 , now + n);
    REP(i , 0 , n) now[i] = now[i] * inv % mod;
}
int ppow(int a , int k){
    if(k == 0) return 1;
    if(k % 2 == 0) return ppow(a * a % mod , k >> 1);
    if(k % 2 == 1) return ppow(a * a % mod , k >> 1) * a % mod;
}
int in[MAX];
int32_t main(){
    IOS;

    REP(i , 2 , n) w[i] = w[i - 1] * w[1] % mod;

    int nn , mm;
    cin >> nn >> mm;
    REP(i , 1 , mm + 1) cin >> in[i];
    REP(i , 1 , mm + 1) x[in[i]] = 1;

    NTT(x);
    REP(i , 0 , n) x[i] = ppow(x[i] , nn / 2);
    INTT(x);

    int ans = 0;
    REP(i , 0 , n){
        ans = (ans + x[i] * x[i]) % mod;
    }
    cout << ans << endl;
    return 0;
}
    // cin >> a >> b;
    // reverse(ALL(a)) , reverse(ALL(b));
    
    // REP(i , 0 , a.size()) x[i] = a[i] - '0';
    // REP(i , 0 , b.size()) y[i] = b[i] - '0';

    // NTT(x) , NTT(y);
    // REP(i , 0 , n) x[i] = x[i] * y[i] % mod;
    // INTT(x);

    // REP(i , 0 , n) x[i + 1] += x[i] / 10 , x[i] %= 10;
    // RREP(i , n , 0) if(x[i] || i == 0){
    //     RREP(j , i , 0) cout << x[j] ;
    //     return cout << endl , 0;
    // }