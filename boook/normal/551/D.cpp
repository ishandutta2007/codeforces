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
#define INF 0x3f3f3f3f
typedef pair<PII , PII> PIII;
int n , k , l , mod , npow , good;
PIII FF(PIII a , PIII b){
    PII q = mp((a.A.A * b.A.A + a.A.B * b.B.A) % mod , (a.A.A * b.A.B + a.A.B * b.B.B) % mod);
    PII w = mp((a.B.A * b.A.A + a.B.B * b.B.A) % mod , (a.B.A * b.A.B + a.B.B * b.B.B) % mod);
    return mp(q , w);
}
PIII ppow(PIII now , int kk){
    if(kk == 1) return now;
    if(kk % 2 == 0) return ppow(FF(now , now) , kk / 2);
    else return FF(ppow(FF(now , now) , kk / 2) , now);
}
int mypow(int now , int kk){
    if(kk == 1) return now % mod;
    else if(kk % 2 == 0) return mypow(now * now % mod , kk / 2);
    else if(kk % 2 == 1) return mypow(now * now % mod , kk / 2) * now % mod;
}
void pre(){
    PII a = mp(1 , 1) , aa = mp(1 , 0);
    PIII qq = mp(a , aa);
    qq = ppow(qq , n - 1);

    good = (qq.A.A + qq.A.B + qq.B.A + qq.B.B) % mod;
    npow = mypow(2 , n);
}
int32_t main(){
    cin >> n >> k >> l >> mod;
    int ans = 1 % mod;
    pre();
    bitset<64> now(k);
    if(l == 0){
        if(k == 0) cout << 1 % mod << endl;
        else cout << 0 % mod << endl;
        return 0;
    }
    REP(i , l , 64){
        if(now.test(i)){
            cout << 0 % mod << endl;
            return 0;
        }
    }
    REP(i , 0 , l){
        if(now.test(i) == 0) ans = ans * good % mod;
        if(now.test(i) == 1){
            int tmp = npow - good;
            tmp = (tmp % mod + mod) % mod;
            ans = ans * tmp % mod;
        }
    }
    cout << ans << endl;
    return 0;
}