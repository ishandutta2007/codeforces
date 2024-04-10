/*input
1000000000000000000 1
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
#define int long long
#define MAX 
#define INF 0x3f3f3f3f


int n , m;
int32_t main(){
    IOS;
    cin >> m >> n;
    int base = 0;// , val = (n + 1) * n / 2;
    if(m * 2 / n / (n + 1) == 0){
        REP(i , 1 , n + 1){
            base ++ , m -= i;
            if(m < i + 1) return cout << i + (m != 0) << endl , 0;
        }
    }
    else {
        m -= (n + 1) * n / 2 , base += n;
        int cnt = n + n + 1;
        while(m >= cnt) m -= cnt , cnt += 2 , base += 2;
        while(m > 0) m -= cnt / 2 , base ++;
        cout << base << endl;
    }
    return 0;
}