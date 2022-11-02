/*input
5
0 0 1 1 2
2 0 1 0 0
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
#define MAX 1010
#define INF 0x3f3f3f3f

int n , a[MAX] , b[MAX] , c[MAX] , d[MAX] , ans[MAX] , add[MAX];
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> a[i];
    REP(i , 1 , n + 1) cin >> b[i];
    vector<int> aa , bb;
    REP(i , 1 , n + 1){
        if(a[i] > aa.size()) return cout << "NO" << endl , 0;
        else {
            if(a[i] > 0) c[aa[a[i] - 1]] = 1;
            aa.insert(aa.begin() + a[i] , i);
        }
    }
    RREP(i , n , 1){
        if(b[i] > bb.size()) return cout << "NO" << endl , 0;
        else {
            if(b[i] > 0) d[bb[b[i] - 1]] = 1;
            bb.insert(bb.begin() + b[i] , i);
        }
    }
    // for(auto to : aa) cout << to << " "; cout << endl;
    // for(auto to : bb) cout << to << " "; cout << endl;

    REP(i , 0 , aa.size()) if(c[aa[i]] == 1){
        add[i] = 1;
        set<int> tmp;
        REP(j , 0 , i + 1) tmp.insert(aa[j]);
        REP(j , 0 , i + 1) if(tmp.count(bb[j]) == 0) return cout << "NO" << endl , 0;
    }
    REP(i , 0 , bb.size()) if(d[bb[i]] == 1){
        add[i] = 1;
        // DBGG(i , bb[i]);
        set<int> tmp;
        REP(j , 0 , i + 1) tmp.insert(bb[j]);
        REP(j , 0 , i + 1) if(tmp.count(aa[j]) == 0) return cout << "NO" << endl , 0;
    }

    int sum = 1;
    RREP(i , int(aa.size()) - 1 , 0){
        sum += add[i];
        ans[aa[i]] = sum;
    }
    cout << "YES" << endl;
    REP(i , 1 , n + 1) cout << ans[i] << " "; cout << endl;
    return 0;
}