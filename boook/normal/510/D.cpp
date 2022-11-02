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
#define MAX 100900
#define INF 0x3f3f3f3f

int n;
map<int , int> cc;
PII x[MAX];
int32_t main(){
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i].A;
    REP(i , 1 , n + 1) cin >> x[i].B;
    int ans = INF;
    REP(i , 1 , n + 1){
        vector<PII> tmp;
        for(auto to : cc){
            tmp.pb(mp(__gcd(to.A , x[i].A) , to.B + x[i].B));
        }
        tmp.pb(x[i]);
        for(auto to : tmp){
            if(to.A == 1) ans = min(ans , to.B);
            if(cc.find(to.A) != cc.end()) cc[to.A] = min(cc[to.A] , to.B);
            else cc[to.A] = to.B;
        }

    }
    if(ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}