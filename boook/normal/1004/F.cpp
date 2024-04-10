/*input
4 8 7
0 3 6 1
2 1 4
2 3 4
1 1 7
2 1 4
2 1 3
2 1 1
1 3 0
2 1 4
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
#define MAX 100900
#define INF 0x3f3f3f3f
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid (l + r >> 1)

struct N{
    int val , sum;
    vector<PII> fr , ba;
} st[MAX * 4];
int n , m , k , x[MAX];
N pull(N a , N b){
    N ans;
    ans.sum = a.sum + b.sum;
    ans.val = a.val | b.val;
    ans.fr = a.fr;
    ans.ba = b.ba;
    for(auto v1 : a.ba) for(auto v2 : b.fr) if((v1.A | v2.A) >= k) ans.sum += v1.B * v2.B;

    for(auto to : b.fr){
        if((to.A | a.val) == ans.fr.back().A) ans.fr.back().B += to.B;
        else ans.fr.pb(to.A | a.val , to.B);
    }
    for(auto to : a.ba){
        if((to.A | b.val) == ans.ba.back().A) ans.ba.back().B += to.B;
        else ans.ba.pb(to.A | b.val , to.B);
    }
    return ans;
}
void build(int now , int l , int r){
    if(l == r){
        st[now].sum = x[l] >= k;
        st[now].val = x[l];
        st[now].fr.clear();
        st[now].ba.clear();
        st[now].fr.pb(x[l] , 1);
        st[now].ba.pb(x[l] , 1);
    }
    else {
        build(ls , l , mid + 0);
        build(rs , mid + 1 , r);
        st[now] = pull(st[ls] , st[rs]);
    }
}
void update(int now , int l , int r , int idx , int val){
    if(l == r){
        st[now].sum = val >= k;
        st[now].val = val;
        st[now].fr[0] = mp(val , 1);
        st[now].ba[0] = mp(val , 1);
    }
    else {
        if(idx <= mid + 0) update(ls , l , mid + 0 , idx , val);
        if(mid + 1 <= idx) update(rs , mid + 1 , r , idx , val);
        st[now] = pull(st[ls] , st[rs]);
    }
}
N query(int now , int l , int r , int ql , int qr){
    if(ql <= l && r <= qr) return st[now];
    else if(qr <= mid + 0) return query(ls , l , mid + 0 , ql , qr);
    else if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr);
    return pull(query(ls , l , mid + 0 , ql , qr) , query(rs , mid + 1 , r , ql , qr));
}
int32_t main(){
    IOS;
    cin >> n >> m >> k;
    REP(i , 1 , n + 1) cin >> x[i];
    build(1 , 1 , n);
    REP(i , 1 , m + 1){
        int ty , v1 , v2;
        cin >> ty >> v1 >> v2;
        if(ty == 1) update(1 , 1 , n , v1 , v2) , x[v1] = v2;
        if(ty == 2) cout << query(1 , 1 , n , v1 , v2).sum << endl;
    }
    return 0;
}