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
#define MAX 100
#define INF 0x3f3f3f3f

int F(int x , int now , int wrong){
    int tmp = x * 3 / 10;
    int a = x - x * now / 250 - 50 * wrong;
    return max(tmp , a); 
}
int ans = 0 , aa[MAX] , ww[MAX];
int32_t main(){
    REP(i , 0 , 5) cin >> aa[i];
    REP(i , 0 , 5) cin >> ww[i];
    ans += F(500 , aa[0] , ww[0]);
    ans += F(1000 , aa[1] , ww[1]);
    ans += F(1500 , aa[2] , ww[2]);
    ans += F(2000 , aa[3] , ww[3]);
    ans += F(2500 , aa[4] , ww[4]);
    int qq , ww;
    cin >> qq >> ww;
    ans += qq * 100;
    ans -= ww * 50;
    cout << ans << endl;
    return 0;
}