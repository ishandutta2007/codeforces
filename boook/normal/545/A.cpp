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
#define MAX 2000
#define INF 0x3f3f3f3f

int n , x[MAX][MAX];
int use[MAX];
int32_t main(){
    cin >> n;
    REP(i , 1 , n + 1) REP(j , 1 , n + 1){
        cin >> x[i][j];
        if(x[i][j] == 1 || x[i][j] == 3) use[i] = 1;
    }
    int cnt = 0;
    REP(i , 1 , n + 1) if(use[i] == 0) cnt++;
    cout << cnt << endl;
    if(cnt){
        REP(i , 1 , n + 1) if(use[i] == 0) cout << i << " ";
        cout << endl;
    }
    return 0;
}