/*input
8
1
1
1
1
3
3
3
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
#define MAX 100000
#define INF 0x3f3f3f3f


vector<int> v[MAX];
int ok = 0;
void DFS(int now){
    if(v[now].size() == 0) return ;
    else {
        int cnt = 0;
        for(auto to : v[now]) if(v[to].size() == 0) cnt ++;
        if(cnt >= 3);
        else {
            cout << "No" << endl;
            exit(0);
        }
        for(auto to : v[now]) DFS(to);
    }
}
int32_t main(){
    int n;
    cin >> n;
    REP(i , 2 , n + 1){
        int in;cin >> in;
        v[in].pb(i);
    }
    DFS(1);
    cout << "Yes" << endl;
    return 0;
}