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
#define N 1000000000900LL
#define mid ((l + r) >> 1)


int b[MAX * 45] , ls[MAX * 45] , rs[MAX * 45] , po = 2;
int n , x[MAX][2] , ans = 0;
double PI = acos(-1);
void update(int now , int l , int r , int k , int val){
    if(l == k && r == k){
        b[now] = max(b[now] , val);
        ans = max(ans , b[now]);
    }
    else {
        if(k <= mid){
            if(ls[now] == 0) ls[now] = po ++;
            update(ls[now] , l , mid , k , val);
        }
        else if(mid + 1 <= k){
            if(rs[now] == 0) rs[now] = po ++;
            update(rs[now] , mid + 1 , r , k , val);
        }
        b[now] = max(b[ls[now]] , b[rs[now]]);
    }
}
int query(int now , int l , int r , int ql , int qr){
    if(ql <= l && r <= qr) return b[now];
    int big = 0;
    if(ql <= mid && ls[now]) big = max(big , query(ls[now] , l , mid , ql , qr));
    if(mid + 1 <= qr && rs[now]) big = max(big , query(rs[now] , mid + 1 , r , ql , qr));
    return big;
}
int32_t main(){
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i][0] >> x[i][1];
    REP(i , 1 , n + 1){
        int val = x[i][0] * x[i][0] * x[i][1];
        int tmp = query(1 , 1 , N , 1 , val - 1);
        update(1 , 1 , N , val , tmp + val);
    }
    double v = (long double)ans * PI;
    printf("%.011f\n", v);
    return 0;
}