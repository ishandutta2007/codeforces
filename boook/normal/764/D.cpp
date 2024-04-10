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
#define MAX 600000
#define INF 0x3f3f3f3f

int n , x[MAX][4];
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 0 , n) REP(j , 0 , 4) cin >> x[i][j];
    cout << "YES" << endl;
    REP(i , 0 , n){
        if(x[i][0] % 2 == 0 && x[i][1] % 2 == 0) cout << 1 << endl;
        if(x[i][0] % 2 != 0 && x[i][1] % 2 == 0) cout << 2 << endl;
        if(x[i][0] % 2 == 0 && x[i][1] % 2 != 0) cout << 3 << endl;
        if(x[i][0] % 2 != 0 && x[i][1] % 2 != 0) cout << 4 << endl;
    }
    return 0;
}