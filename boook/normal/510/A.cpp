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
#define MAX 10000
#define INF 0x3f3f3f3f

int n , m;
string s[MAX];
int32_t main(){
    cin >> n >> m;
    REP(i , 0 , n) REP(j , 0 , m) s[i] += '#';
    int po = 0;
    for(int i = 1 ; i < n ; i += 2){
        if(po == 0){
            REP(j , 0 , m - 1) s[i][j] = '.';
        }
        else {
            REP(j , 1 , m) s[i][j] = '.';
        }
        po = 1 - po;
    }
    REP(i , 0 , n) cout << s[i] << endl;
    return 0;
}