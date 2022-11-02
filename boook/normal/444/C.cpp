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
#define MAX 100900
#define INF 0x3f3f3f3f
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid ((l + r) >> 1)

int n , m;
int sml[MAX * 4] , big[MAX * 4] , tag[MAX * 4] , add[MAX * 4] , val[MAX * 4];
inline void Pull(int now , int l , int r){
    sml[now] = min(sml[ls] , sml[rs]);
    big[now] = max(big[ls] , big[rs]);
    val[now] = val[ls] + val[rs];
}
inline void Build(int now , int l , int r){
    if(l == r){
        sml[now] = big[now] = l;
        tag[now] = val[now] = 0;
    }
    else {
        Build(ls , l , mid) , Build(rs , mid + 1 , r);
        Pull(now , l , r);
    }
}
inline int Push(int now , int l , int r){
    if(add[now] && l != r){
        val[ls] += add[now] * (mid - l + 1);
        val[rs] += add[now] * (r - (mid + 1) + 1);
        add[ls] += add[now];
        add[rs] += add[now];
        add[now] = 0;
    }
    if(tag[now] && l != r){
        sml[ls] = big[ls] = tag[ls] = tag[now];
        sml[rs] = big[rs] = tag[rs] = tag[now];
        tag[now] = 0;
    }
}
inline void update(int now , int l , int r , int ql , int qr , int v){
    Push(now , l , r);
    int siz = r - l + 1;
    if(ql <= l && r <= qr){
        if(sml[now] == big[now]){
            add[now] = abs(v - sml[now]);
            sml[now] = big[now] = tag[now] = v;
            val[now] += add[now] * (r - l + 1);
        }
        else {
            update(ls , l , mid + 0 , ql , qr , v);
            update(rs , mid + 1 , r , ql , qr , v);
            Pull(now , l , r);
            return;
        }
    }
    else{
        if(qr <= mid + 0)      update(ls , l , mid + 0 , ql , qr , v);
        else if(mid + 1 <= ql) update(rs , mid + 1 , r , ql , qr , v);
        else {
            update(ls , l , mid + 0 , ql , qr , v);
            update(rs , mid + 1 , r , ql , qr , v);
        }
        Pull(now , l , r);
    }
}
inline int query(int now , int l , int r , int ql , int qr){
    Push(now , l , r);
    if(ql <= l && r <= qr) return val[now];
    else if(qr <= mid + 0) return query(ls , l , mid + 0 , ql , qr);
    else if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr);
    return query(ls , l , mid + 0 , ql , qr) + query(rs , mid + 1 , r , ql , qr);
}
int32_t main(){
    IOS;
    cin >> n >> m;
    Build(1 , 1 , n);
    REP(i , 1 , m + 1){
        int ty , l , r , v;
        cin >> ty >> l >> r;
        if(ty == 1){
            cin >> v;
            update(1 , 1 , n , l , r , v);
        }
        else cout << query(1 , 1 , n , l , r) << endl;
    }
    return 0;
}