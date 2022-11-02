/*input
5
1 2 3 4 5
3
3 5 3 5
1 5 5 1
1 5 1 5
*/
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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 200900
#define INF 0x3f3f3f3f

struct N{
	int pri , val , sml;
	N *l , *r;
	N(int _val){
		pri = rand() << 16 | rand();
		val = sml = _val;
		l = r = NULL;
	}
};
int SML(N *now){ return now ? now->sml : INF; }
void Pull(N *now){ now->sml = min(now->val , min(SML(now->l) , SML(now->r))); }
N *Merge(N *a , N *b){
	if(!a || !b) return a ? a : b;
	if(a->pri > b->pri)
		 return a->r = Merge(a->r , b) , Pull(a) , a;
	else return b->l = Merge(a , b->l) , Pull(b) , b;
}
void Split(N *t , int v , N *&a , N *&b){
	if(!t) return a = b = NULL , void();
	if(t->val <= v)
		 a = t , Split(t->r , v , a->r , b);
	else b = t , Split(t->l , v , a , b->l);
	Pull(t);
}
int n , m , x[MAX] , ans[MAX];
N *root[200];
void put(N *now){
	if(!now) return ;
	cout << now->val << " ";
	if(now->l) put(now->l);
	if(now->r) put(now->r);
}
N *Join(N *a , N *b){
	if(!a || !b) return a ? a : b;
	if(a->sml > b->sml) swap(a , b);
	N *left , *right;
	Split(a , SML(b) , left , right);
	return Join(right , Merge(left , b));
}
void Print(int val , N *now){
	if(!now) return;
	ans[now->val] = val;
	if(now->l) Print(val , now->l);
	if(now->r) Print(val , now->r);
}
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) root[x[i]] = Merge(root[x[i]] , new N(i));
	cin >> m;
	REP(i , 1 , m + 1){
		int l , r , a , b;
		cin >> l >> r >> a >> b;
		if(a == b) continue;
		N *left1 , *mid1 , *right1 , *tmp1;
		N *left2 , *mid2 , *right2 , *tmp2;
		Split(root[a] , r , tmp1 , right1);
		Split(tmp1 , l - 1 , left1 , mid1);

		Split(root[b] , r , tmp2 , right2);
		Split(tmp2 , l - 1 , left2 , mid2);
		root[a] = Merge(left1 , right1);
		root[b] = Merge(left2 , Merge(Join(mid1 , mid2) , right2));
	}
	REP(i , 1 , 100 + 1) Print(i , root[i]);
	REP(i , 1 , n + 1) cout << ans[i] << " "; cout << endl;
    return 0;
}