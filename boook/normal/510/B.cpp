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
#define MAX 100
#define INF 0x3f3f3f3f

int n , m , ok = 0 , use[MAX][MAX];
string s[MAX];
int X[] = {-1 , 0 , 0 , 1};
int Y[] = {0 , -1 , 1 , 0};
int IN(int a , int b){
    return (a >= 0 && a < n && b >= 0 && b < m);
}
void DFS(int a , int b , PII fa){
    if(use[a][b]) return ;
    use[a][b] = 1;
    REP(i , 0 , 4) {
        int q = a + X[i] , w = b + Y[i];
        if(mp(q , w) == fa) continue;
        if(IN(q , w) && s[a][b] == s[q][w]){
            if(use[q][w] == 1) ok = 1;
            DFS(q , w , mp(a , b));
        }
    }
}
int32_t main(){
    cin >> n >> m;
    REP(i , 0 , n) cin >> s[i];
    REP(i , 0 , n){
        REP(j , 0 , m) DFS(i , j , mp(-1 , -1));
    }
    if(ok == 0) cout << "No" << endl;
    if(ok == 1) cout << "Yes" << endl;
    return 0;
}