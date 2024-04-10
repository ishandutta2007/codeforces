/*input
aabcaa
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
#define MAX 1000900
#define INF 0x3f3f3f3f

string s;
int fr[MAX] , ba[MAX] , u[MAX];
int32_t main(){
    IOS;
    cin >> s , s = " " + s;

    vector<int> sol;
    REP(i , 1 , s.size() + 1) fr[i] = i - 1;
    REP(i , 1 - 1 , s.size()) ba[i] = i + 1;

    REP(i , 1 , s.size()){
        if(i - 1 != 0        && s[i] != s[i - 1]) sol.pb(i);
        if(i + 1 != s.size() && s[i] != s[i + 1]) sol.pb(i);
    }

    int ans = 0;
    while(sol.size()){
        vector<int> nxt;
        queue<int> qu;
        int can = 0;
        for(auto to : sol) if(u[to] == 0){ u[to] = 1;
            can = 1;
            int v1 = fr[to] , v2 = ba[to];
            ba[v1] = v2;
            fr[v2] = v1;
            qu.push(v1);
            qu.push(v2);
        }
        ans += can;
        while(qu.size()){
            int now = qu.front(); qu.pop();
            int ok = 0;
            if(now == s.size() || now == 0) continue;

            if(ba[now] != s.size() && s[now] != s[ba[now]]) ok = 1;
            if(fr[now] != 0        && s[now] != s[fr[now]]) ok = 1;

            if(ok) nxt.pb(now);
        }
        sol = nxt;
    }
    cout << ans << endl;
    return 0;
}