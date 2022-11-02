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
#define MAX 3000
#define INF 0x3f3f3f3f

int n , x[MAX];

int32_t main(){
    cin >> n;
    n = n + n;
    REP(i , 0 , n) cin >> x[i];
    int ans = INF;
    REP(i , 0 , n) REP(j , i + 1 , n){
        vector<int> v;
        REP(k , 0 , n){
            if(k != i && k != j) v.pb(x[k]);
        }
        sort(ALL(v));
        int cnt = 0;
        for(int i = 1 ; i < v.size() ; i += 2){
            cnt += v[i] - v[i - 1];
        }
        ans = min(ans , cnt);
    }
    cout << ans << endl;
    return 0;
}