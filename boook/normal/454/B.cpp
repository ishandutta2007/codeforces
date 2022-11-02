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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , x[MAX];
int32_t main(){
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    vector<int> v;
    REP(i , 1 , n){
        if(x[i] > x[i + 1]) v.pb(i + 1);
    }
    if(x[n] > x[1]) v.pb(1);
    if(v.size() == 0) cout << 0 << endl;
    else if(v.size() >= 2) cout << -1 << endl;
    else {
        if(v[0] == 1) cout << 0 << endl;
        else cout << n - v[0] + 1 << endl;
    }
    return 0;
}