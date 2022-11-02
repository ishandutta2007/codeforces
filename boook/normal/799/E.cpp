#include <bits/stdc++.h>
using namespace std;
#define REP(i,j)       for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)   for(int i = j ; i < k ; i++)
#define RREP(i,j,k)    for(int i = j ; i >=k ; i--)
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
#define RI(i)       scanf("%d" , &i)
#define RII(i,j)    scanf("%d%d" , &i , &j)
#define RIII(i,j,k) scanf("%d%d%d" , &i , &j , &k)
#define RL(i)       scanf("%lld" , &i)
#define RLL(i,j)    scanf("%lld%lld" , &i , &j)
#define RLLL(i,j,k) scanf("%lld%lld%lld" , &i , &j , &k)
#define AS assert
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define int long long
#define MAX 200900
#define INF 30000000000000000LL

int n , m , k , ans , tmp;
int tma , tmb;
int val[MAX] , apo , bpo , pqsum;
set<int> a , b;
VI x[4];
priority_queue<int> pq;
priority_queue<int , vector<int> , greater<int> > mn;
int cmp(int q , int w){
	return val[q] < val[w];
}
int Find(int lim){
	// assert(pq.size() <= lim);
	while(pq.size() < lim){
		if(mn.size() == 0) return INF;
		else pq.push(mn.top()) , pqsum += mn.top() , mn.pop();
	}
	while(pq.size() > lim){
		if(pq.size() == 0) return INF;
		else mn.push(pq.top()) , pqsum -= pq.top() , pq.pop();
	}
	while(pq.size() && mn.size() && pq.top() > mn.top()){
		tma = pq.top() , pq.pop() , pqsum -= tma;
		tmb = mn.top() , mn.pop();
		pq.push(tmb) , pqsum += tmb;
		mn.push(tma) ;
	}
	return pqsum;
}
int Count(int now){
	// DBGG("now = " , now);
	if(now + x[1].size() < k || now + x[2].size() < k) return INF;
	int sum = (now > 0) ? x[0][now - 1] : 0 , cnt = max(0LL , k - now);
	if(cnt > x[1].size() || cnt > x[2].size()) return INF;
	if(cnt > 0) sum += x[1][cnt - 1] + x[2][cnt - 1];
	int C = m - cnt - cnt - now;
	// DB4("C = " , C , sum , bpo);
	if(C < 0) return INF;
	while(apo >= cnt) mn.push(apo == 0 ? x[1][apo] : x[1][apo] - x[1][apo - 1]) , apo --;
	while(bpo >= cnt) mn.push(bpo == 0 ? x[2][bpo] : x[2][bpo] - x[2][bpo - 1]) , bpo --;
	// DB4("now = " , now , sum , C);
	sum += Find(C);
	// DBGG("64" , mn.size());
	// if(now == 3){
	// 	while(pq.size()) cout << pq.top() << " " , pq.pop(); cout << endl;
	// 	while(mn.size()) cout << mn.top() << " " , mn.pop(); cout << endl;
	// }
	return sum;
}
int32_t main(){
	cin >> n >> m >> k;
	REP(i , n) cin >> val[i];
	cin >> tmp;
	REP(i , tmp) cin >> tma , a.insert(tma - 1);
	cin >> tmp;
	REP(i , tmp) cin >> tma , b.insert(tma - 1);
	REP(i , n){
		if(a.find(i) != a.end() && b.find(i) != b.end()) x[0].pb(i);
		else if(a.find(i) != a.end()) x[1].pb(i);
		else if(b.find(i) != b.end()) x[2].pb(i);
		else x[3].pb(i);
	}
	REP(i , 4) sort(ALL(x[i]) , cmp);


	// cout << "-------\n" ;
	// REP(i , 4) {for(auto j : x[i]) cout << val[j] << " " ; cout << endl;}


	for(auto i : x[3]) mn.push(val[i]);

	apo = (int)x[1].size() - 1 , bpo = (int)x[2].size() - 1;
	REP(i , 4){
		if(x[i].size() != 0) x[i][0] = val[x[i][0]];
		REPNM(j , 1 , x[i].size()) x[i][j] = val[x[i][j]] + x[i][j - 1];
	}


	ans = INF;
	REP(i , x[0].size() + 1){
		ans = min(ans , Count(i));
	}
	printf("%lld\n", ans == INF ? -1 : ans);
    return 0;
}