#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i , j , k)  for(int i = j ; i <  k ; ++i)
#define RREP(i , j , k) for(int i = j ; i >= k ; --i)
#define A  first
#define B  second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i , j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i , j)     cout << i << " " << j << endl
#define DB4(i , j , k , l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 300000
#define INF 0x3f3f3f3f

int n , k , x[MAX];

int32_t main(){
    IOS;
    cin >> n >> k;
    REP(i , 1 , n + 1) cin >> x[i];
    sort(x + 1 , x + 1 + n);
    if(k == 0){
    	if(x[1] == 1) cout << "-1" << endl;
    	else cout << 1 << endl;
    }
    else if(k == n) cout << x[n] << endl;
    else {
    	if(x[k] == x[k + 1]) cout << -1 << endl;
    	else cout << x[k] << endl;
    }
    return 0;
}