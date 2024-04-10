/*input
3 2
1 3 0
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

int n , m , x[MAX];
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> x[i];
    int base = (1LL << m) - 1;
    int all = (n * (n + 1)) / 2 , sml = 0;
    map<int , int> cc;
    cc[0] = 1;
    REP(i , 1 , n + 1){
        x[i] ^= x[i - 1];
        if(cc[x[i] ^ base] < cc[x[i]]) x[i] ^= base;

        all -= cc[x[i]];
        cc[x[i]] ++;
    }
    // REP(i , 1 , n + 1) cout << x[i] << " "; cout << endl;
    cout << all << endl;
    return 0;
}