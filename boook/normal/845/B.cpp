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
#define MAX 100
#define INF 0x3f3f3f3f

int x[MAX];
int32_t main(){
    string s;
    cin >> s;
    int ans = 10;
    REP(i , 0 , 1000000){
        int tmp = i;
        REP(j , 0 , 6) x[j] = tmp % 10 , tmp /= 10;
        if(x[0] + x[1] + x[2] == x[3] + x[4] + x[5]){
            int cnt = 0;
            REP(j , 0 , 6) if(x[j] != s[j] - '0') cnt ++;
            ans = min(ans , cnt);
        }
    }
    cout << ans << endl;
    return 0;
}