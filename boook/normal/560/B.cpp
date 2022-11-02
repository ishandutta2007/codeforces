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
#define MAX 
#define INF 0x3f3f3f3f


int ok = 0;
void check(int a , int b , int c , int d , int e , int f){
    if(c + e <= a && max(d , f) <= b) ok = 1;
}
int a , b , c , d , e , f;
int32_t main(){
    cin >> a >> b >> c >> d >> e >> f;
    check(a , b , c , d , e , f);
    check(a , b , c , d , f , e);

    check(b , a , c , d , e , f);
    check(b , a , c , d , f , e);
    
    check(a , b , d , c, e , f);
    check(a , b , d , c, f , e);
    
    check(b , a , d , c, e , f);
    check(b , a , d , c, f , e);

    cout << ((ok == 1) ? "YES" : "NO") << endl;
    return 0;
}