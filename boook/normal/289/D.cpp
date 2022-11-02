/*input
7 4
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
#define MAX 1010
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int ppow(int a , int k){
    if(k == 0) return 1;
    if(k % 2 == 0) return ppow(a * a % mod , k >> 1);
    if(k % 2 == 1) return ppow(a * a % mod , k >> 1) * a % mod;    
}
int n , m , ans = 0 , x[10] , use[10];
void check(int now){
    if(use[now]) return ;
    use[now] = 1;
    REP(i , 1 , m + 1) if(x[i] == now) check(i);
}
void DFS(int floor){
    if(floor == m + 1){
        MEM(use , 0);
        check(1);
        REP(i , 1 , m + 1) if(use[i] == 0) return ;
        ans ++;
    }
    else {
        REP(i , 1 , m + 1) if(i != floor || floor == 1){
            x[floor] = i;
            DFS(floor + 1);
        }
    }
}
int32_t main(){
    IOS;
    cin >> n >> m;
    int las = ppow(n - m , n - m);

    DFS(1);
    // DBGG("las = " , ans);
    // DBGG("las = " , las);
    cout << ans * las % mod << endl;
    return 0;
}