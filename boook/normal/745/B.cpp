/*input
2 3
XXX
XXX
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
#define MAX 1000
#define INF 0x3f3f3f3f

int l = INF , r , x = INF , y;
int n , m;
string s[MAX];
int32_t main(){
    cin >> n >> m;
    REP(i , 0 , n){
        cin >> s[i];
    }
    int cnt = 0;
    REP(i , 0 , n) REP(j , 0 , m){
        if(s[i][j] == 'X'){
            cnt ++;
            l = min(l , i);
            r = max(r , i);
            x = min(x , j);
            y = max(y , j);
        }
    }
    // DB4(l , r , x , y);
    int tma = r - l + 1;
    int tmb = y - x + 1;
    if(tma * tmb == cnt) cout << "YES" << endl;
    else cout << "NO" << endl;  
    return 0;
}