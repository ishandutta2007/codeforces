#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j)       for(int i = 0 ; i < j ; ++i)
#define REPNM(i,j,k)   for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define VI  vector<int> 
#define VPII vector<PII>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define endl "\n"
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define MAX 1000090
#define INF 0x3f3f3f3f


int n , m , x[MAX] , pre[MAX];
int32_t main(){
	cin >> n;
	REPNM(i , 1 , n + 1) cin >> x[i] , pre[i] = pre[i - 1] + x[i];
	cin >> m;
	REPNM(i , 1 , m + 1){
		int tmp;
		cin >> tmp;
		int ans = 1;
		RREP(i , 20 , 0){
			int to = ans + (1 << i);
			if(to > n) continue;
			if(pre[to - 1] + 1 > tmp) continue;
			ans = to;
		}
		cout << ans << endl;
	}
    return 0;
}