/*input
4 2 4
1 1 1 1
1 1 1 1
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
#define MAX 200000
#define INF 0x3f3f3f3f

int n , l , r , a[MAX] , b[MAX];
vector<int> q , w;
int32_t main(){
    cin >> n >> l >> r;
    REP(i , 1 , n + 1) cin >> a[i];
    REP(i , 1 , n + 1) cin >> b[i];
    REP(i , 1 , n + 1){
        if(l <= i && i <= r){
            q.pb(a[i]);
            w.pb(b[i]);
        }else if(a[i] != b[i]){
            cout << "LIE" << endl;
            return 0;
        }
    }
    sort(ALL(q));
    sort(ALL(w));
    if(q == w) cout << "TRUTH" << endl;
    else cout << "LIE" << endl;
    return 0;
}