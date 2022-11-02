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
#define MAX 
#define INF 0x3f3f3f3f

int n;
int F(int now){
    REP(i , 2 , now){
        if(i * i > now) return 1;
        if(now % i == 0) return 0;
    }
    return 1;
}
int32_t main(){
    cin >> n;
    vector<int> ans;
    REP(i , 2 , n + 1){
        if(F(i) == 0) continue;
        int tmp = i;
        while(tmp <= n) ans.pb(tmp) , tmp *= i;
    }
    cout << ans.size() << endl;
    for(auto to : ans) cout << to << " " ;
        cout << endl;
    return 0;
}