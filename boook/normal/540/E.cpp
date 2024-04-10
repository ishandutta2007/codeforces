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
#define MAX 
#define INF 0x3f3f3f3f

typedef tree< int , null_type , greater< int > ,rb_tree_tag , tree_order_statistics_node_update> TREE;
set<int> cc;
map<int , int> ma;
VI x;
int F(int now){
	return upper_bound(ALL(x) , now) - x.begin();
}
int32_t main(){
	int n;
	cin >> n;
	REP(i , n){
		int q , w;
		cin >> q >> w;
		int tma = 1 , tmb = 1;
		if(ma.find(q) == ma.end()) cc.insert(q) , ma[q] = q;
		if(ma.find(w) == ma.end()) cc.insert(w) , ma[w] = w;
		swap(ma[q] , ma[w]);
	}
	int ans = 0;
	for(auto i : cc) x.pb(i);
	TREE tr;
	for(auto i = ma.begin() ; i != ma.end() ; i ++){
		tr.insert(i->B); 
		ans += tr.order_of_key(i->B);
		// DB4(54 , i->B , tr.order_of_key(i->B) , "");
		if(i->B > i->A){
			//i->A + 1 ~ i->B - 1
			// DBGG(60 , i->B - 1 - (i->A + 1) + 1);
			// DBGG(i->B - 1 , F(i->B - 1));
			// DBGG(i->A , F(i->A));
			ans += i->B - 1 - (i->A + 1) + 1 - (F(i->B - 1) - F(i->A));
			// ans += lower_bound(ALL(x) , i->B) - x.begin();
			// ans -= lower_bound(ALL(x) , i->A) - x.begin();
		}
		else ans += i->A - 1 - i->B - (F(i->A - 1) - F(i->B));
		// DBGG("ans = " , ans);
	}
	cout << ans << endl;
    return 0;
}