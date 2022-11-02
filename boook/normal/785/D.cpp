/*input
)))
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
#define MAX 300000
#define INF 0x3f3f3f3f
#define mod 1000000007LL

string s;
int m[MAX] , ni[MAX];
int fr[MAX] , ba[MAX];
int C(int a , int b){
    return m[a] * ni[b] % mod * ni[a - b] % mod;
}
int32_t main(){
    m[0] = ni[0] = ni[1] = 1;
    REP(i , 1 , MAX) m[i] = m[i - 1] * i % mod;
    REP(i , 2 , MAX) ni[i] = ni[mod % i] * (mod - mod / i) % mod;
    REP(i , 2 , MAX) ni[i] = ni[i] * ni[i - 1] % mod;

    cin >> s;
    REP(i , 1 , s.size() + 1){
        fr[i] = fr[i - 1] + (s[i - 1] == '(');
    }
    RREP(i , s.size() , 1){
        ba[i] = ba[i + 1] + (s[i - 1] == ')');
    }
    int ans = 0;
    REP(i , 1 , s.size() + 1){
        if(s[i - 1] == '('){
            int l = fr[i] , r = ba[i];
            if(r) ans = (ans + C(l + r - 1 , r - 1)) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}