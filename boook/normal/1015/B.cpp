/*input
6
aaaab
baaaa
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
#define MAX 
#define INF 0x3f3f3f3f

string a , b;
string c , d;
int32_t main(){
    IOS;
    cin >> a >> a >> b;
    c = a , d = b;
    sort(ALL(c));
    sort(ALL(d));
    if(c != d) return cout << -1 << endl , 0;
    else {
        vector<int> ans;
        RREP(i , b.size() - 1 , 0){
            RREP(j , i , 0){
                if(a[j] == b[i]){
                    REP(k , j , i) ans.pb(k) , a[k] = a[k + 1];
                    a[i] = b[i];
                    break;
                }
            }
        }
        cout << ans.size() << endl;
        for(auto to : ans) cout << to + 1 << " "; cout << endl;
    }
    return 0;
}