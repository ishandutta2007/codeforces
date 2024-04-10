/*input
5
3123 3123
2777 2777
2246 2246
2246 2246
1699 1699
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
#define MAX 3000
#define INF 0x3f3f3f3f

int n , a[MAX] , b[MAX];

int32_t main(){
    cin >> n;
    REP(i , 1 , n + 1) cin >> a[i] >> b[i];

    REP(i , 1 , n + 1){
        if(a[i] != b[i]){
            cout << "rated" << endl;
            return 0;
        }
    }
    REP(i , 2 , n + 1){
        if(a[i] > a[i - 1]){
            cout << "unrated" << endl;
            return 0;
        }
    }
    cout << "maybe" << endl;
    return 0;
}