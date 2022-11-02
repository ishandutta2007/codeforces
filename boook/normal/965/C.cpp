/*input
30 9 4 1
*/
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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 
#define INF 0x3f3f3f3f

int people , candies , lim , times;
int T(int a , int b , int c){
    int tmp = 3123456789123456789;
    if(a == 0 || b == 0 || c == 0) return 0;
    if(tmp / a / b / c != 0) return a * b * c;
    else return tmp;
}
int32_t main(){
    IOS;
    // 20 4 5 2
    cin >> candies >> people >> lim >> times;
    int ans = -1;
    REP(i , 1 , times + 1){
        int now = 0;
        RREP(j , 60 , 0){
            int to = now + (1LL << j);
            // if(to * (i - 1) * people + to <= candies) now = to;
            // if(to == 4) cout << "here = " << T(to , (i - 1) , people) + to << endl;
            if(T(to , (i - 1) , people) + to <= candies) now = to;
        }


        // DBGG(i , now);
        int big = min(now , lim);
        if(candies - T(big , i , people) <= big){
            ans = max(ans , big * i);
        }
    }
    cout << ans << endl;
    return 0;
}