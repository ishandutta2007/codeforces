/*input
3
qwerty
qwerty
qwerty
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
#define MAX 110
#define INF 0x3f3f3f3f

int n;
string s[MAX];
int cmp(string a , string b){ return a.size() < b.size(); }
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> s[i];
    sort(s + 1 , s + 1 + n , cmp);
    REP(i , 2 , n + 1){
        int ok = 0;
        REP(j , 0 , s[i].size()){
            string p = s[i].substr(j , s[i - 1].size());
            if(p == s[i - 1]) ok = 1;
        }
        if(ok == 0) return cout << "NO" << endl , 0;
    }
    cout << "YES" << endl;
    REP(i , 1 , n + 1) cout << s[i] << endl;
    return 0;
}