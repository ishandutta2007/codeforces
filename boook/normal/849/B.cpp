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
#define int long long
#define MAX 1010
#define INF 0x3f3f3f3f

int n , x[MAX];
int solve(int val){
	set<int> cc;
	REP(i , 1 , n + 1) cc.insert(x[i] - i * val);
	// REP(i , 1 , n + 1) cout << x[i] - i * val << " "; cout << endl;
	return cc.size() == 2;
}
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i] , x[i] += x[i];
	int ans = solve(x[2] - x[1]) | solve(x[3] - x[2]) | solve((x[3] - x[1]) / 2);
	cout << (ans ? "Yes" : "No") << endl;
    return 0;
}