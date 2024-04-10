/*input
10
3 6 5 5 4 5 5 4 7 6
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
// #define endl "\n"
///------------------------------------------------------------
#define MAX 1010
#define INF 0x3f3f3f3f

int n , x[MAX];
vector<int> sol;
vector<PII> ans;
int cmp(int a , int b){ return x[a] < x[b]; }
void trs(int a , int b){
    ans.pb(mp(a , b));
    x[b] -= x[a] , x[a] += x[a];
}
void solve(int id1 , int id2 , int id3){
    int q[3] = {id1 , id2 , id3};
    sort(q , q + 3 , cmp) , id1 = q[0] , id2 = q[1] , id3 = q[2];
    if(x[id1] == 0) return ;
    int val = x[id2] / x[id1];
    while(val){
        if(val % 2 == 1) trs(id1 , id2);
        if(val % 2 == 0) trs(id1 , id3);
        val >>= 1;
    }
    solve(id1 , id2 , id3);
}
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 1) if(x[i]) sol.pb(i);
    if(sol.size() <= 1) return cout << -1 << endl , 0;
    else {
        while(sol.size() > 2){
            solve(sol[0] , sol[1] , sol.back());
            while(x[sol[0]] == 0) sol[0] = sol.back() , sol.pop_back();
            while(x[sol[1]] == 0) sol[1] = sol.back() , sol.pop_back();
            while(x[sol.back()] == 0) sol.pop_back();
        }
        cout << ans.size() << endl;
        for(auto to : ans) cout << to.A << " " << to.B << endl;
    }
    return 0;
}