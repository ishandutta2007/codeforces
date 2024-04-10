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

int n , m , k;
string s;
int32_t main(){
    IOS;
    vector<int> sol , v;
    cin >> n >> m >> k >> s;
    sol.pb(-1);
    REP(i , 0 , s.size()) if(s[i] == '*') sol.pb(i);
    sol.pb(s.size());
    REP(i , 1 , sol.size()){
    	int l = sol[i - 1] + 1 , r = sol[i] - 1;
    	v.pb(r - l + 1);
    }
    int ans = 0 , cnt = 0;
    for(auto to : v){
    	int tmp = to / 2;
    	int v1 = min(m , tmp);
    	int v2 = min(k , tmp);
    	ans += v1 + v2;
    	m -= v1 , k -= v2;
    	cnt += to % 2;
    }
    int v1 = min(cnt , m);
    cnt -= v1;
   	ans += v1;
    int v2 = min(cnt , k);
    cnt -= v2;
    ans += v2;
    cout << ans << endl;
    return 0;
}