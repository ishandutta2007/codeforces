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

int C2(int now){
    if(now % 2 == 0) return now / 2 * (now + 1);
    else return (now + 1) / 2 * now;
}
int F(int a , int b){
    int tma = C2(a) , tmb = C2(b);
    return tma * (b + 1) + tmb * (a + 1);
}

int32_t main(){
    int m , b;
    int ans = 0;
    cin >> m >> b;
    PII now = mp(0 , b);
    while(now.B >= 0){
        // DBGG(now.A , now.B);
        ans = max(ans , F(now.A , now.B));
        now.A += m;
        now.B --;
    }
    cout << ans << endl;
    return 0;
}