/*input
4 7 2 3 9
1 2 3 4
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
#define int long long
#define MAX 200900
#define INF 100000000000000LL

int n , l , r , ql , qr , x[MAX] , pre[MAX];

int32_t main(){
    IOS;
    cin >> n >> l >> r >> ql >> qr;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 1) pre[i] = pre[i - 1] + x[i]; 
    int ans = INF;
    REP(i , 0 , n + 1){
        int lth = i , rth = n - i;
        int val = pre[i] * l + (pre[n] - pre[i]) * r;
        if(lth == rth);
        else if(lth > rth){
            int tmp = lth - rth - 1;
            val += tmp * ql;
        }
        else if(rth > lth){
            int tmp = rth - lth - 1;
            val += tmp * qr;
        }
        ans = min(ans , val);
    }
    cout << ans << endl;
    return 0;
}