/*input
4
LDUR
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

int l , u , d , r;
string s;
int32_t main(){
    cin >> s >> s;
    REP(i , 0 , s.size()){
        if(s[i] == 'L') l ++;
        if(s[i] == 'U') u ++;
        if(s[i] == 'D') d ++;
        if(s[i] == 'R') r ++;
    }
    cout << min(l , r) * 2 + min(u , d) * 2 << endl;
    return 0;
}