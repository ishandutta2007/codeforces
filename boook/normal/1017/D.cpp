/*input
1 2 4
100
0
1
0 0
0 100
1 0
1 100
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
#define MAX 100000
#define INF 0x3f3f3f3f

int n , m , k;
int w[5050] , c[5050] , v[5050] , cnt[5050][110];

int32_t main(){
    IOS;
    cin >> n >> m >> k;
    REP(i , 0 , n) cin >> w[i];
    REP(i , 0 , m){
        string s; cin >> s;
        int val = 0;
        RREP(j , s.size() - 1 , 0) val = val * 2 + s[j] - '0';
        c[val] ++;
    }
    REP(i , 0 , (1 << n)){
        REP(j , 0 , n){
            if((i & (1 << j)) == 0) v[i] += w[j];
        }
    }
    // REP(i , 0 , (1 << n)) cout << v[i] << " "; cout << endl;
    REP(i , 0 , (1 << n)){
        REP(j , 0 , (1 << n)){
            if(v[i ^ j] <= 100) cnt[i][v[i ^ j]] += c[j];
        }
    }
    REP(i , 0 , k){
        int val = 0 , vvv , ans = 0;
        string s; cin >> s >> vvv;

        RREP(j , s.size() - 1 , 0) val = val * 2 + s[j] - '0';
        RREP(j , vvv , 0) ans += cnt[val][j];
        cout << ans << endl;
    }
    return 0;
}