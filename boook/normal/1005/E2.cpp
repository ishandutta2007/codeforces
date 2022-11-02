/*input
15 2
1 2 3 1 2 3 1 2 3 1 2 3 1 2 3
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
#define MAX 600000
#define INF 0x3f3f3f3f

int N = 300000 , cnt[MAX] , now = N , sum = 0;
int n , m , x[MAX] , v[MAX] , p[MAX];
inline void update(int from , int val){
    from += N;
    if(from <= now) sum += val;
    cnt[from] += val;
}
inline int query(int from){
    from += N;
    while(from < now) sum -= cnt[now] , now --;
    while(now < from) now ++ , sum += cnt[now];
    return sum;
}
inline long long solve(int k){
    now = N , sum = 0 , MEM(cnt , 0);
    REP(i , 1 , n + 1) v[i] = x[i] <= k ? 1 : -1;
    REP(i , 1 , n + 1) p[i] = v[i] + p[i - 1];
    long long ans = 0;
    REP(i , 1 , n + 1){
        update(p[i - 1] , 1);
        ans += query(p[i]);
    }
    return ans;
}
int32_t main(){
    // IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> x[i];
    cout << solve(m) - solve(m - 1) << endl;
    return 0;
}