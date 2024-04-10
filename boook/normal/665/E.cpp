/*input
3 3
1 2 3
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
#define MAX 1000900
#define INF 0x3f3f3f3f

int n , m , x[MAX];
int b[MAX * 40] , ls[MAX * 40] , rs[MAX * 40] , po = 2;
void update(int now , int floor , int val){
    if(floor == -1) b[now] ++;
    else {
        if(val & (1 << floor)){
            if(rs[now] == 0) rs[now] = po ++;
            update(rs[now] , floor - 1 , val);
        }
        else {
            if(ls[now] == 0) ls[now] = po ++;
            update(ls[now] , floor - 1 , val);
        }
        b[now] = b[ls[now]] + b[rs[now]];
    }
}
int query(int now , int floor , int val){
    // DB4("query = " , now , floor , val);
    if(now == 0) return 0;
    if(floor == -1) return b[now];
    else {
        int ans = 0;
        if((m & (1 << floor)) == 0){
            if(val & (1 << floor)){
                 ans += b[ls[now]];
                 ans += query(rs[now] , floor - 1 , val);                
            }
            else{
                ans += b[rs[now]];
                ans += query(ls[now] , floor - 1 , val);
            }
        }
        else {
            if(val & (1 << floor)){
                ans += query(ls[now] , floor - 1 , val);                
            }
            else{
                ans += query(rs[now] , floor - 1 , val);
            }
        }
        return ans;
    }
}
// 0001010111 m
// 1111100111 val
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 1) x[i] = x[i] ^ x[i - 1];
    long long ans = 0;
    REP(i , 0 , n){
        update(1 , 30 , x[i]);
        ans += query(1 , 30 , x[i + 1]);
        // DBGG("now ans = " , ans);
    }
    cout << ans << endl;
    return 0;
}