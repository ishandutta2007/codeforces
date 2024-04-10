/*input
-3 5 9 4 2
0 6 4 10 9
-3 1 4 10 1
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
#define int long long
#define MAX 500090
#define INF 0x3f3f3f3f
#define mid ((l + r) >> 1)
#define ls (now << 1)
#define rs (now << 1 | 1) 

int n , x[MAX] , y[MAX];
int d[MAX] , m[MAX] , p[MAX] , r[MAX] , ok[MAX];
vector<int> uni , sol , sum[MAX];
int sml[MAX * 4];
void update(int now , int l , int r , int k , int id){
    if(l == k && r == k){
        sml[now] = min(sml[now] , m[id]);
        sum[l].pb(id);
    }
    else {
        if(k <= mid + 0) update(ls , l , mid + 0 , k , id);
        if(mid + 1 <= k) update(rs , mid + 1 , r , k , id);
        sml[now] = min(sml[ls] , sml[rs]);
    }
}
void query(int now , int l , int r , int ql , int qr , int power){
    if(ql <= l && r <= qr){
        if(l == r){
            sml[now] = INF;
            for(auto to : sum[l]) sol.pb(to);
            sum[l].clear();
        }
        else {
            if(sml[ls] <= power) query(ls , l , mid + 0 , ql , qr , power);
            if(sml[rs] <= power) query(rs , mid + 1 , r , ql , qr , power);
            sml[now] = min(sml[ls] , sml[rs]);
        }
    }
    else {
        if(ql <= mid + 0) query(ls , l , mid + 0 , ql , qr , power);
        if(mid + 1 <= qr) query(rs , mid + 1 , r , ql , qr , power);
        sml[now] = min(sml[ls] , sml[rs]);
    }
}
int32_t main(){
    IOS;
    cin >> x[0] >> y[0] >> p[0] >> r[0] >> n;
    REP(i , 1 , n + 1){
        cin >> x[i] >> y[i] >> m[i] >> p[i] >> r[i];
    }

    REP(i , 0 , n + 1){
        uni.pb((x[i] - x[0]) * (x[i] - x[0]) + (y[i] - y[0]) * (y[i] - y[0]));
        uni.pb(r[i] * r[i]);
    }
    sort(ALL(uni));
    uni.resize(unique(ALL(uni)) - uni.begin());
    REP(i , 0 , n + 1){
        int tmp = (x[i] - x[0]) * (x[i] - x[0]) + (y[i] - y[0]) * (y[i] - y[0]);
        d[i] = lower_bound(ALL(uni) , tmp) - uni.begin();
        r[i] = lower_bound(ALL(uni) , r[i] * r[i]) - uni.begin();
    }
    MEM(sml , INF);
    REP(i , 1 , n + 1){
        update(1 , 0 , uni.size() , d[i] , i);
    }
    sol.pb(0);
    while(sol.size()){
        int now = sol.back(); sol.pop_back();
        ok[now] = 1;
        query(1 , 0 , uni.size() , 0 , r[now] , p[now]);
    }

    int ans = 0;
    REP(i , 1 , n + 1) ans += ok[i];
    cout << ans << endl;
    return 0;
}