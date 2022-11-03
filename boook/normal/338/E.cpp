/*input
11 10 80
35 1 70 25 79 59 63 65 6 46
92 96 43 28 37 92 5 3 54 93 83
*/
// 16 12 80
// 35 1 70 25 79 59 63 65 6 46 82 28 
// 62 92 96 43 28 37 92 5 3 54 93 83 22 17 19 96

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
#define int long long
#define MAX 150900
#define INF 0x3f3f3f3f

struct node{
	int sml , val , pri , siz , tag;
	node *l , *r;
	node(int _val){ sml = val = _val , pri = rand() , siz = 1 , tag = 0 , l = r = NULL; }
};
int SIZ(node *now){ return now ? now->siz : 0; }
int VAL(node *now){ return now ? now->sml : INF; }
void Push(node *now){
	if(now->tag != 0){
		if(now->l){
			now->l->tag += now->tag;
			now->l->val += now->tag;
			now->l->sml += now->tag;
		}
		if(now->r){
			now->r->tag += now->tag;
			now->r->val += now->tag;
			now->r->sml += now->tag;
		}
		now->tag = 0;
	}
}
void Pull(node *now){
	now->siz = SIZ(now->l) + SIZ(now->r) + 1;
	now->sml = min(now->val , min(VAL(now->l) , VAL(now->r)));
}
node *Merge(node *a , node *b){
	if(!a || !b) return a ? a : b;
	if(a->pri > b->pri){
		Push(a) , a->r = Merge(a->r , b) , Pull(a);
		return a;
	}
	else {
		Push(b) , b->l = Merge(a , b->l) , Pull(b);
		return b;
	}
}
void Split(node *t , int k , node *&a , node *&b){
	if(!t) return a = b = NULL , void();
	Push(t);
	if(SIZ(t->l) + 1 <= k)
		 a = t , Split(t->r , k - 1 - SIZ(t->l) , a->r , b);
	else b = t , Split(t->l , k , a , b->l);
	Pull(t);
}
int query(node *now , int val , int presum){
	if(now == NULL) return presum;
	Push(now);
	int v = now->val + presum + SIZ(now->l) + 1;
	if(v <= val) return query(now->r , val , presum + SIZ(now->l) + 1);
	else 		 return query(now->l , val , presum); 
}
node *Insert(node *root , int val , int k){
	node *left , *right;
	Split(root , k , left , right);
	if(right){
		right->tag --;
		right->sml --;
		right->val --;
	}
	return Merge(left , Merge(new node(val - k - 1) , right));
}
node *Erase(node *root , int k){
	node *left , *mid , *right , *tmp;
	Split(root , k , tmp , right);
	Split(tmp , k - 1 , left , mid);
	if(right){
		right->tag ++;
		right->sml ++;
		right->val ++;
	}
	return Merge(left , right);
}
void put(node *now){
	if(now == NULL) return ;
	Push(now);
	if(now->l) put(now->l);
	cout << now->val << " ";
	if(now->r) put(now->r);
}
node *root = NULL;
int n , m , h , a[MAX] , b[MAX];
int ID(int now){ return upper_bound(a + 1 , a + 1 + m , now) - 1 - a; }
int32_t main(){
	IOS;
	srand(time(NULL));
	cin >> n >> m >> h;
	REP(i , 1 , m + 1) cin >> a[i] , a[i] = h - a[i];
	REP(i , 1 , n + 1) cin >> b[i];
	sort(a + 1 , a + 1 + m);

	REP(i , 1 , n + 1) b[i] = ID(b[i]);

	REP(i , 1 , m + 0){
		int v1 = query(root , b[i] , 0);
		root = Insert(root , b[i] , v1);
	}
	// REP(i , 1 , m + 1) cout << a[i] << " " ; cout << endl;
	// REP(i , 1 , n + 1) cout << b[i] << " " ; cout << endl;
	int pos = 1 , ans = 0;
	REP(i , m , n + 1){
		// cout << "before";put(root),cout << endl;
		int v1 = query(root , b[i] , 0);
		root = Insert(root , b[i] , v1);
		if(root->sml >= 0) ans ++;
		// put(root),cout << endl;
		
		int v2 = query(root , b[pos] , 0);
		root = Erase(root , v2) , pos ++;
		// DB4("V1 = " , v1 , "v2 = " , v2);
		// cout << "after";put(root),cout << endl;
	}
	cout << ans << endl;
    return 0;
}