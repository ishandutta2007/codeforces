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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , m , k;
int a[MAX] , b[MAX];
vector<int> v;
int query(int now){
    int ans = 1e17;
    int fr = lower_bound(ALL(v) , -now) - v.begin();
    if(fr != 0) ans = min(abs(ans) , abs(v[fr - 1] + now));
    if(fr != v.size()) ans = min(abs(ans) , abs(v[fr] + now));
    return ans;
}
int32_t main(){
    IOS;
    cin >> n >> m >> k;
    REP(i , 1 , n + 1) cin >> a[i];
    REP(i , 1 , m + 1) cin >> b[i];
    int po = 1 , now = 0 , ba = -1;
    REP(i , 1 , n) now += b[i] * ba , ba *= -1;
    REP(i , n , m + 1){
        now += b[i] * ba;
        v.pb(now);
        // DBGG("pb = " , now);
        now = -now;
        now -= b[po ++];
    }
    sort(ALL(v));
    int tmp = 1 , val = 0;
    REP(i , 1 , n + 1){
        val += a[i] * tmp , tmp *= -1;
    }

    // REP(i , 0 , v.size()) cout << v[i] << " " ; cout << endl;

    cout << query(val) << endl;
    REP(i , 0 , k){
        int l , r , vv , tma , tmb;
        cin >> l >> r >> vv;
        tma = (l % 2 == 0) ? l : l - 1;
        tmb = (r % 2 == 0) ? r - 1 : r;
        val += (tmb - tma + 1) / 2 * vv;

        tma = (l % 2 == 0) ? l : l + 1;
        tmb = (r % 2 == 0) ? r + 1 : r;
        val -= (tmb - tma + 1) / 2 * vv;
        cout << query(val) << endl;
    }
    return 0;
}