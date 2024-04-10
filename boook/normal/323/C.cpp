/*input
4
4 3 2 1
2 3 4 1
3
1 2 3 4
1 3 2 1
1 4 2 3
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
///-----------------------------------------------------------
#define MAX 1000090
#define INF 0x3f3f3f3f
#define mid ((l + r) >> 1)

int n , m , sum[MAX * 25] , ls[MAX * 25] , rs[MAX * 25] , po = 2;
int x[MAX] , y[MAX] , att[MAX] , root[MAX] , preans = -1;
int update(int dot , int l , int r , int k , int val){
    int now = po ++;
    sum[now] = sum[dot] , ls[now] = ls[dot] , rs[now] = rs[dot];
    if(l == r) return sum[now] += val , now;
    else {
        if(k <= mid + 0) ls[now] = update(ls[now] , l , mid + 0 , k , val);
        if(mid + 1 <= k) rs[now] = update(rs[now] , mid + 1 , r , k , val);
        return sum[now] = sum[ls[now]] + sum[rs[now]] , now;
    }
}
int query(int now , int l , int r , int ql , int qr){
    if((ql <= l && r <= qr) || now == 0) return sum[now];
    if(qr <= mid + 0) return query(ls[now] , l , mid + 0 , ql , qr);
    if(mid + 1 <= ql) return query(rs[now] , mid + 1 , r , ql , qr);
    return query(ls[now] , l , mid + 0 , ql , qr) + query(rs[now] , mid + 1 , r , ql , qr);
}
inline int rit(){
    char c = getchar();
    int res = 0;
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)){
        res = (res << 1) + (res << 3) + c - '0';
        c = getchar();
    }
    return res;
}
int32_t main(){
    n = rit();
    REP(i , 1 , n + 1) x[i] = rit();
    REP(i , 1 , n + 1) y[i] = rit();
    REP(i , 1 , n + 1) att[y[i]] = i;
    REP(i , 1 , n + 1) x[i] = att[x[i]];
    root[0] = 1;
    REP(i , 1 , n + 1) root[i] = update(root[i - 1] , 1 , n , x[i] , 1);
    m = rit();
    REP(i , 1 , m + 1){
        int l = rit() , r = rit() , a = rit() , b = rit();
        l = (l + preans) % n + 1 , r = (r + preans) % n + 1;
        a = (a + preans) % n + 1 , b = (b + preans) % n + 1;
        if(l > r) swap(l , r);
        if(a > b) swap(a , b);
        preans = query(root[r] , 1 , n , a , b) - query(root[l - 1] , 1 , n , a , b);
        printf("%d\n", preans);
    }
    return 0;
}