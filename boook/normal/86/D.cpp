/*input
3 2
1 2 1
1 2
1 3
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
#define MAX 1000009
#define INF 0x3f3f3f3f
#define N 480

int cnt[MAX];
int n , m , x[MAX] , ql[MAX] , qr[MAX] , sol[MAX] , ans[MAX] , ret = 0;
void solve(int val , int add){
    ret -= cnt[val] * cnt[val] * val;
    cnt[val] += add;
    ret += cnt[val] * cnt[val] * val;
}
int cmp(int a , int b){
    return mp(ql[a] / N , qr[a]) < mp(ql[b] / N , qr[b]);
}
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , m + 1) cin >> ql[i] >> qr[i];
    REP(i , 1 , m + 1) sol[i] = i;
    sort(sol + 1 , sol + 1 + m , cmp);
    int l = 1 , r = 0;
    REP(idx , 1 , m + 1){
        int i = sol[idx];
        while(l < ql[i]) solve(x[l] , -1) , l ++; 
        while(qr[i] < r) solve(x[r] , -1) , r --;
        while(ql[i] < l) l -- , solve(x[l] , 1);
        while(r < qr[i]) r ++ , solve(x[r] , 1);
        ans[i] = ret;
    }
    REP(i , 1 , m + 1) cout << ans[i] << endl;
    return 0;
}