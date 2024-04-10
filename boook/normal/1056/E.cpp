/*input
001
kokokokotlin
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
#define MAX 1000900
#define INF 0x3f3f3f3f
#define mod 1000000087LL

int ac , h[MAX] , p[MAX];
string s , t;
void solveinit(){
    ac = (rand() % 1000 + 7) * 38 + 1;
    h[0] = 1;
    REP(i , 1 , MAX) h[i] = h[i - 1] * ac % mod;
}
int query(int l , int r){
    l ++ , r ++;
    int v1 = p[r];
    int v2 = p[l - 1] * h[r - l + 1] % mod;
    return (v1 + mod - v2) % mod;
}
int32_t main(){
    IOS;
    cin >> s >> t;
    srand(time(NULL));
    solveinit();
    int v0 = 0 , v1 = 0;
    REP(i , 0 , s.size()){
        if(s[i] == '0') v0 ++;
        if(s[i] == '1') v1 ++;
    }
    REP(i , 0 , t.size()) p[i + 1] = (p[i] * ac + t[i]) % mod;
    // REP(i , 1 , t.size() + 1) cout << p[i] << " "; cout << endl;
    // cout << query(0 , 2) << endl;
    // DB4("v0 = " , v0 , "v1 = " , v1);
    int ans = 0;
    REP(len , 1 , t.size() + 1){
        if(((int)(t.size()) - v0 * len) % v1 == 0){
            int len0 = len , len1 = ((int)(t.size()) - v0 * len) / v1;
            if(len0 <= 0 || len1 <= 0) continue;
            int pos = 0 , pre0 = -1 , pre1 = -1 , ok = 1;
            REP(i , 0 , s.size()){
                if(s[i] == '0'){
                    int tmp = query(pos , pos + len0 - 1);
                    if(pre0 == -1) pre0 = tmp;
                    if(tmp != pre0) ok = 0;
                    pos += len0;
                }

                if(s[i] == '1'){
                    int tmp = query(pos , pos + len1 - 1);
                    if(pre1 == -1) pre1 = tmp;
                    if(tmp != pre1) ok = 0;
                    pos += len1;
                }
                if(ok == 0) break;
            }
            // if(ok) DB4("pre0 = " , pre0 , "pre1 = " , pre1);
            // if(ok) DB4("find = " , len0 , len1 , "");
            if(pre0 == pre1) ok = 0;
            ans += ok;
        }
    }
    cout << ans << endl;
    return 0;
}