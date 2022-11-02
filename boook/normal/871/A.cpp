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

int n , x;

int32_t main(){
    IOS;
    cin >> n;
    REP(times , 1 , n + 1){
        cin >> x;
        int ans = 0;
        if(x % 2 == 1) x -= 9 , ans ++;
        if(x < 0) cout << -1 << endl;
        else if(x == 0) cout << 1 << endl;
        else if(x < 4) cout << -1 << endl;
        else cout << x / 4 + ans << endl;
    }
    return 0;
}