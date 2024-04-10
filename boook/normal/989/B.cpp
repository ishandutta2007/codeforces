/*input
10 6
1.0.1.1000
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
#define MAX 
#define INF 0x3f3f3f3f

int n , m;
string s;
int32_t main(){
    IOS;
    cin >> n >> m;
    cin >> s;
    int ok = 0;
    // cout << s << endl;
    REP(i , 0 , s.size()){
        int to = i + m;
        if(to < s.size()){

            if(s[i] == '.' || s[to] == '.'){
                if(s[i] == '.' && s[to] == '.') s[i] = '0' , s[to] = '1' , ok = 1;
                else if(s[i] != '.') s[to] = 1 - (s[i] - '0') + '0' , ok = 1;
                else if(s[to] != '.') s[i] = 1 - (s[to] - '0') + '0' , ok = 1;
            }
            else if(s[i] != s[to]) ok = 1;
        }
    }
    // cout << s << endl;
    if(ok == 0) return cout << "No" << endl , 0;
    REP(i , 0 , s.size()) if(s[i] == '.') s[i] = '0';
    cout << s << endl;
    return 0;
}