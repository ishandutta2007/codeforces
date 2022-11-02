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
#define MAX 20
#define INF 0x3f3f3f3f

int n , m , k , use[MAX][MAX][MAX];
string s[MAX][MAX];
int X[] = {1 , -1 , 0 , 0 , 0 , 0};
int Y[] = {0 , 0 , 1 , -1 , 0 , 0};
int Z[] = {0 , 0 , 0 , 0 , 1 , -1};
int DFS(int a , int b , int c){
    if(use[a][b][c]) return 0;
    use[a][b][c] = 1;
    int ans = 1;
    REP(i , 0 , 6){
        int aa = a + X[i];
        int bb = b + Y[i];
        int cc = c + Z[i];
        if(aa >= 0 && aa < n && bb >= 0 && bb < m && cc >= 0 && cc < k)
            if(s[aa][bb][cc] == '.') ans += DFS(aa , bb , cc);
    }
    return ans;
}
int32_t main(){
    IOS;
    cin >> n >> m >> k;
    REP(i , 0 , n) REP(j , 0 , m) cin >> s[i][j];
    int a , b;
    cin >> a >> b;
    cout << DFS(0 , a - 1 , b - 1) << endl;
    return 0;
}