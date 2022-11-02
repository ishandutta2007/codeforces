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
#define MAX 200
#define INF 0x3f3f3f3f

int n , m , ans = 0;
string s[MAX];
int DFS(int i , int j){
    s[i][j] = '.';
    if(i > 0 && s[i - 1][j] != '.') DFS(i - 1 , j);
    if(j > 0 && s[i][j - 1] != '.') DFS(i , j - 1);
    if(j + 1 < m && s[i][j + 1] != '.') DFS(i , j + 1);
    if(i + 1 < n && s[i + 1][j] != '.') DFS(i + 1 , j);
}
int32_t main(){
    cin >> n >> m;
    REP(i , 0 , n) cin >> s[i];
    REP(i , 0 , n) REP(j , 0 , m){
        if(s[i][j] != '.') ans ++ , DFS(i , j);
    }
    cout << ans << endl;
    return 0;
}