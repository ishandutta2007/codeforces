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
#define MAX 1000
#define INF 0x3f3f3f3f

int n , m;
int p[MAX][MAX];
int32_t main(){
    cin >> n >> m;
    int cnt = 0;
    REP(i , 0 , n){
        if(i % 2 == 0){
            for(int j = 0 ; j < n ; j += 2)
                if(cnt < m) p[i][j] = 1 , cnt ++;
        }
        else {
            for(int j = 1 ; j < n ; j += 2)
                if(cnt < m) p[i][j] = 1 , cnt ++;
        }
    }
    if(cnt == m){
        cout << "YES" << endl;
        REP(i , 0 , n){
            REP(j , 0 , n){
                if(p[i][j] == 0) cout << "S" ;
                else cout << "L";
            }
            cout << endl;
        }
    }
    else cout << "NO" << endl;
    return 0;
}