#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
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
#define mid ((l + r) >> 1)
#define ls (now << 1)
#define rs (now << 1 | 1)

int n , m , k;
int x[MAX] , dp[MAX] , b[MAX * 4];
void update(int now , int l , int r , int k , int v){
    if(l == k && r == k) { b[now] = v; return ;}
    else if(k <= mid) update(ls , l , mid , k , v);
    else update(rs , mid + 1 , r , k , v);
    b[now] = min(b[ls] , b[rs]);
}
int query(int now , int l , int r , int ql , int qr){
    if(ql <= l && r <= qr) return b[now];
    else if(qr <= mid) return query(ls , l , mid , ql , qr);
    else if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr);
    else return min(query(ls , l , mid , ql , qr) , query(rs , mid + 1 , r , ql , qr));
}
int32_t main(){
    IOS;
    cin >> n >> m >> k;
    REP(i , 1 , n + 1) cin >> x[i];

    dp[0] = 0;
    REP(i , 1 , n + 1) dp[i] = 1000000000000LL;
    MEM(dp , INF) , dp[0] = 0;
    REP(i , 0 , n + 1) update(1 , 0 , n , i , dp[i]);

    int l = 1;

    multiset<int> cc;
    REP(i , 1 , n + 1){
        // DBGG("now = " , i);
        cc.insert(x[i]);
        auto fr = cc.begin() , ba = cc.end(); ba--;
        int a = *fr , b = *ba;
        while(abs(b - x[i]) > m || abs(a - x[i]) > m){
            cc.erase(cc.find(x[l++]));
            fr = cc.begin() , ba = cc.end(); ba--;
            a = *fr , b = *ba;
        }
        if(cc.size() >= k && dp[l - 1] != -1){
            int ll = l - 1 , rr = i - k;
            dp[i] = min(dp[i] , query(1 , 0 , n , ll , rr) + 1);

            update(1 , 0 , n , i , dp[i]);
        }
        // DB4("dp[" , i , "] = " , dp[i]);
    }
    if(dp[n] > n + 10) dp[n] = -1;
    cout << dp[n] << endl;
    return 0;
}