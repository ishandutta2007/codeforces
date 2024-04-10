/*input
4 -1
-2 1 -2 3
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
#define MAX 200900
#define INF 0x3f3f3f3f

int bit[MAX];
void update(int from , int val){
    for(int i = from + 10 ; i < MAX ; i += i & -i)
        bit[i] += val;
}
int query(int from){
    int cnt = 0;
    for(int i = from + 10 ; i > 0 ; i -= i & -i)
        cnt += bit[i];
    return cnt;
}

int n , k , x[MAX] , p[MAX] , sol[MAX];
int cmp(int a , int b){
    return p[a] < p[b];
}
int32_t main(){
    IOS;
    cin >> n >> k;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 1) p[i] = p[i - 1] + x[i];
    REP(i , 0 , n + 1) sol[i] = i;
    sort(sol , sol + 1 + n , cmp);
    int pos = 0 , ans = 0;
    REP(i , 0 , n + 1) update(i , 1);
    REP(i , 0 , n + 1){
        int now = p[sol[i]];
        while(pos <= n && p[sol[i]] - p[sol[pos]] >= k){
            update(sol[pos] , -1);
            pos ++;
        }
        ans += query(sol[i] - 1);
        
        // REP(j , 0 , n + 1) cout << query(j) - query(j - 1) << " "; cout << endl;
    }
    cout << ans << endl;
    return 0;
}