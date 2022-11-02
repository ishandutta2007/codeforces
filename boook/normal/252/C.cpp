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

int n , m , x[MAX] , po = 0;
int32_t main(){
    cin >> n >> m;
    REP(i , 0 , n) cin >> x[i];
    int ans = 0;
    REP(i , 0 , n){
        while(po + 1 < n && x[po + 1] <= x[i] + m) po ++;
        int res = po - i + 1 - 1;
        ans += res * (res - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}