/*input
5
1 1
10 10 9 8 7 100 5 4 3 99 1
5 1 2 3 4 5
5 4 1 3 2 5
4 10 1 5 3
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
#define MAX 
#define INF 0x3f3f3f3f

int n , m;
map<int , int> cc;
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1){
        cin >> m;
        int in;
        REP(j , 1 , m + 1) cin >> in , cc[in] ++;
    }
    for(auto to : cc) if(to.B == n) cout << to.A << " ";
        cout << endl;
    return 0;
}