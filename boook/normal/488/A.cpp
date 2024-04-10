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

int F(int now){
    if(now < 0) now *= -1;
    while(now){
        if(now % 10 == 8) return 1;
        now /= 10;
    }
    return 0;
}
int32_t main(){
    int n , ans = 1;
    cin >> n; n++;
    while(F(n) == 0) n ++ , ans++;
    cout << ans << endl;
    return 0;
}