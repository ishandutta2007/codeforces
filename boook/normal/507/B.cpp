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

int r , a , b , q , w;

int32_t main(){
    cin >> r >> a >> b >> q >> w;
    int tmp = (a - q) * (a - q) + (b - w) * (b - w);
    r *= 2;
    int tt = sqrt(tmp);
    while(tt * tt < tmp) tt++;
    if(tt % r == 0) cout << tt / r << endl;
    else cout << (tt / r) + 1 << endl;
    return 0;
}