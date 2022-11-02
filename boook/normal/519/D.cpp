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

map<pair<int , char> , int> cc;
int val[MAX] , x[MAX];
string s;
int32_t main(){
    REP(i , 0 , 26) cin >> val[i];
    cin >> s;
    int ans = 0;
    REP(i , 0 , s.size()){
        x[i + 1] = x[i] + val[s[i] - 'a'];
        ans += cc[mp(x[i] , s[i])];
        cc[mp(x[i + 1] , s[i])] ++;
    }
    cout << ans << endl;
    return 0;
}