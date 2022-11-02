/*input
6 2
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
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 
#define INF 0x3f3f3f3f

int n , k;

int32_t main(){
    IOS;
    cin >> n >> k;
    if(k == 1){
        if(n == 1) cout << "a" << endl;
        else cout << -1 << endl;
        return 0;
    }
    if(n < k) cout << -1 << endl;
    else {
        if((n - k) % 2 == 0){
            REP(i , 0 , n - k){
                if(i % 2 == 0) cout << "a";
                if(i % 2 == 1) cout << "b";
            }
            REP(i , 0 , k){
                cout << char('a' + i) ;
            }
            cout << endl;
        }
        if((n - k) % 2 == 1){
            REP(i , 0 , n - k){
                if(i % 2 == 0) cout << "a";
                if(i % 2 == 1) cout << "b";
            }
            REP(i , 0 , k){
                int v;
                if(i <= 1) v = 1 - i;
                else v = i;
                cout << char('a' + v) ;
            }
            cout << endl;
        }
    }
    return 0;
}