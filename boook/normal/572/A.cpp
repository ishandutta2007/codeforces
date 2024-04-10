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
#define MAX 200000
#define INF 0x3f3f3f3f

int n , m;
int q , w;
int a[MAX] , b[MAX];

int32_t main(){
    cin >> n >> m;
    cin >> q >> w;
    REP(i , 0 , n) cin >> a[i];
    REP(i , 0 , m) cin >> b[i];
    sort(b , b + m , greater<int>());
    int tma = a[q - 1];
    int tmb = b[w - 1];
    if(tma < tmb) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}