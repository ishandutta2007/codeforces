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
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 
#define INF 0x3f3f3f3f

int a , b , f , k;
int32_t main(){
    IOS;
    cin >> a >> b >> f >> k;
    if(b < f) cout << -1 << endl;
    else {
        int oil = b - f , sum = f , all = a * k;
        int p = f * 2 , q = (a - f) * 2;
        int ans = 0 , step = q;
        while(sum < all){
            int nxt = min(all - sum , step);
            if(oil >= nxt) oil -= nxt;
            else oil = b - nxt , ans ++;
            if(oil < 0) return cout << -1 << endl , 0;
            sum += nxt;
            step = p + q - step;
        }
        cout << ans << endl;
    }
    return 0;
}