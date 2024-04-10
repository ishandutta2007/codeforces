/*input
110
2
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
#define MAX 100090
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int mm[MAX] , ni[MAX] , k , one[MAX] , dis[MAX];
string s;
int C(int a , int b){
    if(a < b) return 0;
    else return mm[a] * ni[b] % mod * ni[a - b] % mod;
}
int solve(int sum){
    int cnt = sum , ans = 0 , las = s.size();
    int tmp = 0;
    REP(i , 0 , s.size()) tmp += s[i] == '1';
    if(tmp == sum) ans ++;
    REP(i , 0 , s.size()){
        las --;
        if(cnt == -1) break;
        if(s[i] == '1'){
            ans = (ans + C(las , cnt)) % mod;
            cnt --;
        }
    }
    return ans;
}
int32_t main(){
    IOS;
    mm[0] = ni[0] = ni[1] = 1;
    REP(i , 1 , MAX) mm[i] = mm[i - 1] * i % mod;
    REP(i , 2 , MAX) ni[i] = ni[mod % i] * (mod - mod / i) % mod;
    REP(i , 1 , MAX) ni[i] = ni[i] * ni[i - 1] % mod;

    REP(i , 1 , MAX){
        if(i % 2 == 0) one[i] = one[i >> 1];
        if(i % 2 == 1) one[i] = one[i >> 1] + 1;
    }
    REP(i , 2 , MAX){
        dis[i] = dis[one[i]] + 1;
    }
    cin >> s >> k;
    if(k == 0) return cout << 1 << endl , 0;
    int ans = 0;
    REP(i , 1 , s.size() + 1){
        if(dis[i] == k - 1){
            // DBGG("here = " , i);
            ans = (ans + solve(i)) % mod;
        }
    }
    if(k - 1 == 0) ans --;
    cout << ans << endl;
    return 0;
}