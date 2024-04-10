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
#define MAX 4000
#define INF 0x3f3f3f3f

int n , x[MAX];
int32_t main(){
    cin >> n;
    vector<int> v;
    REP(i , 1 , n + 1){
        cin >> x[i];
        if(x[i] == 1) v.pb(i);
    }
    int ans = v.size();
    REP(i , 1 , v.size()){
        if(v[i] - v[i - 1] == 2) ans ++;
    }
    cout << ans << endl;
    return 0;
}