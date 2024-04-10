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
// #define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 200900
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int n , cnt[MAX] , x[MAX] , pre[MAX + 10] , ba[MAX + 10];
int ppow(int now , int k){
    if(k == 0) return 1 % mod;
    if(k == 1) return now % mod;
    if(k % 2 == 0) return ppow(now * now % mod , k / 2);
    if(k % 2 == 1) return ppow(now * now % mod , k / 2) * now % mod;
}
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 0 , n) cin >> x[i] , cnt[x[i]] ++;

    int ans = 1 , sum = 0;
    REP(i , 0 , MAX){
        if(cnt[i] != 0) sum += cnt[i] + 1;
    }
    pre[0] = 1 , ba[MAX] = 1;
    REP(i , 1 , MAX) pre[i] = pre[i - 1] * (cnt[i] + 1) % (mod - 1);
    RREP(i , MAX - 1 , 0) ba[i] = ba[i + 1] * (cnt[i] + 1) % (mod - 1);

    REP(i , 0 , MAX){
        if(cnt[i] != 0){
            int res = (pre[i - 1] * ba[i + 1]) % (mod - 1);
            int tmp = 1 , tma = ((1 + cnt[i]) * cnt[i] / 2) % (mod - 1);
            // DBGG("res = " , res);
            tma *= res;
            ans = ans * ppow(i , tma) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}