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
#define MAX 1010
#define INF 0x3f3f3f3f

int n , v[15] , u[15] , sol[15];
string s[MAX];
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> s[i];
    REP(i , 1 , n + 1){
    	int base = 1;
    	RREP(j , (int)(s[i].size()) - 1 , 0) v[s[i][j] - 'a'] += base , base *= 10;
    	u[s[i][0] - 'a'] = 1;
    }
    REP(i , 0 , 10) sol[i] = i;
    int ans = 1e12;
    do{
    	if(u[sol[0]]) continue;
    	int val = 0;
    	REP(i , 0 , 10) val += v[sol[i]] * i;
    	ans = min(ans , val);
    }while(next_permutation(sol , sol + 10));
    cout << ans << endl;
    return 0;
}