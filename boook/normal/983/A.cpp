/*input
4
1 1 2
9 36 2
4 12 3
3 5 4
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
#define INF 0x3f3f3f3f

int t , a , b , c;
int32_t main(){
    IOS;
    cin >> t;
    REP(times , 0 , t){
        cin >> a >> b >> c;
        a = a % b;
        int tmp = __gcd(a , b);
        a /= tmp , b /= tmp;
        tmp = __gcd(b , c);
        while(__gcd(tmp , b) != 1) b /= __gcd(tmp , b);
        if(b == 1) cout << "Finite" << endl;
        else cout << "Infinite" << endl;
    }
    return 0;
}