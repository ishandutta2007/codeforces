#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/priority_queue.hpp>
using namespace std;
// using namespace __gnu_pbds;
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
#define DBGG(i,j)     if(debug) cout << i << " " << j << endl;
#define DB4(i,j,k,l)  if(debug) cout << i << " " << j << " " << k << " " << l <<endl;
#define RI(i)       scanf("%d" , &i)
#define RII(i,j)    scanf("%d%d" , &i , &j)
#define RIII(i,j,k) scanf("%d%d%d" , &i , &j , &k)
#define RL(i)       scanf("%lld" , &i)
#define RLL(i,j)    scanf("%lld%lld" , &i , &j)
#define RLLL(i,j,k) scanf("%lld%lld%lld" , &i , &j , &k)
#define AS assert
#define IOS cin.tie() , cout.sync_with_stdio(0);
///------------------------------------------------------------
#define MAX 100090
#define INF 0x3f3f3f3f
#define debug 1

void Pre(){}

void Init(){}

void Read(){}

void Solve(){}
typedef pair<PII , int> PIII;
int n , m , money;
PII bug[MAX]; ///  , i
PIII stu[MAX]; ///abilities	money , i
vector<int> ans;
int g[MAX];
int F(int now){
	ans.clear();
	int po = n , work = m , ccost = 0;
	priority_queue<PII> pq;
	while(work > 0){

		// DBGG("here" , now);
		// DBGG(stu[po].A.A , bug[work].A);

		while(po > 0 && stu[po].A.A >= bug[work].A)
			pq.push(mp(-stu[po].A.B , stu[po].B)) , po --;
		// DBGG("56" , po);
		work -= now;
		if(pq.empty()) return 0;
		else ccost += -pq.top().A , ans.pb(pq.top().B) , pq.pop();
		if(ccost > money) return 0;
	}
	return 1;
}
int main(){
	RIII(n , m , money);
	REPNM(i , 1 , m + 1) RI(bug[i].A) , bug[i].B = i;
	REPNM(i , 1 , n + 1) RI(stu[i].A.A) , stu[i].B = i;
	REPNM(i , 1 , n + 1) RI(stu[i].A.B);
	sort(bug + 1 , bug + m + 1);
	sort(stu + 1 , stu + n + 1);


	// REPNM(i , 1 , m + 1) cout << bug[i].A << " " ; cout << endl;
	// REPNM(i , 1 , n + 1) cout << stu[i].A.A << " " << stu[i].A.B << endl;
	// cout << F(0) << endl;
	// cout << F(1) << endl;
	// cout << F(2) << endl;
	// cout << F(3) << endl;
	// cout << F(4) << endl;
	// cout << F(5) << endl;
	// cout << F(6) << endl;


	int l = 0 , r = m + 10;
	while(r - l > 1){
		int mid = (l + r) / 2;
		if(F(mid)) r = mid;
		else l = mid;
	}
	// DBGG(l , r);
	F(r);
	if(r == m + 10) puts("NO");
	else {
		puts("YES");

		int ppo = m;
		// DBGG("l = " , r);
		for(auto i : ans){
			REP(j , r){
				if(ppo == 0) break;
				else g[bug[ppo].B] = i , ppo--; 
			}
		}
		printf("%d", g[1]);
		REPNM(i , 2 , m + 1) printf(" %d", g[i]);
		puts("");
		// cout << ans.size() << endl;
		// printf("%d\n", );
	}
    return 0;
}