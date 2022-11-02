/*input
codeforces
yes
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i , j , k)  for(int i = j ; i <  k ; ++i)
#define RREP(i , j , k) for(int i = j ; i >= k ; --i)
#define A  first
#define B  second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i , j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i , j)     cout << i << " " << j << endl
#define DB4(i , j , k , l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 
#define INF 0x3f3f3f3f

string a , b;
int32_t main(){
    IOS;
    cin >> a >> b;
    reverse(ALL(a));
    reverse(ALL(b));
    int pos = -1;
    while(pos + 1 < a.size() && pos + 1 < b.size() && a[pos + 1] == b[pos + 1]) pos ++;
    cout << a.size() + b.size() - pos - pos - 2 << endl;
    return 0;
}