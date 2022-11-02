/*input
4 3
###
###
###
###
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
#define MAX 1010
#define INF 0x3f3f3f3f

int n , m , use[MAX][MAX];
string s[MAX];
int in(int a , int b){
    return 0 <= a && a < n && 0 <= b && b < m;
}
void solve(int a , int b){
    int ok = 1;
    REP(i , -1 , 2) REP(j , -1 , 2){
        if(in(a + i , b + j) == 0) ok = 0;
        else if(i == 0 && j == 0);
        else if(s[a + i][b + j] == '.') ok = 0;
    }
    if(ok){
        REP(i , -1 , 2) REP(j , -1 , 2) if(i != 0 || j != 0){
            use[a + i][b + j] = 1;
        }
    }
}
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 0 , n) cin >> s[i];
    REP(i , 0 , n) REP(j , 0 , m) solve(i , j);
    int ok = 1;
    REP(i , 0 , n) REP(j , 0 , m) if(s[i][j] == '#' && use[i][j] == 0) ok = 0;
    if(ok == 1) cout << "YES" << endl;
    if(ok == 0) cout << "NO"  << endl;
    return 0;
}