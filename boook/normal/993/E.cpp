/*input
6 99
-1 -1 -1 -1 -1 -1
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
// #define int long long
#define MAX (1 << 18) + 10
#define INF 0x3f3f3f3f
#define cplx complex<double>
const double PI = acos(-1);
#define mid ((l + r) >> 1)
#define N (1 << 18)

cplx T[MAX] , x[MAX] , y[MAX] , w[MAX] , I(0 , 1);
int nn , base , xx[MAX] , yy[MAX];
int n , m , val[MAX];
long long ans[MAX];

void FFT(cplx G[MAX]){
    int siz = 0 , pat = (nn >> 1) - 1;
    cplx *tmp = T , *now = G; 
    RREP(i , base - 1 , 0){
        REP(j , 0 , nn){
            int fr = j >> i , ba = j & pat;
            int a = ((fr & siz) << 1 | 0) , b = a | 1;
            tmp[j] = now[a << i | ba] + now[b << i | ba] * w[(fr << i) << (18 - base)];
        }
        swap(tmp , now);
        // REP(j , 0 , nn) now[j] = tmp[j];
        siz = (siz << 1 | 1) , pat >>= 1;
    }
    REP(i , 0 , nn) G[i] = now[i];
}
void IFFT(cplx now[MAX]){
    FFT(now) , reverse(now + 1 , now + nn);
    REP(i , 0 , nn) now[i] /= nn;
}
void solve(int l , int r){
    if(l == r) ans[val[l]] ++;
    else {
        solve(l , mid + 0);
        solve(mid + 1 , r);
    // DBGG(l , r);
    // DBGG("mid = " , mid);
        base = 0;
        while((1 << base) <= r - l + 1) base ++;
        nn = 1 << base;


        REP(i , 0 , nn) xx[i] = yy[i] = 0;

        int fr = 0 , ba = 0;
        RREP(i , mid , l) fr += val[i] , xx[fr] ++;
        REP( i , mid + 1 , r + 1) ba += val[i] , yy[ba] ++;

        REP(i , 0 , nn) x[i] = cplx(xx[i] , 0);
        REP(i , 0 , nn) y[i] = cplx(yy[i] , 0);

        if(nn <= 350){
            REP(i , 0 , nn) REP(j , 0 , nn) ans[i + j] += 1LL * xx[i] * yy[j];
        }
        else {
            FFT(x) , FFT(y);
            REP(i , 0 , nn) x[i] = x[i] * y[i];
            IFFT(x);
            REP(i , 0 , nn) ans[i] += (long long)(x[i].real() + 0.5);
        }
    }
}
inline int rit(){
    int res = 0 , val = 0;
    char c = getchar();
    while(!isdigit(c)){
        if(c == '-') val = 1;
        c = getchar();
    }
    while(isdigit(c)){
        res = (res << 1) + (res << 3) + (c & 15);
        c = getchar();
    }
    return val ? -res : res;
}
int32_t main(){
    // cin >> n >> m;
    // auto c = clock();
    n = rit() , m = rit();
    REP(i , 1 , n + 1) val[i] = rit() , val[i] = (val[i] < m) ? 1 : 0;
    
    REP(i , 0 , N) w[i] = exp(2 * PI * i / N * I);
    solve(1 , n);
    REP(i , 0 , n + 1) printf("%lld ", ans[i]); cout << endl;
    // cout << (double)(clock() - c)/CLOCKS_PER_SEC << endl;
    return 0;
}