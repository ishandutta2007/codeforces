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
#define MAX 
#define INF 0x3f3f3f3f

string s;
int ppow(int a , int k){
    if(k == 0) return 1;
    if(k % 2 == 0) return ppow(a * a % 5 , k >> 1);
    if(k % 2 == 1) return ppow(a * a % 5 , k >> 1) * a % 5;
}
int32_t main(){
    IOS;
    cin >> s;
    int res = 0;
    if(s.size() == 1) res = s.back() - '0';
    else res = (s[s.size() - 2] - '0') * 10 + (s.back() - '0');
    int ans = 0;
    REP(i , 1 , 5) ans = (ans + ppow(i , res)) % 5;
    cout << ans << endl;
    return 0;
}