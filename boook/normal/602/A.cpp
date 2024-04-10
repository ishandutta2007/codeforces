#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 10000
#define INF 0x3f3f3f3f

int n , m , x[MAX];
int a , b;
int solve(){
    int c = 1 , ans = 0;
    RREP(i , n - 1 , 0){
        ans += c * x[i];
        c *= m;
    }
    return ans;
}
int32_t main(){
    cin >> n >> m;
    REP(i , 0 , n) cin >> x[i];
    a = solve();
    cin >> n >> m;
    REP(i , 0 , n) cin >> x[i];
    b = solve();
    if(a > b) cout << ">" << endl;
    if(a < b) cout << "<" << endl;
    if(a == b) cout << "=" << endl;
    return 0;
}