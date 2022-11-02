#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
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
#define MAX 400900
#define INF 0x3f3f3f3f

int n , m , x[MAX] , nxt[MAX] , use[MAX];
__gnu_pbds::priority_queue<PII>::point_iterator id[MAX];
int32_t main(){
	IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> x[i];

    RREP(i,  n , 1) use[i] = n + 1;
    RREP(i , n , 1) nxt[i] = use[x[i]] , use[x[i]] = i;
    RREP(i , n , 1) use[i] = 0;
    
    __gnu_pbds::priority_queue<PII> pq;
    int ans = 0;
    REP(i , 1 , n + 1){
    	if(use[x[i]]){
    		pq.modify(id[x[i]] , mp(nxt[i] , x[i]));
    	}
    	else {
    		if(pq.size() == m){
    			PII tmp = pq.top(); pq.pop();
    			use[tmp.B] = 0;
    		}
    		ans ++;
    		use[x[i]] = 1;
    		id[x[i]] = pq.push(mp(nxt[i] , x[i]));
    	}
    }
    cout << ans << endl;
    return 0;
}