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
#define MAX 600900
#define INF 0x3f3f3f3f

int n , x[MAX];

int32_t main(){
    cin >> n;
    REP(i , 0 , n) cin >> x[i];
    x[n] = x[n - 1];
    vector<int> tmp;
    tmp.pb(0);
    REP(i , 1 , n){
        if(x[i] == x[i - 1] || x[i] == x[i + 1]) tmp.pb(i);
    }
    int ans = 0;
    REP(i , 1 , tmp.size()){
        if(tmp[i] == tmp[i - 1] + 1) continue;
        int l = tmp[i - 1] , r = tmp[i];
        if(x[l] == x[r]){
            int res = 0;
            int qq = l + 1 , ww = r - 1;
            while(qq <= ww) x[qq++] = x[l] , x[ww--] = x[r] , res ++;
            ans = max(ans , res);
        }
        else {
            int res = 0;
            int qq = l + 1 , ww = r - 1;
            while(qq <= ww) x[qq++] = x[l] , x[ww--] = x[r] , res ++;
            ans = max(ans , res);
        }
    }
    cout << ans << endl;
    REP(i , 0 , n) cout << x[i] << " ";cout << endl;
    return 0;
}