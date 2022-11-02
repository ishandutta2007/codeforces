/*input
4
6
2 2 2 2 2 2
5
2 2 2 2 2
3
2 2 2
5
2 2 2 2 2
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

int m , n , x[MAX];
int32_t main(){
    IOS;
    cin >> m;
    map<int , PII> cc;
    REP(times , 1 , m + 1){
        cin >> n;
        int all = 0;
        REP(i , 1 , n + 1) cin >> x[i] , all += x[i];
        REP(i , 1 , n + 1){
            if(cc.find(all - x[i]) != cc.end()){
                cout << "YES" << endl;
                cout << cc[all - x[i]].A << " " << cc[all - x[i]].B << endl;
                cout << times << " " << i << endl;
                return 0;
            }
        }
        REP(i , 1 , n + 1) cc[all - x[i]] = mp(times , i);
    }
    cout << "NO" << endl;
    return 0;
}