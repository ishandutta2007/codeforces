/*input
4
1 2 4 12
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
// #define endl "\n"


///------------------------------------------------------------
#define int long long
#define MAX 100900
#define INF 0x3f3f3f3f

int sum[MAX * 50] , ls[MAX * 50] , rs[MAX * 50] , po = 2;
int n , x[MAX] , pre[MAX] , suf[MAX];
void update(int now , int floor , int val){
    if(floor == -1) sum[now] ++;
    else {
        if(ls[now] == 0) ls[now] = po ++;
        if(rs[now] == 0) rs[now] = po ++;
        if(val & (1LL << floor)) update(rs[now] , floor - 1 , val);
        else update(ls[now] , floor - 1 , val);
        sum[now] = sum[ls[now]] + sum[rs[now]];
    }
}
int query(int now , int floor , int val){
    if(ls[now] == 0) ls[now] = po ++;
    if(rs[now] == 0) rs[now] = po ++;
    if(floor == -1) return 0;
    else if(val & (1LL << floor)){
        if(sum[ls[now]]) return query(ls[now] , floor - 1 , val) + (1LL << floor);
        else return query(rs[now] , floor - 1 , val);
    }
    else {
        if(sum[rs[now]]) return query(rs[now] , floor - 1 , val) + (1LL << floor);
        else return query(ls[now] , floor - 1 , val);
    }
}
int32_t main(){
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    int ans = 0;
    REP(i , 1 , n + 1) pre[i] = pre[i - 1] ^ x[i];
    RREP(i , n , 1) suf[i] = suf[i + 1] ^ x[i];

    REP(i , 1 , n + 1) ans = max(ans , suf[i]);
    REP(i , 1 , n + 1) ans = max(ans , pre[i]);

    REP(i , 1 , n){
        update(1 , 45 , pre[i]);
        ans = max(ans , query(1 , 45 , suf[i + 1]));
    }

    cout << ans << endl;
    return 0;
}