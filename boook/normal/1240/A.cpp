/*input
4
1
100
50 1
49 1
100
8
100 200 100 200 100 200 100 100
10 2
15 3
107
3
1000000000 1000000000 1000000000
50 1
50 1
3000000000
5
200 100 100 100 100
69 5
31 2
90
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)  for(int i = j ; i < k ; ++i)
#define RREP(i,j,k) for(int i = j ; i >=k ; --i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i,j) memset(i , j , sizeof i)
#define ALL(i)   i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 300000
#define INF 0x3f3f3f3f

int t , n , p[MAX] , x , a , y , b , v[MAX] , goal;

int judge(int nn){
    REP(i , 1 , nn + 1) v[i] = 0;
    REP(i , 1 , nn + 1) if(i % a == 0) v[i] += x;
    REP(i , 1 , nn + 1) if(i % b == 0) v[i] += y;
    
    sort(v + 1 , v + 1 + nn , greater<int>());

    int sum = 0;
    REP(i , 1 , nn + 1) sum += v[i] * p[i];

    
    return sum >= goal;
}
int32_t main(){
    IOS;
    cin >> t;
    REP(times , 0 , t){
        cin >> n;
        REP(i , 1 , n + 1) cin >> p[i] , p[i] /= 100;
        cin >> x >> a >> y >> b >> goal;

        sort(p + 1 , p + 1 + n , greater<int>());
        int ans = 0;
        RREP(i , 20 , 0){
            int to = ans + (1 << i);
            if(to <= n && judge(to) == 0) ans = to;
        }ans ++;

        if(ans > n) cout << -1 << endl;
        else cout << ans << endl;

        // REP(i , 1 , n + 1) cout << v[i] << " "; cout << endl;
        // REP(i , 1 , n + 1) cout << p[i] << " "; cout << endl;
        // REP(i , 1 , n + 1) cout << p[i] * v[i] / 100 << " "; cout << endl;

    }
    return 0;
}