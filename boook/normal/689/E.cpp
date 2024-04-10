/*input
4 2
1 7
4 8
5 9
3 10
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
#define MAX 400900
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int bit[MAX];
void update(int from , int val){
    for(int i = from + 10 ; i < MAX ; i += i & -i)
        bit[i] += val;
}
int query(int from){
    int cnt = 0;
    for(int i = from + 10 ; i > 0 ; i -= i & -i)
        cnt += bit[i];
    return cnt;
}
int query(int ql , int qr){
    return query(qr) - query(ql - 1);
}
int m[MAX] , ni[MAX];
void solveinit(){
    m[0] = ni[0] = ni[1] = 1;
    REP(i , 1 , MAX) m[i] = m[i - 1] * i % mod;
    REP(i , 2 , MAX) ni[i] = ni[mod % i] * (mod - mod / i) % mod;
    REP(i , 2 , MAX) ni[i] = ni[i] * ni[i - 1] % mod;
}
int C(int a , int b){
    if(a < b) return 0;
    return m[a] * ni[b] % mod * ni[a - b] % mod;
}
int n , k , x[MAX][2] , sol[MAX];
vector<int> uni;
int cmp1(int a , int b){
    if(x[a][0] != x[b][0]) return x[a][0] < x[b][0];
    else return x[a][1] < x[b][1];
}
int cmp2(int a , int b){
    if(x[a][1] != x[b][1]) return x[a][1] > x[b][1];
    else return x[a][0] > x[b][0];
}
int32_t main(){

    solveinit();
    IOS;
    cin >> n >> k;
    REP(i , 0 , n) REP(j , 0 , 2) cin >> x[i][j];
    REP(i , 0 , n) x[i][1] ++;

    REP(i , 0 , n) REP(j , 0 , 2) uni.pb(x[i][j]);
    sort(ALL(uni));
    uni.resize(unique(ALL(uni)) - uni.begin());

    REP(i , 0 , n) REP(j , 0 , 2) 
        x[i][j] = lower_bound(ALL(uni) , x[i][j]) - uni.begin();

    REP(i , 0 , n) sol[i] = i;

    sort(sol , sol + n , cmp1);
    int ans = 0;
    REP(i , 0 , n){
        int id = sol[i];
        int sum = query(x[id][0] , uni.size());
        ans = (ans - C(sum , k - 1) * uni[x[id][0]] % mod + mod) % mod;
        ans = (ans + mod) % mod;
        update(x[id][1] , 1);
    }
    MEM(bit , 0);
    sort(sol , sol + n , cmp2);
    REP(i , 0 , n){
        int id = sol[i];
        int sum = query(x[id][1]);
        ans = (ans + C(sum , k - 1) * uni[x[id][1]] % mod + mod) % mod;
        update(x[id][0] , 1);
    }
    cout << ans << endl;
    return 0;
}