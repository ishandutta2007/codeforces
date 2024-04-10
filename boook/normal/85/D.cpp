/*input
14
add 1
add 7
add 2
add 5
sum
add 6
add 8
add 9
add 3
add 4
add 10
sum
del 1
sum
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
#define MAX 100900
#define INF 0x3f3f3f3f
#define mid ((l + r) >> 1)

struct N{ int siz , sum[5]; } st[MAX * 40];
int ls[MAX * 40] , rs[MAX * 40] , po = 2;
N Pull(N a , N b){
    N res;
    res.siz = a.siz + b.siz;
    REP(i , 0 , 5){
        res.sum[(i + a.siz) % 5] = a.sum[(i + a.siz) % 5] + b.sum[i];
    }
    return res;
}
void update(int now , int l , int r , int k , int val){
    if(l == k && r == k){
        if(val == 1) st[now].sum[0] = k;
        if(val != 1) st[now].sum[0] = 0;
        st[now].siz += val;
    }
    else {
        if(k <= mid + 0 && ls[now] == 0) ls[now] = po ++;
        if(k <= mid + 0) update(ls[now] , l , mid + 0 , k , val);

        if(mid + 1 <= k && rs[now] == 0) rs[now] = po ++;
        if(mid + 1 <= k) update(rs[now] , mid + 1 , r , k , val);

        st[now] = Pull(st[ls[now]] , st[rs[now]]);
    }
}
int n , x , N = 1e9 + 10;
string s;
int32_t main(){
    cin >> n;
    REP(i , 1 , n + 1){
        cin >> s;
        if(s == "add") cin >> x , update(1 , 1 , N , x ,  1);
        if(s == "del") cin >> x , update(1 , 1 , N , x , -1);
        if(s == "sum") cout << st[1].sum[2] << endl;
    }
    return 0;
}