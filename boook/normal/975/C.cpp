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
#define MAX 200900
#define INF 0x3f3f3f3f

int n , m , a[MAX] , b[MAX] , p[MAX];

int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> a[i];
    REP(i , 1 , n + 1) p[i] = p[i - 1] + a[i];

    REP(i , 1 , m + 1) cin >> b[i];
    int now = 1 , base = 0;
    REP(i , 1 , m + 1){
    	int val = base + b[i];
    	if(p[n] - p[now - 1] <= val){
    		cout << n << endl;
    		now = 1 , base = 0;
    	}
    	else {
    		int from = now;
    		now -- ;
    		RREP(j , 20 , 0){
    			int to = now + (1 << j);
    			if(to <= n && p[to] - p[from - 1] <= val) now = to;
    		}
    		cout << n - now << endl;
    		base = val - (p[now] - p[from - 1]);
    		// DB4("now = " , now , "base = " , base);
    		now ++;
    	}
    }
    return 0;
}