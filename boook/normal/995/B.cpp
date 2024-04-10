/*input
4
1 1 2 3 3 2 4 4

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

int n;
int32_t main(){
    IOS;
    cin >> n;
    vector<int> v;
    REP(i , 1 , n + n + 1) {
        int in;
        cin >> in;
        v.pb(in);
    }
    int ans = 0;
    REP(i , 1 , n + 1){
        vector<int> w , ss;
        REP(j , 0 , v.size()){
            if(v[j] == v[0]) ss.pb(j);
            else w.pb(v[j]);
        }
        ans += ss[1] - ss[0] - 1;
        swap(w , v);
    }
    cout << ans << endl;
    return 0;
}