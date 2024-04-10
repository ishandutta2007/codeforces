/*input
100 1 100 1 0 1
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


int32_t main(){
    IOS;
    int a , b , c , d , e , f;
    cin >> a >> b >> c >> d >> e >> f;
    int v1 = b * d * f;
    int v2 = a * c * e;
    if(a == 0 && b != 0 && c != 0 && d != 0) cout << "Ron" << endl;
    else if(e == 0 && f != 0 && a != 0 && b != 0 && c != 0 && d != 0) cout << "Ron" << endl;
    else if(c == 0 && d != 0) cout << "Ron" << endl;
    else if(v1 > v2) cout << "Ron" << endl;
    else cout << "Hermione" << endl;
    return 0;
}