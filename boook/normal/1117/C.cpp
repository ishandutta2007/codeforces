/*input
0 0
0 1
1
L
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i, j, k)  for(int i = j; i <  k; ++i)
#define RREP(i, j, k) for(int i = j; i >= k; --i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 
#define INF 0x3f3f3f3f

int a , aa , b , bb;
string s;
int judge(int val){
    int l = 0 , r = 0 , u = 0 , d = 0 , tmp = val;
    REP(i , 0 , s.size()){
        if(s[i] == 'L') l ++;
        if(s[i] == 'R') r ++;
        if(s[i] == 'U') u ++;
        if(s[i] == 'D') d ++;
    }
    l = l * (val / s.size());
    r = r * (val / s.size());
    d = d * (val / s.size());
    u = u * (val / s.size());
    val %= s.size();

    REP(i , 0 , val){
        if(s[i] == 'L') l ++;
        if(s[i] == 'R') r ++;
        if(s[i] == 'U') u ++;
        if(s[i] == 'D') d ++;
    }
    int xx = a + r - l;
    int yy = b + u - d;
    // cout << xx << " " << yy << endl;
    if(abs(xx - aa) + abs(yy - bb) <= tmp) return 1;
    return 0;
}
int32_t main(){
    IOS;
    cin >> a >> b >> aa >> bb;
    cin >> s >> s;
    int ans = 0 , ok = 0;
    // cout << judge(4) << endl;
    // return 0;
    RREP(i , 60 , 0){
        int to = ans + (1ll << i);
        if(judge(to) == 0) ans = to;
        else ok = 1;
    }
    if(ok == 0) cout << -1 << endl;
    else cout << ans + 1 << endl;
    return 0;
}