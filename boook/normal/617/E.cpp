/*input
5 3 1
1 1 1 1 1
1 5
2 4
1 3
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
#define MAX 3000000
#define INF 0x3f3f3f3f
#define N 320

int n , m , k , x[MAX] , ql[MAX] , qr[MAX] , sol[MAX];
int res = 0 , use[MAX] , ans[MAX];
PII T(int idx){
    return mp(ql[idx] / N , (ql[idx] / N & 1) ? qr[idx] : -qr[idx]);
}
int cmp(int a , int b){
    return T(a) < T(b);
}
void ADD(int now){
    res += use[now ^ k];
    use[now] ++;
}
void STR(int now){
    use[now] --;
    res -= use[now ^ k];
}
int32_t main(){
    IOS;
    cin >> n >> m >> k;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 1) x[i] ^= x[i - 1];
    REP(i , 1 , m + 1) cin >> ql[i] >> qr[i];
    REP(i , 1 , m + 1) ql[i] --;
    REP(i , 1 , m + 1) sol[i] = i;
    sort(sol + 1 , sol + 1 + m , cmp);
    int l = 0 , r = -1;
    REP(t , 1 , m + 1){
        int i = sol[t];
        while(r < qr[i]) ADD(x[++ r]);
        while(ql[i] < l) ADD(x[-- l]);
        while(l < ql[i]) STR(x[l ++]);
        while(qr[i] < r) STR(x[r --]);
        ans[i] = res;
    }
    REP(i , 1 , m + 1) cout << ans[i] << endl;
    return 0;
}