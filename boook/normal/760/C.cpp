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
#define MAX 300000
#define INF 0x3f3f3f3f

int n , a[MAX] , b[MAX] , use[MAX];
void DFS(int now){
    if(use[now]) return ;
    use[now] = 1;
    DFS(a[now]);
}
int32_t main(){
    cin >> n;
    REP(i , 1 , n + 1) cin >> a[i];
    REP(i , 1 , n + 1) cin >> b[i];
    int sum = 0 , cnt = 0;
    REP(i , 1 , n + 1) sum += b[i];
    REP(i , 1 , n + 1){
        if(use[i] == 0) DFS(i) , cnt ++;
    }
    int ans = ((cnt > 1) ? cnt : 0) + ((sum + 1) % 2);
    cout << ans << endl;
    return 0;
}