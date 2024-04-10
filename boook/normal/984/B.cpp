/*input
2 4
*.*.
1211
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
#define MAX 200
#define INF 0x3f3f3f3f

int n , m;
string s[MAX];
int in(int a , int b){
    return 0 <= a && a < n && 0 <= b && b < m;
}
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 0 , n) cin >> s[i];
    REP(i , 0 , n) REP(j , 0 , m) if(s[i][j] != '*'){
        if(s[i][j] == '.') s[i][j] = '0';
        int cnt = 0;
        REP(ii , -1 , 2) REP(jj , -1 , 2){
            if(in(i + ii , j + jj) && s[i + ii][j + jj] == '*') cnt ++;
        }
        if(cnt != s[i][j] - '0') return cout << "NO" << endl , 0;
    }
    cout << "YES" << endl;
    return 0;
}