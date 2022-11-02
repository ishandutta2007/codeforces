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
#define MAX 200000
#define INF 0x3f3f3f3f

int n , a , b , c , x[MAX] , ans = -4e18 - 87;
PII l[MAX] , r[MAX];
int32_t main(){
    cin >> n >> a >> b >> c;
    REP(i , 1 , n + 1) cin >> x[i];
    l[1] = mp(x[1] , x[1]);
    r[n] = mp(x[n] , x[n]);
    REP(i , 2 , n + 1){
        l[i].A = min(l[i - 1].A , x[i]);
        l[i].B = max(l[i - 1].B , x[i]);
    }
    RREP(i , n - 1 , 1){
        r[i].A = min(r[i + 1].A , x[i]);
        r[i].B = max(r[i + 1].B , x[i]);
    }
    REP(i , 1 , n + 1){
        ans = max(ans , a * l[i].A + b * x[i] + c * r[i].A);
        ans = max(ans , a * l[i].B + b * x[i] + c * r[i].A);
        ans = max(ans , a * l[i].A + b * x[i] + c * r[i].B);
        ans = max(ans , a * l[i].B + b * x[i] + c * r[i].B);
    }
    cout << ans << endl;
    return 0;
}