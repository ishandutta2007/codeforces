/*input
3
7
3 1 6 6 3 1 1
8
1 1 4 4 4 7 8 8
7
4 2 5 2 6 2 7
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)  for(int i = j ; i < k ; ++i)
#define RREP(i,j,k) for(int i = j ; i >=k ; --i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i,j) memset(i , j , sizeof i)
#define ALL(i)   i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 300900
#define INF 0x3f3f3f3f

int t , n , x[MAX] , ql[MAX] , qr[MAX];

int32_t main(){
    IOS;
    cin >> t;
    REP(times , 0 , t){
        cin >> n;
        set<int> cc;
        REP(i , 1 , n + 1) cin >> x[i] , cc.insert(x[i]);
        REP(i , 1 , n + 1) ql[i] = INF , qr[i] = 0;
        REP(i , 1 , n + 1) ql[x[i]] = min(ql[x[i]] , i);
        REP(i , 1 , n + 1) qr[x[i]] = max(qr[x[i]] , i);

        int pos = 0 , nowval = 0 , ans = 0;
        for(auto to : cc){
            if(pos < ql[to]){
                nowval ++;
                pos = qr[to];
            }
            else {
                nowval = 1;
                pos = qr[to];
            }
            ans = max(ans , nowval);
        }
        cout << cc.size() - ans << endl;
    }
    return 0;
}