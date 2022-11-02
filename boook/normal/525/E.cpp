#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
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
#define MAX 4000000
#define INF 0x3f3f3f3f

int n , m , k , N;
int x[30] , p[30] , val[MAX];
VPII a , b;
void DFS1(int now , int sum , int usek){
	if(sum > k || usek > m) return ;
	else if(now >= N) a.pb(mp(sum , usek));
	else {
		DFS1(now + 1 , sum , usek);
		DFS1(now + 1 , sum + x[now] , usek);
		if(x[now] <= 18) DFS1(now + 1 , sum + p[x[now]] , usek + 1);
	}
}
void DFS2(int now , int sum , int usek){
	if(sum > k || usek > m) return ;
	else if(now >= n) b.pb(mp(sum , usek));
	else {
		DFS2(now + 1 , sum , usek);
		DFS2(now + 1 , sum + x[now] , usek);
		if(x[now] <= 18) DFS2(now + 1 , sum + p[x[now]] , usek + 1);
	}	
}
int F(int goal , int lim){
	int l = 0 , r = a.size();
	while(r - l > 1){
		int mid = (l + r) >> 1;
		if(a[mid].A < goal) l = mid;
		else if(goal < a[mid].A) r = mid;
		else {
			if(a[mid].B <= lim) l = mid;
			else r = mid;
		} 
	}
	if(a[l].A == goal) return val[l];
	return 0;
}
int32_t main(){
	cin >> n >> m >> k;
	REP(i , n) cin >> x[i];

	p[1] = 1;
    REPNM(i , 2 , 20) p[i] = p[i - 1] * i;

	if(n == 1){
		int ans = 0;
		if(x[0] <= 17 && m > 0 && p[x[0]] == k) ans ++;
		if(x[0] == k) ans ++;
		cout << ans << endl;
		return 0;
	}
	N = n / 2;
	DFS1(0 , 0 , 0);
	// DBGG("A = " , a.size());
	DFS2(N , 0 , 0);
	// DBGG("B = " , b.size());
	sort(ALL(a));
	// REP(i , a.size()) cout << a[i].A << " " << a[i].B << endl;
	// cout << "-----" << endl;
	// REP(i , b.size()) cout << b[i].A << " " << b[i].B << endl;
	val[0] = 1;
	REPNM(i , 1 , a.size()){
		if(a[i].A == a[i - 1].A) val[i] = val[i - 1] + 1;
		else val[i] = 1;
	}
	// DBGG("here" , "");
	int ans = 0;
	REP(i , b.size()){
		// DBGG(b[i].A , b[i].B);
		ans += F(k - b[i].A , m - b[i].B);
		// DBGG("ans = " , ans);
	}
	cout << ans << endl;
    return 0;
}