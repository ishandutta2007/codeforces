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
#define MAX 100900
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int n , m;
string s;
int ppow(int now , int k){
    if(k == 0) return 1;
    if(k == 1) return now;
    if(k & 1) return ppow(now * now % mod , (k >> 1)) * now % mod;
    return ppow(now * now % mod , (k >> 1));
}
int cc[MAX] , mm[MAX];
void pre(){
    cc[0] = 1;
    REP(i , 1 , MAX) cc[i] = cc[i - 1] * i % mod;
    REP(i , 0 , MAX) mm[i] = ppow(cc[i] , mod - 2);
}
int C(int a , int b){
    if(b < 0 || b > a) return 0;
    return cc[a] * mm[b] % mod * mm[a - b] % mod;
}
int32_t main(){
    pre();
    cin >> n >> m;
    cin >> s;
    int tmp = 0 , po = n - 2 , ans = 0 , pp = 1;
    int qq = n - 1 , ww = 1;
    RREP(i , n - 1 , 0){
        ans = (ans + C(qq-- , m) * (s[i] - '0') * ww) % mod;
        ww = ww * 10 % mod;
    }
    RREP(i , n - 2 , 0){
        tmp = (tmp + C(po-- , m - 1) * pp) % mod , pp = pp * 10 % mod;
        // DBGG("tmp = " , tmp);
        ans = (ans + tmp * (s[i] - '0')) % mod;
        // DBGG("ans = " , ans);
    }
    cout << ans << endl;
    return 0;
}