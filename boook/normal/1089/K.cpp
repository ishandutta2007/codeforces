#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int long long 
#define MAX 1000006

const ll INF = (1ll<<45);
int bit[MAX];
void update(int from , int val){
	for(int i = from ; i < MAX ; i += i & -i)
		bit[i] += val;
}
int query(int from){
	if(from == 0) return 0;
	int cnt = 0;
	for(int i = from ; i > 0 ; i -= i & -i)
		cnt += bit[i];
	return cnt;
}
int query(int l , int r){
	return query(r) - query(l - 1);
}
struct Node {
	Node *lc,*rc;
	ll mx,tag;
	Node():lc(NULL),rc(NULL),mx(-INF),tag(0){}
	void pull() {
		mx = max(lc->mx,rc->mx);
	}
};

const int N = 1000002;

Node* Build(int L,int R) {
	Node* node = new Node();
	if (L == R) {
		node->mx = -N+L;
		return node;
	}
	int mid=(L+R)>>1;
	node->lc = Build(L,mid);
	node->rc = Build(mid+1,R);
	node->pull();
	return node;
}

void push(Node* node,int L,int R) {
	if (L == R) node->tag = 0;
	if (node->tag == 0) return;
	node->lc->mx += node->tag;
	node->rc->mx += node->tag;
	node->lc->tag += node->tag;
	node->rc->tag += node->tag;
	node->tag = 0;
	return;
}

void modify(Node* node,int L,int R,int l,int r,ll val) {
	if (l>R || L>r) return;
	else if (l<=L && R<=r) {
		node->mx += val;
		node->tag += val;
		return;
	}
	push(node,L,R);
	int mid=(L+R)>>1;
	modify(node->lc,L,mid,l,r,val);
	modify(node->rc,mid+1,R,l,r,val);
	node->pull();
	return;
}

ll query(Node* node,int L,int R,int l,int r) {
	if (l>R || L>r) return -INF;
	else if (l<=L && R<=r) return node->mx;
	push(node,L,R);
	int mid=(L+R)>>1;
	return max( query(node->lc,L,mid,l,r) , query(node->rc,mid+1,R,l,r));
}
#define REP(i,j,k) for (int i=j;i<k;++i)

int n , x[N][2];
int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	// build(1 , 1 , N);
	Node* root = Build(1,N);
	string in; int v1 , v2;
	REP(i , 1 , n + 1){
		cin >> in;
		if(in == "?"){
			cin >> v1;
			// cout << "the ans = ";
			cout << query(root , 1 , N , 1 , v1) + (N-v1) - query(v1+1,MAX-1) << '\n';
		}
		else if(in == "+"){
			cin >> v1 >> v2;
			x[i][0] = v1;
			x[i][1] = v2;
			modify(root , 1 , N , 1, x[i][0] , x[i][1]);
			update(v1,v2);
		}
		else if(in == "-"){
			cin >> v1;
			modify(root , 1 , N , 1, x[v1][0] , -x[v1][1]);
			update(x[v1][0],-x[v1][1]);
		}
	}
	return 0;
}