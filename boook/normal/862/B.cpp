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
#define MAX 200000
#define INF 0x3f3f3f3f

int n , q = 0 , w = 0 , ans = 0;
vector<int> v[MAX];
void DFS1(int now , int fa , int dep){
    if(dep % 2 == 0) q ++;
    else w ++;
    for(auto to : v[now]){
        if(to == fa) continue;
        DFS1(to , now , dep + 1);
    }
}
void DFS2(int now , int fa , int dep){
    int son = 0;
    if(fa) son ++;
    for(auto to : v[now]){
        if(to == fa) continue;
        son ++;
        DFS2(to , now , dep + 1);
    }
    if(dep % 2 == 0) ans += w - son;
    else ans += q - son;
}
int32_t main(){
    cin >> n;
    REP(i , 1 , n){
        int a , b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    DFS1(1 , 0 , 0);
    DFS2(1 , 0 , 0);
    cout << ans / 2 << endl;
    return 0;
}