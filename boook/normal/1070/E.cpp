#include <bits/stdc++.h>
using namespace std;
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define IOS cin.tie(0) , cout.sync_with_stdio(0)
///------------------------------------------------
#define int long long
typedef pair<int , int> PII;

const int INF = 1e17;
const int MAX = 2e5 + 3;

void update(int from , int val , int bit[MAX]){
	for(int i = from ; i < MAX ; i += i & -i)
		bit[i] += val;	
}
int query(int from , int bit[MAX]){
	if(from == 0) return 0;
	int cnt = 0;
	for(int i = from ; i > 0 ; i -= i & -i)
		cnt += bit[i];
	return cnt;
}
int T , n , m , k , x[MAX] , bit[2][MAX];
int calc(int siz){
	int kk = siz % m == 0 ? siz - m : siz - siz % m;
	int l = 0 , r = n + 1;
	while(r - l > 1){
		int mid = (l + r) >> 1;
		if(query(mid , bit[0]) <= kk) l = mid;
		else r = mid;
	}
	// cout << "l = " << l << "siz = " << siz << " " << query(n , bit[0]) << " kk = " << kk << endl;
	return query(n , bit[1]) + query(l , bit[1]);
}
int32_t main(){
	IOS;
	cin >> T;
	REP(times , 0 , T){
		cin >> n >> m >> k;

		REP(i , 1 , n + 1) bit[0][i] = bit[1][i] = 0;
		REP(i , 1 , n + 1) cin >> x[i];


		priority_queue<PII> pq;

		int ansd = 1 , ans = 0 , lim = INF , sum = 0;

		REP(i , 1 , n + 1){
			if(x[i] >= lim) continue;
			pq.push(mp(x[i] , i));
			update(i ,    1 , bit[0]);
			update(i , x[i] , bit[1]);
			while(pq.size() && calc(pq.size()) > k){
				lim = pq.top().F;
				while(pq.size() && pq.top().F >= lim){
					int val = pq.top().F;
					int idx = pq.top().S;
					pq.pop();
					update(idx ,   -1 , bit[0]);
					update(idx , -val , bit[1]);
					// cout << "pop = " << val << endl;
				}
			}
			if(pq.size() > ans){
				ans = pq.size();
				ansd = pq.top().F;
			}
			// cout << "i = " << i << " " << calc(pq.size()) << " " << pq.size() << endl;
		}

		cout << ans << " " << ansd << endl;
	}
	return 0;
}