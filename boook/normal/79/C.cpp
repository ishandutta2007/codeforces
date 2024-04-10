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
#define AC 10430579LL
#define mod 1000000009LL

int h[MAX] , m[MAX] , n , v[20];
string s , x[20];

int32_t main(){
    IOS;
    m[0] = 1;
    REP(i , 1 , MAX) m[i] = m[i - 1] * AC % mod;

    cin >> s;
    REP(i , 0 , s.size()) h[i + 1] = (h[i] + s[i] * m[i]) % mod;
    // REP(i , 0 , s.size()) cout << h[i + 1] << " " ; cout << endl;

    cin >> n;
    REP(i , 0 , n){
        cin >> x[i];
        int res = 0;
        REP(j , 0 , x[i].size()) res = (res + x[i][j] * m[j]) % mod;
        v[i] = res;
    }

    int l = 0;
    PII ans = mp(0 , 0);
    REP(r , 0 , s.size()){
        int ok = 1 , to = 0;
        REP(i , 0 , n){
            if(r - l + 1 < x[i].size()) continue;
            int v1 = (h[r + 1] + mod - h[r - x[i].size() + 1]) % mod;

            int v2 = v[i] * (m[r - (x[i].size() - 1)]) % mod;
            if(v1 == v2){
                ok = 0;
                to = max(to , r + 1 - x[i].size() + 1);
            }
        }
        if(ok) ans = max(ans , mp(r - l + 1 , l));
        else l = to;
    }

    cout << ans.A << " " << ans.B << endl;
    return 0;
}