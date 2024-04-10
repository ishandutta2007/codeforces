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
#define MAX 200
#define INF 0x3f3f3f3f

int n , ans[MAX][MAX];
int32_t main(){
    cin >> n;
    int po = 1 , add = 2;
    REP(i , 1 , n + 1){
        // DBGG("po = " , po);
        int tmp = (n - po) / 2;
        REP(j , tmp + 1 , tmp + 1 + po){
            ans[i][j] = 1;
        }
        if(po == n) add *= -1;
        po += add;
    }
    REP(i , 1 , n + 1) {
        REP(j , 1 , n + 1){
        if(ans[i][j] == 1){
            cout << "D" ;
        }
        else cout << "*";
    }
        cout << endl;
    }
    return 0;
}