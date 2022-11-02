/*input
123 1 2143435 4
54343 -13 6 124
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
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 
#define INF 0x3f3f3f3f

int n , m , k , l;
set<int> cc;
int32_t main(){
    IOS;
    cin >> n >> m >> k >> l;
    REP(i , 0 , l){
        int tmp;cin >> tmp;
        cc.insert(tmp);
    }
    if(abs(n) > k) return cout << 0 << endl , 0;
    if(m == 0 || n == 0){
        int ans = 0;
        if(cc.find(n) == cc.end()) ans ++;
        if(cc.find(0) == cc.end()) cout << "inf" << endl;
        else cout << ans << endl;
    }
    else if(m == 1){
        int ans = 0;
        if(cc.find(n) == cc.end())
            cout << "inf" << endl;
        else cout << 0 << endl; 
    }
    else if(m == -1){
        int ans = 0;
        if(cc.find(n) != cc.end() && cc.find(-n) != cc.end())
            cout << 0 << endl;
        else cout << "inf" << endl;
    }
    else {
        int now = n , ans = 0;
        while(abs(now) <= k){
            if(cc.find(now) == cc.end()) ans ++;
            now = now * m;
        }
        cout << ans << endl;
    }
    return 0;
}