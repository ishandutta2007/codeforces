/*input
4
garage for sa-le
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
#define MAX 
#define INF 0x3f3f3f3f

int n;
string s;
int judge(int now){
    int res = 1 , sum = 0;
    vector<int> sol;
    sol.pb(-1);
    REP(i , 0 , s.size()) if(s[i] == '-') sol.pb(i);
    sol.pb(s.size() - 1);
    REP(i , 1 , sol.size()){
        if(sum + sol[i] - sol[i - 1] <= now) sum += sol[i] - sol[i - 1];
        else sum = sol[i] - sol[i - 1] , res ++;
        if(sum > now) return 0;
    }
    if(res > n) return 0;
    return 1;
}
int32_t main(){
    cin >> n;
    getline(cin , s);
    getline(cin , s);
    REP(i , 0 , s.size()) if(s[i] == ' ') s[i] = '-';
    
    int ans = s.size();
    RREP(i , 20 , 0){
        int to = ans - (1 << i);
        if(to >= 1 && judge(to)) ans = to;
    }
    cout << ans << endl;
    return 0;
}