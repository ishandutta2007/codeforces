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

int n , m;
int dp[MAX];
int32_t main(){
    cin >> n >> m;
    dp[0] = dp[1] = 1;
    REP(i , 2 , MAX) dp[i] = dp[i - 1] + dp[i - 2];
    int now = 1 , tmp = n;
    while(now <= n){
        if(m > dp[tmp - 1]){
            m -= dp[tmp - 1];
            tmp -= 2;
            if(now == n) cout << now << " ";
            else cout << now + 1 << " " << now << " ";
            now += 2;
        }
        else {
            tmp --;
            cout << now << " ";
            now ++;
        }
    }
    cout << endl;
    return 0;
}