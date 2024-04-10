#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(unsigned i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(unsigned i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
// #define DBGG(i,j)     cout << i << " " << j << endl
// #define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 100090
#define INF 0x3f3f3f3f

int n , m , x[MAX] , ll[MAX] , rr[MAX] , val[MAX];
class djs{
public:
    int x[MAX] , l[MAX] , r[MAX] , siz[MAX];
    void init(){ REP(i , 0 , MAX) x[i] = l[i] = r[i] = i , siz[i] = 1; }
    int Find(int now){ return x[now] == now ? now : x[now] = Find(x[now]); }
    void Union(int a , int b){
        a = Find(a) , b = Find(b);
        if(siz[a] > siz[b]) swap(a , b);
        x[a] = b;
        siz[b] += siz[a];
        l[b] = min(l[b] , l[a]);
        r[b] = max(r[b] , r[a]);
    }
    int operator[](int now){ return Find(now); }
}ds;
int cmp(int a , int b){
    if(val[a] != val[b]) return val[a] < val[b];
    return a > b;
}
int sol[MAX];
int32_t main(){
    IOS;
    ds.init();
    cin >> n >> m;
    REP(i , 0 , n) cin >> x[i]; 
    REP(i , 0 , n - 1){
        val[i] = abs(x[i] - x[i + 1]);
        sol[i] = i;
    }
    sort(sol , sol + n - 1 , cmp);
    REP(i , 0 , n - 1){
        int now = sol[i];
        int L = ds.l[ds[now]] - 1 , R = ds.r[ds[now]] + 1;
        while(L >= 0 && val[now] > val[L]){
            ds.Union(now , L);
            L = ds.l[ds[now]] - 1;
        }
        while(R < n - 1 && val[now] >= val[R]){
            ds.Union(now , R);
            R = ds.r[ds[now]] + 1;
        }
        ll[now] = ds.l[ds[now]];
        rr[now] = ds.r[ds[now]];
    }
    // REP(i , 0 , n - 1) cout << val[i] << " " ; cout << endl;
    // REP(i , 0 , n - 1) cout << ll[i] << " " ; cout << endl;
    // REP(i , 0 , n - 1) cout << rr[i] << " " ; cout << endl;
    REP(times , 0 , m){
        int q , w;
        long long ans = 0;
        cin >> q >> w;
        q -- , w-- , w --;
        REP(i , q , w + 1){
            int fr = max(q , ll[i]) , ba = min(w , rr[i]);
            // DB4("fr = " , fr , "ba = " , ba);
            long long tma = ba - i + 1 , tmb = i - fr + 1;
            ans += tma * tmb * val[i];
        }
        cout << ans << endl;
    }
    return 0;
}