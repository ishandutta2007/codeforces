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
#define int long long
#define MAX 
#define INF 0x3f3f3f3f

vector<PII> cc;

int32_t main(){
    int now = 9 , pp = 1;
    REP(i , 1 , 13){
        cc.pb(mp(now , pp));
        now = now * 10 + 9;
        pp ++;
    }
    int n;
    cin >> n;
    now = 1;
    int ans = 0;
    REP(i , 0 , 13){
        if(n <= cc[i].A){
            ans += (n - now + 1) * cc[i].B;
            break;
        }
        else {
            ans += (cc[i].A - now + 1) * cc[i].B;
            now = cc[i].A + 1;
        }
        // DBGG(now , ans);
    }
    cout << ans << endl;
    return 0;
}