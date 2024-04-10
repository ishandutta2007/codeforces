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
#define MAX 200900
#define INF 0x3f3f3f3f
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid ((l + r) >> 1)

int big[MAX * 4];
int n , m , sol[MAX] , x[MAX] , t[MAX];
int eat[MAX];
multiset<PII> cc;
int cmp(int a , int b){
    return x[a] < x[b];
}
void build(int now , int l , int r){
    if(l == r) big[now] = x[sol[l]] + t[sol[l]];
    else {
        build(ls , l , mid);
        build(rs , mid + 1 , r);
        big[now] = max(big[ls] , big[rs]);
    }
}
void update(int now , int l , int r , int k){
    if(l == k && r == k) big[now] = x[sol[l]] + t[sol[l]];
    else{
        if(k <= mid) update(ls , l , mid , k);
        else update(rs , mid + 1 , r , k);
        big[now] = max(big[ls] , big[rs]);
    }
}
int query(int now , int l , int r , int ql , int qr , int k){
    if(ql <= l && r <= qr){
        if(big[now] < k) return n + 1;
        if(l == r) return l;
        if(big[ls] >= k) return query(ls , l , mid , ql , qr , k);
        else return query(rs , mid + 1 , r , ql , qr , k);
    }
    else if(qr <= mid) return query(ls , l , mid , ql , qr , k);
    else if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr , k);
    return min(query(ls , l , mid , ql , qr , k) , query(rs , mid + 1 , r , ql , qr , k));
}
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> x[i] >> t[i];
    REP(i , 1 , n + 1) sol[i] = i;
    sort(sol + 1 , sol + 1 + n , cmp);

    build(1 , 1 , n);
    REP(i , 1 , m + 1){
        int a , b , now = 0;
        cin >> a >> b;
        RREP(j , 20 , 0){
            int to = now + (1LL << j);
            if(to <= n && x[sol[to]] <= a) now = to;
        }
        if(now >= 1){
            int tmp = query(1 , 1 , n , 1 , now , a);
            if(tmp == n + 1) cc.insert(mp(a , b));
            else {
                int id = sol[tmp];
                eat[id] ++ , t[id] += b;
                while(cc.size()){
                    auto to = cc.upper_bound(mp(x[id] + t[id] + 1 , -1));
                    if(to == cc.begin()) break;
                    to --;
                    if((*to).A < x[id]) break;
                    eat[id] ++ , t[id] += (*to).B;
                    cc.erase(to);
                }
                update(1 , 1 , n , tmp);
            }
        }
    }

    REP(i , 1 , n + 1) cout << eat[i] << " " << t[i] << endl;
    return 0;
}