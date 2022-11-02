/*input
6 2
..GT..
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
#define MAX 10000
#define INF 0x3f3f3f3f

int n , m , ok[MAX];
string s;
int32_t main(){
    cin >> n >> m >> s;
    int now = 0;
    REP(i , 0 , s.size()) if(s[i] == 'G') now = i;
    ok[now] = 1;
    REP(i , 0 , s.size()){
        if(ok[i]){
            if(i + m < s.size() && s[i + m] != '#') ok[i + m] = 1;
        }
    }
    RREP(i , s.size() - 1 , 0){
        if(ok[i]){
            if(i - m >= 0 && s[i - m] != '#') ok[i - m] = 1;
        }
    }
    REP(i , 0 , s.size()){
        if(s[i] == 'T' && ok[i]){
            return cout << "YES" << endl , 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}