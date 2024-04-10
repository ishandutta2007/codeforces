/*input
2 3
1 5 7
2 3 1
1 2
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
#define MAX 1010
#define INF 0x3f3f3f3f
#define mod 998244353

int n , m , x[MAX][MAX] , ans[MAX][MAX];
vector<int> uni;
vector<PII> sol[MAX * MAX];
int ppow(int a , int k){
    if(k == 0) return 1;
    if(k % 2 == 0) return ppow(a * a % mod , k >> 1);
    if(k % 2 == 1) return ppow(a * a % mod , k >> 1) * a % mod;
}
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) REP(j , 1 , m + 1) cin >> x[i][j] , uni.pb(x[i][j]);
    sort(ALL(uni));
    uni.resize(unique(ALL(uni)) - uni.begin());
    REP(i , 1 , n + 1) REP(j , 1 , m + 1)
        x[i][j] = lower_bound(ALL(uni) , x[i][j]) - uni.begin();
    REP(i , 1 , n + 1) REP(j , 1 , m + 1) sol[x[i][j]].pb(mp(i , j));

    int totsum = 0 , totcnt = 0;
    int totpinX = 0 , sumX = 0;
    int totpinY = 0 , sumY = 0;

    REP(i , 0 , uni.size()){
        for(auto idx : sol[i]){
            int tmp = totsum;
            tmp = (tmp + idx.A * idx.A % mod * totcnt) % mod;
            tmp = (tmp + totpinX) % mod;
            tmp = (tmp - 2 * idx.A * sumX) % mod;
            tmp = (tmp % mod + mod) % mod;

            tmp = (tmp + idx.B * idx.B % mod * totcnt) % mod;
            tmp = (tmp + totpinY) % mod;
            tmp = (tmp - 2 * idx.B * sumY) % mod;
            tmp = (tmp % mod + mod) % mod;

            tmp = tmp * ppow(totcnt , mod - 2) % mod;
            ans[idx.A][idx.B] = tmp;
        }
        for(auto idx : sol[i]){
            totsum = (totsum + ans[idx.A][idx.B]) % mod;
            totcnt = (totcnt + 1) % mod;
            sumX = (sumX + idx.A) % mod;
            sumY = (sumY + idx.B) % mod;
            totpinX = (totpinX + idx.A * idx.A) % mod;
            totpinY = (totpinY + idx.B * idx.B) % mod;
        }
    }

    int v1 , v2;
    cin >> v1 >> v2;
    cout << ans[v1][v2] << endl;
    return 0;
}