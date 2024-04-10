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
#define MAX 2020
#define INF 0x3f3f3f3f

int n , a[MAX] , b[MAX];
set<int> cc;
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> a[i] , cc.insert(a[i]);
    REP(i , 1 , n + 1) cin >> b[i] , cc.insert(b[i]);
    int ans = 0;
    REP(i , 1 , n + 1) REP(j , 1 , n + 1){
        if(cc.find(a[i] ^ b[j]) != cc.end()) ans ++;
    }
    if(ans % 2 == 0) cout << "Karen" << endl;
    else cout << "Koyomi" << endl;
    return 0;
}