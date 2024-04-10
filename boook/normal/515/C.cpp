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

int n;
string s , ans;
string pre[90];

int32_t main(){

    pre[2] = "2";
    pre[3] = "3";
    pre[4] = "322";
    pre[5] = "5";
    pre[6] = "53";
    pre[7] = "7";
    pre[8] = "2227";
    pre[9] = "3327";

    cin >> n;
    cin >> s;
    REP(i , 0 , s.size()){
        int tmp = s[i] - '0';
        if(tmp <= 1) continue;
        else ans += pre[tmp];         
    }
    sort(ALL(ans) , greater<char>());
    cout << ans << endl;
    return 0;
}