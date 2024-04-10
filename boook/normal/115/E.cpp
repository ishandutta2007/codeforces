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
#define MAX 200800
#define INF 0x3f3f3f3f
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid ((l + r) >> 1)

int big[MAX * 4] , tag[MAX * 4];
int n , m , x[MAX] , a[MAX][3] , dp[MAX];
vector<int> v[MAX];
void Push(int now , int l , int r){
    if(l != r && tag[now]){
        big[ls] += tag[now];
        big[rs] += tag[now];
        tag[ls] += tag[now];
        tag[rs] += tag[now];
        tag[now] = 0;
    }
}
void update(int now , int l , int r , int ql , int qr , int val){
    // DB4(now , l , ql , qr);
    Push(now , l , r);
    if(ql <= l && r <= qr){
        big[now] += val;
        tag[now] += val;
    }
    else {
        if(ql <= mid) update(ls , l , mid , ql , qr , val);
        if(mid + 1 <= qr) update(rs , mid + 1 , r , ql , qr , val);
        big[now] = max(big[ls] , big[rs]);
    }
}
int query(int now , int l , int r , int ql , int qr){
    Push(now , l , r);
    if(ql <= l && r <= qr) return big[now];
    else if(qr <= mid) return query(ls , l , mid , ql , qr);
    else if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr);
    return max(query(ls , l , mid , ql , qr) , query(rs , mid + 1 , r , ql , qr));
}
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> x[i] , x[i] += x[i - 1];
    REP(i , 1 , m + 1){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        v[a[i][1]].pb(i);
    }

    REP(i , 1 , n + 1){
        update(1 , 0 , n , i , i , x[i]);
    }
    REP(i , 1 , n + 1){
        for(auto to : v[i]){
            update(1 , 0 , n , 0 , a[to][0] - 1 , a[to][2]);
        }
        dp[i] = query(1 , 0 , n , 0 , i - 1) - x[i];
        // DB4("i = " , i , "query(i) = " , dp[i] - x[i]);
        dp[i] = max(dp[i] , dp[i - 1]);
        update(1 , 0 , n , i , i , dp[i]);
    }
    // REP(i , 1 , n + 1) cout << dp[i] << " " ; cout << endl;
    cout << dp[n] << endl;
    return 0;
}