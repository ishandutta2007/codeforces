#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL , LL> PLL;
#define REP(i,j)      for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)  for(int i = j ; i < k ; i++)
#define RREP(i,j,k)   for(int i = j ; i >=k ; i--)
#define LREP(i,j)      for(LL i = 0 ; i < j ; i++)
#define LREPNM(i,j,k)  for(LL i = j ; i < k ; i++)
#define LRREP(i,j,k)   for(LL i = j ; i >=k ; i--)
#define pb   push_back
#define mp   make_pair
#define A    first
#define B    second
#define MEM(i,j)   memset(i,j,sizeof i)
#define ALL(i)     i.begin(),i.end()
#define DB()          if(debug)
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l <<endl
#define RI(i)       scanf("%d" , &i)
#define RII(i,j)    scanf("%d%d" , &i , &j)
#define RIII(i,j,k) scanf("%d%d%d" , &i , &j , &k)
#define RL(i)       scanf("%lld" , &i)
#define RLL(i,j)    scanf("%lld%lld" , &i , &j)
#define RLLL(i,j,k) scanf("%lld%lld%lld" , &i , &j , &k)
#define AS assert
#define IOS cin.tie() , cout.sync_with_stdio(0);
///------------------------------------------------------------
#define MAX 500900
#define INF 0x3f3f3f3f
#define debug 1

class N{
public:
	int x , v , ty , i;
	N(int x_ , int v_ , int ty_ , int i_){
		x = x_ , v = v_ , ty = ty_ , i = i_;
	}
};

LL ans[MAX] ;
int bit[MAX] , x[MAX] , n , m;
void update(int from , int v){
	for(int i = from ; i < MAX ; i += i & -i) bit[i] += v;
}
int query(int from){
	int ans = 0;
	for(int i = from ; i > 0 ; i -= i & -i) ans += bit[i];
	return ans;
}
void did(N &now){
	if(now.ty == 1) ans[now.i] += query(n) - query(now.v);
	else ans[now.i] -= query(n) - query(now.v);
}
void did2(N &now){
	if(now.ty == 1) ans[now.i] += query(now.v);
	else ans[now.i] -= query(now.v);
}
vector<N> sol;
int op[MAX] , opo;
void solve(int l , int r){
	if(l == r) return;
	
	int mid = (l + r) / 2;

	solve(l , mid);
	solve(mid + 1 , r);


	vector<N> tmp , re;

	int lpo = l , rpo = mid + 1;

	int opo = 0;

	while(lpo < mid + 1 || rpo < r + 1){
		if(rpo == r + 1) tmp.pb( sol[lpo ++] ) , op[opo++] = 0;
		else if(lpo == mid + 1) tmp.pb( sol[rpo ++] ) , op[opo++] = 1;
		else if(sol[lpo].x <= sol[rpo].x) tmp.pb( sol[lpo ++] ) , op[opo++] = 0;
		else tmp.pb( sol[rpo ++] ) , op[opo++] = 1;
	}

	REP(i , tmp.size()){
		if(op[i] == 0) update(tmp[i].v , tmp[i].ty) , re.pb(tmp[i]);
		else did(tmp[i]);
	}
	for(auto i : re) update(i.v , -i.ty);
	RREP(i , tmp.size() - 1 , 0){
		if(op[i] == 0) update(tmp[i].v , tmp[i].ty);
		else did2(tmp[i]);
	}
	for(auto i : re) update(i.v , -i.ty);

	REPNM(i , l , r + 1) sol[i] = tmp[i - l];

}
int main(){
	RII(n , m);

	REPNM(i , 1 , n + 1) x[i] = i , sol.pb(N(i , i , 1 , 0));

	REPNM(i , 1 , m + 1){
		int q , w;
		RII(q , w);
		sol.pb(N(q , x[q] , -1 , i));
		sol.pb(N(w , x[w] , -1 , i));
		sol.pb(N(q , x[w] , 1 , i));
		sol.pb(N(w , x[q] , 1 , i));
		swap(x[q] , x[w]);
	}
	
	solve(0 , sol.size() - 1);

	REPNM(i , 1 , m + 1) ans[i] += ans[i - 1];

	REPNM(i , 1 , m + 1) printf("%lld\n", ans[i]);


    return 0;
}