/*input
4
1 2
1 3
1 4
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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 200900
#define INF 0x3f3f3f3f

struct N{
    int nowsum , othsum , nowsiz , othsiz;
};
int n , ans;
vector<int> v[MAX];
N DFS(int now , int fa){
    N ret = N{0 , 0 , 1 , 0};
    for(auto to : v[now]) if(to != fa){
        N tmp = DFS(to , now);
        swap(tmp.nowsum , tmp.othsum);
        swap(tmp.nowsiz , tmp.othsiz);
        tmp.nowsum += tmp.nowsiz;
        tmp.othsum += tmp.othsiz;

        ans += (tmp.nowsum * ret.nowsiz + ret.nowsum * tmp.nowsiz) / 2;

        ans += (tmp.othsum * ret.othsiz + ret.othsum * tmp.othsiz) / 2;

        ans += (tmp.nowsum * ret.othsiz + ret.othsum * tmp.nowsiz + (tmp.nowsiz * ret.othsiz)) / 2;

        ans += (tmp.othsum * ret.nowsiz + ret.nowsum * tmp.othsiz + (tmp.othsiz * ret.nowsiz)) / 2;

        ret.nowsum += tmp.nowsum;
        ret.othsum += tmp.othsum;
        ret.nowsiz += tmp.nowsiz;
        ret.othsiz += tmp.othsiz;
    }
    // DBGG("now = " , now);
    // DB4(ret.nowsum , ret.othsum , ret.nowsiz , ret.othsiz);
    return ret;
}
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 2 , n + 1){
        int a , b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    DFS(1 , 1);
    cout << ans << endl;
    return 0;
}