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
#define MAX 100000
#define INF 0x3f3f3f3f

int n , m;
PII x[MAX];

int32_t main(){
    cin >> n >> m;
    REP(i , 1 , n + 1){
        cin >> x[i].A;
        x[i].B = i;
    }
    sort(x + 1 , x + n + 1);
    vector<int> ans;
    int now = 0;
    REP(i , 1 , n + 1){
        if(now + x[i].A <= m) now += x[i].A , ans.pb(x[i].B);
        else break;
    }
    cout << ans.size() << endl;
    if(ans.size() > 0){
        for(auto to : ans) cout << to << " " ; cout << endl;
        
    }
    return 0;
}