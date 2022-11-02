/*input
2
5 2 3
6 4 5
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
#define MAX 
#define INF 0x3f3f3f3f

int t , n , l , r;
int32_t main(){
    cin >> t;
    REP(times , 0 , t){
        cin >> n >> l >> r;
        int now = 0;
        RREP(i , 30 , 0){
            int to = now + (1 << i);
            if(to * r < n) now = to;
        }
        now ++;
        int len = (r - l) * now;
        // DBGG("now = " , now);
        if(now * r - len <= n && n <= now * r){
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
    return 0;
}