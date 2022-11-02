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
#define MAX 5
#define INF 0x3f3f3f3f

int a[MAX] , b[MAX] , c[MAX];

int32_t main(){

    REP(i , 0 , 3) cin >> a[i];
    REP(i , 0 , 3) cin >> b[i];
    REP(i , 0 , 3) cin >> c[i];
    int ans = 100000000000000LL;

    REP(i , 0 , 110){
        REP(j , 0 , 40000){
            int val = i * c[2] + j * c[1];

            int q = a[1] + j , w = a[2] + i; // attack denfin
            if(q <= b[2]) continue;
            int dam = q - b[2] , tt;

            if(b[0] % dam == 0) tt = b[0] / dam;
            else tt = b[0] / dam + 1;

            int hur = max(0LL , b[1] - w) * tt;

            int tmp = a[0] - hur;
            if(tmp <= 0) val += (1 - tmp) * c[0];

            ans = min(ans , val);
        }
    }
    cout << ans << endl;
    return 0;
}