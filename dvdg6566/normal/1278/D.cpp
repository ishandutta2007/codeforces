#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb emplace_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1000000000
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define MAXN 1000110
ll MOD = 1e9+7;

int fw[MAXN];
void update(int x, int v) {
    for (; x<MAXN; x+=x&(-x)) fw[x] += v; 
}
int sum(int x) {
    int res = 0;
    for(; x; x-=x&(-x)) res += fw[x];
    return res;
}

ll N,E,a,b;
pi A[MAXN];
int L[MAXN];

struct node{
	int s,e,m,v;
	node *l,*r;
	node(int _s,int _e):s(_s), e(_e){
		m=(s+e)/2;
		v=0;
		if (s!=e){l=new node (s,m); r=new node(m+1,e);}
	}
	void up(int x, int val){
		if (s==e){
			v=val;
			return;
		}
		if (x <= m)l->up(x,val);
		else r->up(x,val);
		v=max(l->v,r->v);
	}
	int query(int x, int y){
		if (x==s&&e==y)return v;
		if (y <= m)return l->query(x,y);
		else if (x > m)return r->query(x,y);
		return max(l->query(x,m), r->query(m+1,y));
	}
}*root;

int S[MAXN],C[MAXN];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	if (N==1){
		cout<<"YES";return 0;
	}
	for (int i=1;i<=N;++i){
		cin>>A[i].f>>A[i].s;
	}
	sort(A+1,A+N+1);
	root = new node(1,MAXN);

	for (int i=1;i<=N;++i){
		int st = A[i].f;
		int en = A[i].s;
		int t = sum(en) - sum(st);
		update(en,1);
		// cout<<st<<' '<<en<<' '<<t<<'\n';
		E += t;
	}
	if (E+1!=N){
		cout<<"NO\n";
		return 0;
	}
	reverse(A+1,A+N+1);
	for (int i=1;i<=2*N;++i)S[i]=MAXN;
	for (int i=1;i<=N;++i){
		int st = A[i].f;
		int en = A[i].s;
		int lst = max(en, root->query(st,en));
		root->up(st,lst);
		S[lst] = min(S[lst],st);
		C[lst]++;
	}
	memset(fw,0,sizeof(fw));
	for (int i=1;i<=2*N;++i){
		update(i,C[i]);
	}
	for (int i=1;i<2*N;++i)if (S[i]!=MAXN){
		int dst = i - S[i]+1;
		int cnt = sum(i) - sum(S[i]-1);
		// cout<<cnt<<' '<<dst<<'\n';
		if (cnt*2==dst){cout<<"NO\n";return 0;}
	}
	cout<<"YES";
}