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
#define MAX 100500
#define INF 0x3f3f3f3f

int n , x[MAX] , l[MAX] , eat[MAX] , die[MAX];
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];

    int big = 0;
    REP(i , 1 , n + 1){
		big = max(big , x[i]);
		if(big == x[i]) die[i] = 0 , l[i] = i;
		else if(x[i - 1] > x[i]){
			die[i] = 1 , l[i] = i - 1 , eat[i - 1] ++;
		}
		else {
			int now = i - 1;
			while(!(x[now] > x[i] && (die[now] == 0 || eat[now] < die[now]))) now = l[now];
			l[i] = now , eat[now] ++ , die[i] = eat[now];
		}
    }
    // REP(i , 1 , n + 1) cout << die[i] << " "; cout << endl;
    // REP(i , 1 , n + 1) cout << eat[i] << " "; cout << endl;
    // REP(i , 1 , n + 1) cout << l[i] << " "; cout << endl;
    int ans = die[1];
    REP(i , 1 , n + 1) ans = max(ans , eat[i]);
    cout << ans << endl;
    return 0;
}