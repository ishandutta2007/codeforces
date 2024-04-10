/*input
6 11
1 2
2 5
5 4
1 6
1 3
0 3 1 3
0 3 4 5
0 2 1 4
0 1 5 5
0 4 6 2
1 1
1 2
1 3
1 4
1 5
1 6
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
    for(int i = from + 10 ; i < MAX ; i += i & -i)
        bit[i] += val;
}
int query(int from){
    int res = 0;
    for(int i = from + 10 ; i > 0 ; i -= i & -i)
        res += bit[i];
    return res;
}
int query(int l , int r){
    return query(r) - query(l - 1);
}
int sum[MAX * 4] , tag[MAX * 4];
void Push(int now , int l , int r){
    if(tag[now] && l != r){
        tag[ls] += tag[now];
        sum[ls] += tag[now];
        tag[rs] += tag[now];
        sum[rs] += tag[now];
        tag[now] = 0;
    }
}
void update(int now , int l , int r , int ql , int qr , int add){
    Push(now , l , r);
    if(ql <= l && r <= qr){
        sum[now] += add;
        tag[now] += add;
    }
    else{
        if(ql <= mid + 0) update(ls , l , mid + 0 , ql , qr , add);
        if(mid + 1 <= qr) update(rs , mid + 1 , r , ql , qr , add);
        sum[now] = sum[ls] , sum[rs];
    }
}
int query(int now , int l , int r , int k){
    Push(now , l , r);
    if(l == k && r == k) return sum[now];
    if(k <= mid + 0) return query(ls , l , mid + 0 , k);
    if(mid + 1 <= k) return query(rs , mid + 1 , r , k);
}
vector<int> v[MAX];
int n , m , dep[MAX] , id[MAX] , h[MAX] , rt[MAX] , po = 1;

void DFS(int now , int fa , int deep , int root){
    rt[now] = root;
    h[now] = po;
    id[now] = po ++;
    dep[now] = deep;
    for(auto to : v[now]){
        if(to == fa) continue;
        DFS(to , now , deep + 1 , root);
        h[now] = max(h[now] , h[to]);
    }
}
int32_t main(){
    cin >> n >> m;
    REP(i , 1 , n){
        int a , b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    for(auto to : v[1]){
        DFS(to , 1 , 1 , to);
    }
    REP(i , 1 , m + 1){
        int ty , dot , add , d;
        cin >> ty;
        if(ty == 0){
            cin >> dot >> add >> d;
            int l = max(id[rt[dot]] , id[dot] - d);
            int r = min(h[dot] , id[dot] + d);
            if(dot != 1) update(1 , 1 , po , l , r , add);
            if(dep[dot] <= d){
                int ql = id[rt[dot]];
                int qr = min(h[dot] , ql + d - dep[dot] - 1);
                if(dot != 1 && ql <= qr) update(1 , 1 , po , ql , qr , -add);
                update(d - dep[dot] , add);
            }
        }
        else {
            cin >> dot;
            if(dot == 1) cout << query(dep[dot] , n) << endl;
            else {
                cout << query(1 , 1 , po , id[dot]) + query(dep[dot] , n) << endl;
            }
        }
    }
    return 0;
}