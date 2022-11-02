#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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
#define MAX 100900
#define INF 0x3f3f3f3f

class N{
public:
	int pri , siz;
	int val , sum;
	N *l , *r;
	N(int v){
		l = r = 0;
		pri = rand() , siz = 1;
		val = sum = v;
	}
};
int SIZ(N *now){ return now ? now->siz : 0; }
int SUM(N *now){ return now ? now->sum : 0; }
void Pull(N *now){
	now->siz = SIZ(now->l) + SIZ(now->r) + 1;
	now->sum = SUM(now->l) + SUM(now->r) + now->val;
}
N *Merge(N *a , N *b){
	if(!a || !b) return a ? a : b;
	if(a->pri > b->pri){
		a->r = Merge(a->r , b) , Pull(a);
		return a;
	}else {
		b->l = Merge(a , b->l) , Pull(b);
		return b;
	}
}
void SplitSiz(N *t , int k , N *&a , N *&b){
	if(!t) return a = b = 0 , void();
	if(SIZ(t->l) + 1 <= k)
		 a = t , SplitSiz(t->r , k - 1 - SIZ(t->l) , a->r , b);
	else b = t , SplitSiz(t->l , k , a , b->l);
	Pull(t);
}
void SplitVal(N *t , int v , N *&a , N *&b){
	if(!t) return a = b = 0 , void();
	if(t->val <= v)
		 a = t , SplitVal(t->r , v , a->r , b);
	else b = t , SplitVal(t->l , v , a , b->l);
	Pull(t);
}
void put(N *now){
	if(!now) return;
	if(now->l) put(now->l);
	cout << now->val << " ";
	if(now->r) put(now->r);
}
N *root = 0;
void det(int val){
	N *left , *right , *tma , *tmb;
	SplitVal(root , val , left , right);
	SplitSiz(left , SIZ(left) - 1 , tma , tmb);
	root = Merge(tma , right);
}
int query(int k){
	N *left , *right;
	SplitSiz(root , k , left , right);
	int ans = SUM(left);
	root = Merge(left , right);
	return ans;
}
int n , my = 0 , use[MAX];
vector<int> v[MAX] , xx;
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 0 , n){
		int q , w;
		cin >> q >> w;
		if(q == 0) my ++;
		else {
			use[q] ++;
			v[q].pb(w);
			xx.pb(w);
		}
	}
	priority_queue<PII> pq;
	pq.push(mp(0 , 0));
	int big = 0;
	REP(i , 0 , MAX){
		if(use[i]){
			big = max(big , use[i]);
			pq.push(mp(use[i] , i));
			sort(ALL(v[i]) , greater<int>());
		}
	}
	sort(ALL(xx));
	REP(i , 0 , xx.size()) root = Merge(root , new N(xx[i]));
	
	int ans = INF , res = 0;
	RREP(i , big , 0){
		while(pq.top().A > i){
			PII tmp = pq.top(); pq.pop();
			int val = v[tmp.B].back();
			v[tmp.B].pop_back();
			pq.push(mp(tmp.A - 1 , tmp.B));
			res += val , my ++;
			det(val);
		}
		int need = max(0 , pq.top().A + 1 - my);
		if(need > SIZ(root)) continue;
		else {
			int tohave = query(need);
			ans = min(ans , res + tohave);
		}
	}
	cout << ans << endl;
    return 0;
}