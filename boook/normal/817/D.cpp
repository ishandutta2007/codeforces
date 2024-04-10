/*input
3
1 4 1
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
#define MAX 2000000
#define INF 0x3f3f3f3f

int n , x[MAX] , l[MAX] , r[MAX];
int L(int id , int val){ return x[id] >  val ? id : L(l[id] , val); }
int R(int id , int val){ return x[id] >= val ? id : R(r[id] , val); }
int32_t main(){
    IOS;
    cin >> n;
    int ans = 0;

    x[0] = x[n + 1] = INF;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 1) l[i] = L(i - 1 , x[i]);
    RREP(i , n , 1)    r[i] = R(i + 1 , x[i]);
    REP(i , 1 , n + 1){
        int ll = l[i] + 1 , rr = r[i] - 1;
        ans += (rr - i + 1) * (i - ll + 1) * x[i];
    }
    REP(i , 1 , n + 1) x[i] = -x[i];
    REP(i , 1 , n + 1) l[i] = L(i - 1 , x[i]);
    RREP(i , n , 1)    r[i] = R(i + 1 , x[i]);
    REP(i , 1 , n + 1){
        int ll = l[i] + 1 , rr = r[i] - 1;
        ans += (rr - i + 1) * (i - ll + 1) * x[i];
    }
    cout << ans << endl;    
    return 0;
}