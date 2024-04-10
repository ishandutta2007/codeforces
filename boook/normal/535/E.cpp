#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j)       for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)   for(int i = j ; i < k ; i++)
#define RREP(i,j,k)    for(int i = j ; i >=k ; i--)
#define LREP(i,j)      for(LL  i = 0 ; i < j ; i++)
#define LREPNM(i,j,k)  for(LL  i = j ; i < k ; i++)
#define LRREP(i,j,k)   for(LL  i = j ; i >=k ; i--)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define LL  long long int
#define PII pair<int , int>
#define PLL pair< LL , LL >
#define VI  vector<int> 
#define VLL vector<LL> 
#define VPII vector<PII>
#define VPLL vector<PLL>
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
#define MAX 300000
#define INF 0x3f3f3f3f

int n;
PII x[MAX];
vector<PII> a , w;
map<PII , vector<int> > cc;
int cmp(PII q , PII w){
	if(q.A != w.A) return q.A > w.A;
	else return q.B > w.B; 
}
int cross(PII q , PII w , PII e){
	int tma = (q.A - w.A) * (q.B - e.B) * e.A * w.B;
	int tmb = (q.B - w.B) * (q.A - e.A) * w.A * e.B;
	// DB4("tma = " , tma , tmb , "");
	if(tma == tmb) return 0;
	return (tma < tmb) ? -1 : 1;
}
int32_t main(){
	cin >> n;
	REP(i , n){
		cin >> x[i].A >> x[i].B;
		if(cc.find(x[i]) == cc.end()) a.pb(x[i]);
		cc[x[i]].pb(i);
	}
	sort(ALL(a) , cmp);
	REP(i , a.size()){
		while(w.size() > 1 && cross(w[w.size() - 2] , w[w.size() - 1] , a[i]) == -1) w.pop_back();
		w.pb(a[i]);
	}

	// cout << "------" << endl;
	// REP(i , w.size()) DBGG(w[i].A , w[i].B);

	VI ans;
	REP(i , w.size()){
		if(i != 0 && w[i].B <= w[i - 1].B) break;
		for(auto j : cc[w[i]]) ans.pb(j);
	}
	sort(ALL(ans));
	for(auto i : ans) cout << i + 1 << " " ; cout << endl;
    return 0;
}