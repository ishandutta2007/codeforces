#include<bits/stdc++.h>
using namespace std;
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
#define RREP(i , j , k) for(int i = j ; i >= k ; i --)
class N{
public:
	int v , siz , pri;
	N *l , *r;
	N(int V){
		v = V , siz = 1 , pri = rand();
		l = r = 0;
	}
};
int SIZ(N *now){ return now ? now->siz : 0; }
void Pull(N *now){
	now->siz = SIZ(now->l) + SIZ(now->r) + 1;
}
N *Merge(N *a , N *b){
	if(!a || !b) return a ? a : b;
	if(a->pri > b->pri){
		a->r = Merge(a->r , b);
		Pull(a);
		return a;
	}
	else{
		b->l = Merge(a , b->l); 
		Pull(b);
		return b;
	}
}
void Split(N *t , int k , N *&a , N *&b){
	if(!t) return a = b = 0 , void();
	if(SIZ(t->l) + 1 <= k)
		a = t , Split(t->r , k - 1 - SIZ(t->l) , a->r , b);
	else b = t , Split(t->l , k , a , b->l);
	Pull(t);
}
N *root = 0;
int n , m , use[1200000] , po = 1;
void put(N *now){
	if(now->l) put(now->l);
	if(now->v) cout << now->v << " ";
	else {
		while(use[po]) po ++;
		cout << po++ << " ";
	}
	if(now->r) put(now->r);
}

void solve(int a , int b){
	N *left , *mid , *right , *tmp;
	Split(root , b , tmp , right);
	Split(tmp , 1 , left , mid);
	if(left->v == 0 && use[a] == 0){
		use[a] = 1 , left->v = a;
	}
	if(left->v != a){
		cout << -1 << endl;
		exit(0);
	}
	root = Merge(mid , Merge(left , right));
}
int aa[1000009][2];
int main(){
	cin.tie(0) , cout.sync_with_stdio(0);
	srand(time(NULL));
	cin >> n >> m;
	REP(i , 0 , n) root = Merge(root , new N(0));
	REP(i , 0 , m){
		cin >> aa[i][0] >> aa[i][1];
	}
	RREP(i , m - 1 , 0){
		solve(aa[i][0] , aa[i][1]);
	}
	put(root) , puts("");
  	return 0;
}