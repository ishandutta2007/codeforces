#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const int INF=1e9 + 5;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=1e5+5;


int n,k;
#define maxn 2*N+5
#define max_logn 20
struct SparseMin{
    int log[maxn];
    int dp[max_logn][maxn];
    SparseMin(){
        log[1] = 0;
        for (int i = 2; i < maxn; i++)
            log[i] = log[i/2] + 1;
    }
    void build(vector<int> b)
    {
        int n=b.size();
        for (int i = 0; i < n; ++i){
            dp[0][i]=b[i];
        }
        for (int j = 1; j < max_logn; j++)
            for (int i = 0; i + (1 << j) < maxn; i++)
                dp[j][i] = min(dp[j - 1][i], dp[j - 1][i + (1 << (j - 1))]);
    }
    int query(int l,int r)
    {
        if(l>r)return M;
        int j=log[r-l+1];
        return min(dp[j][l],dp[j][r-(1<<j)+1]);
    }
}spmin;


int get(int l,int r){
	if(r-l+1 >= n){
		return spmin.query(0,n-1);
	}
	l%=n,r%=n;
	if(r >= l){
		return spmin.query(l,r);
	}
	else{
		return min(spmin.query(0,r),spmin.query(l,n-1));
	}
}


struct node{
	node *left,*right;
	int val=INF;
	int lazy=0;
};

node ns[35*N];
int cnt=0;

node* create(int tl,int tr)
{
	node *tmp;
	if(cnt<35*N)tmp=&ns[cnt++];
	else tmp = new node();
	tmp->val=get(tl,tr);
	tmp->left=NULL;
	tmp->right=NULL;
	tmp->lazy=0;
	return tmp;
}
struct dynamicsegtree{
	node *root;
	dynamicsegtree()
	{
		root=create(0,M);
	}
	
	void pushdown(node *x){
		if(x -> lazy){
			apply(x->left,x->lazy);
			apply(x->right,x->lazy);
			x -> lazy=0;
		}
	}
	
	void apply(node *x, int val){
		x->val=val;
		x->lazy=val;
	}
	
	int query(node *x,int tl,int tr,int l,int r){
		if(l>tr || r<tl)
			return INF;
		if(tl>=l && tr<=r)
			return x->val;
		int tm=tl + (tr-tl)/2;
		
		if(!x->left)x->left = create(tl,tm);
		if(!x->right)x->right = create(tm+1,tr);
		pushdown(x);
		
		return min(query(x->left,tl,tm,l,r),query(x->right,tm+1,tr,l,r));
	}
	int query(int l,int r){
		return query(root,0,M,l,r);
	}
	
	void update(node *x,int tl,int tr,int l,int r,int val)
	{
		if(l > tr || r < tl)return;
		if(tl >= l && tr <= r)
		{
			apply(x,val);
			return;
		}
		int tm=tl + (tr-tl)/2;
		
		if(!x->left)x->left = create(tl,tm);
		if(!x->right)x->right = create(tm+1,tr);
		pushdown(x);
		
		update(x->left,tl,tm,l,r,val);
		update(x->right,tm+1,tr,l,r,val);
		x->val = min(x->left->val, x->right->val);
	}
	void upd(int l,int r,int val){
		return update(root,0,M,l,r,val);
	}
} t;

vector<int> b;

void solve(){
	cin>>n>>k;
	b.resize(n);
	rep(i,0,n){
		cin>>b[i];
	}
	
	spmin.build(b);
	
	// cout<<get(7,8)<<"\n";
	
	int q;
	cin>>q;
	rep(i,0,q){
		int z,l,r;
		cin>>z>>l>>r;
		l--;
		r--;
		if(z==1){
			int x;
			cin>>x;
			t.upd(l,r,x);
		}
		else{
			cout<<t.query(l,r)<<"\n";
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}