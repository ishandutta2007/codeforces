/*input
10
2 1 3 3 3 3 1 3 1 1
10
4 8
2 10
1 10
4 4
1 3
2 4
6 7
1 9
2 5
1 1
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
#define MAX 100900
#define INF 0x3f3f3f3f
#define mid ((l + r) >> 1)
#define ls (now << 1)
#define rs (now << 1 | 1)

int bit[MAX];
void update(int from , int val){
    for(int i = from + 10 ; i < MAX ; i += i & -i) bit[i] += val;
}
int query(int from){
    int cnt = 0;
    for(int i = from + 10 ; i > 0 ; i -= i & -i) cnt += bit[i];
    return cnt;
}
int query(int l , int r){ return query(r) - query(l - 1); }
int n , m;
int x[MAX] , fr[MAX] , ba[MAX] , help[MAX] , ss[MAX];
int ql[MAX] , qr[MAX] , ans[MAX];
vector<int> sol[MAX];
int sml[MAX * 4];
void update(int now , int l , int r , int k , int val){
    if(l == r) sml[now] = val;
    else{
        if(k <= mid + 0) update(ls , l , mid + 0 , k , val);
        if(mid + 1 <= k) update(rs , mid + 1 , r , k , val);
        sml[now] = min(sml[ls] , sml[rs]);
    }
}
int query(int now , int l , int r , int ql , int qr){
    if(ql <= l && r <= qr) return sml[now];
    if(qr <= mid + 0) return query(ls , l , mid + 0 , ql , qr);
    if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr);
    return min(query(ls , l , mid + 0 , ql , qr) , query(rs , mid + 1 , r , ql , qr));
}
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];

    fill(help , help + MAX , 0);
    REP(i , 1 , n + 1) fr[i] = help[x[i]] , help[x[i]] = i;
    fill(help , help + MAX , n + 1);
    RREP(i , n , 1)    ba[i] = help[x[i]] , help[x[i]] = i;

    // REP(i , 1 , n + 1) cout << fr[i] << " " ; cout << endl;
    // REP(i , 1 , n + 1) cout << ba[i] << " " ; cout << endl;

    REP(i , 1 , n + 1){
        if(ba[i] - i != i - fr[i]) ss[ba[i]] = fr[i];
        if(ba[i] - i == i - fr[i]) ss[ba[i]] = ss[i];
    }
    // REP(i , 1 , n + 1) cout << ss[i] << " " ; cout << endl;
    cin >> m;
    REP(i , 1 , m + 1) cin >> ql[i] >> qr[i];
    REP(i , 1 , m + 1) sol[qr[i]].pb(i);

    REP(i , 1 , n + 1) update(1 , 0 , n , i , n + 1);
    REP(i , 1 , n + 1){
        update(i , 1);
        update(fr[i] , -1);
        update(1 , 0 , n , i , ss[i]);
        update(1 , 0 , n , fr[i] , n + 1);
        for(auto to : sol[i]) ans[to] = query(ql[to] , qr[to]);
        for(auto to : sol[i]) 
            if(ql[to] <= query(1 , 0 , n , ql[to] , qr[to])) ans[to] ++;
    }
    REP(i , 1 , m + 1) cout << ans[i] << endl;
    return 0;
}