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
#define MAX 
#define INF 0x3f3f3f3f

int ans = 0;
void DFS(int a , int b){
    // DBGG(a , b);
    if(a == b) return ans ++ , void();
    if(a < b) swap(a , b);
    int tmp = __gcd(a , b);
    a /= tmp , b /= tmp;
    if(b == 1){
        ans += a;
        return ;
    }
    if(a > b){
        ans += a / b;
        DFS(b , a % b);
    }
}
int a , b;
int32_t main(){
    cin >> a >> b;
    DFS(a , b);
    cout << ans << endl;
    return 0;
}