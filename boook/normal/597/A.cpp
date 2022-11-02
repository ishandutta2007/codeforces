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
#define int long long
#define MAX 
#define INF 0x3f3f3f3f

long long a , b , c;

int32_t main(){
    cin >> a >> b >> c;
    int tma , tmb;
    if(b >= 0) tma = (b % a == 0) ? b / a : b / a + 1;
    else tma = b / a;

    if(c >= 0) tmb = c / a;
    else tmb = (c % a == 0) ? c / a : c / a - 1;
    cout << tmb - tma + 1 << endl;
    return 0;
}