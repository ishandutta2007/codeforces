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
#define MAX (1 << 19)
#define INF 0x3f3f3f3f
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid ((l + r) >> 1)

int n , N , m;
int sum[MAX * 4] , x[MAX];
int Build(int now , int l , int r , int deep){
    if(l == r) sum[now] = x[l];
    else {
        Build(ls , l , mid + 0 , deep + 1);
        Build(rs , mid + 1 , r , deep + 1);
        if(deep % 2 == n % 2) sum[now] = sum[ls] ^ sum[rs];
        if(deep % 2 != n % 2) sum[now] = sum[ls] | sum[rs];
    }
}
int update(int now , int l , int r , int k , int val , int deep){
    if(l == r) sum[now] = val;
    else {
        if(k <= mid + 0) update(ls , l , mid + 0 , k , val , deep + 1);
        if(mid + 1 <= k) update(rs , mid + 1 , r , k , val , deep + 1);
        if(deep % 2 == n % 2) sum[now] = sum[ls] ^ sum[rs];
        if(deep % 2 != n % 2) sum[now] = sum[ls] | sum[rs];
    }
}
int32_t main(){
    IOS , cin >> n >> m;
    N = (1 << n);
    REP(i , 1 , N + 1) cin >> x[i];
    Build(1 , 1 , N , 0);
    REP(i , 1 , m + 1){
        int a , b;
        cin >> a >> b;
        update(1 , 1 , N , a , b , 0);
        cout << sum[1] << endl;
    }
    return 0;
}