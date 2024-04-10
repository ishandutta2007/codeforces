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

string a , b;
int32_t main(){
    cin >> a >> b;
    int cnt = 0;
    string ans;
    REP(i , 0 , a.size()){
        if(a[i] != b[i]) ans += (cnt % 2 == 0) ? a[i] : b[i] , cnt ++;
        else ans += "0";
    }
    if(cnt & 1) cout << "impossible" << endl;
    else cout << ans << endl;
    return 0;
}