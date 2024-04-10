/*input
1 6 2
4 3 3
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)  for(int i = j ; i < k ; ++i)
#define RREP(i,j,k) for(int i = j ; i >=k ; --i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i,j) memset(i , j , sizeof i)
#define ALL(i)   i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 
#define INF 0x3f3f3f3f

int A , B , C;
int a , b , c;

int32_t main(){
    IOS;
    cin >> A >> B >> C;
    cin >> a >> b >> c;
    a -= A;
    if(a < 0) return cout << "NO" << endl , 0;
    if(a + b < B) return cout << "NO" << endl , 0;
    int all = a + b + c - B;
    if(all < C) return cout << "NO" << endl , 0;
    cout << "YES" << endl;
    return 0;
}