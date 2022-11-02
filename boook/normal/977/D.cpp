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
#define MAX 10000
#define INF 0x3f3f3f3f

int n , x[MAX];
int cmp(int q , int w){
	int aa = q , bb = w;
	int v1 = 0 , v2 = 0;
	while(aa % 3 == 0) v1 ++ , aa /= 3;
	while(bb % 3 == 0) v2 ++ , bb /= 3;
	if(v1 != v2) return v1 > v2;
	else return q < w;
}
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    sort(x + 1 , x + 1 + n , cmp);
    REP(i , 1 , n + 1) cout << x[i] << " " ; cout << endl;
    return 0;
}