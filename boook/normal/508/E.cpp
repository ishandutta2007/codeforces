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
#define MAX 1010
#define INF 0x3f3f3f3f

stack<string> cc;
int n , x[MAX][2];
int32_t main(){
    cin >> n;
    REP(i , 0 , n) REP(j , 0 , 2) cin >> x[i][j];
    RREP(i , n - 1 , 0){
        int l = x[i][0] - 1 , r = x[i][1] - 1;
        string now;
        while(cc.size() && now.size() < l){
            now += cc.top() , cc.pop();
        }
        if(now.size() < l || now.size() > r){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        string tmp = "(" + now + ")";
        cc.push(tmp);
    }
    while(cc.size()) cout << cc.top() , cc.pop();
    cout << endl;
    return 0;
}