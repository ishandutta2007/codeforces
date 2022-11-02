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
#define MAX 200000
#define INF 0x3f3f3f3f

int n , x[MAX];
multiset<int> cc;
int32_t main(){
    cin >> n;
    int ans = 0;
    REP(i , 0 , n) cin >> x[i];
    int l = 0;
    REP(i , 0 , n){
        cc.insert(x[i]);
        auto fr = cc.begin();
        auto ba = cc.end(); ba --;
        while(*ba - *fr > 1){
            cc.erase(cc.find(x[l ++]));
            fr = cc.begin();
            ba = cc.end(); ba --;
        }
        ans = max(ans , i - l + 1);
    }
    cout << ans << endl;
    return 0;
}