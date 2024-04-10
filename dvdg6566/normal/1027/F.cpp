#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;
typedef vector<pi> vpi;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define MAXN 2001000

vpi V[MAXN];
vi des;
vpi A;
int N,a,b,c,ans;
bool vis[MAXN];
vi tmp;

void dfs(int x, int p){
	tmp.pb(x);
	for (auto v:V[x])if (v.f != p){
		if (v.s >= 3){
			cout<<-1;
			exit(0);
		}
		if (v.s == 2)a+=2;
		if (vis[v.f]){
			++a;
			if (a > 2){
				cout<<-1;
				exit(0);
			}
			continue;
		}
		vis[v.f]=1;
		dfs(v.f,x);
	}
}

int main(){
	// freopen("in.txt","r",stdin);
	cin>>N;
	for (int i=0;i<N;++i){
		cin>>a>>b;
		des.pb(a); des.pb(b);
		A.pb(mp(a,b));
	}
	sort(ALL(des));
	des.resize(unique(ALL(des)) - des.begin());
	sort(ALL(A));
	for (int i=0;i<N;++i){
		A[i].f = lb(ALL(des), A[i].f)-des.begin();
		A[i].s = lb(ALL(des), A[i].s)-des.begin();
		int a=A[i].f;
		int b=A[i].s;
		if (SZ(V[a]) && V[a].back().f == b){
			++V[a].back().s;
		}else{
			V[a].pb(mp(b,1));
		}
		if (SZ(V[b]) && V[b].back().f == a){
			++V[b].back().s;
		}else{
			V[b].pb(mp(a,1));
		}
	}
	N = SZ(des)-1;
	for (int i=0;i<N;++i){
		tmp.clear();
		a=0;
		b=c=-1;
		if (vis[i])continue;
		vis[i]=1;
		dfs(i,-1);
		assert(a%2==0);
		sort(ALL(tmp));
		if (a > 2){
			cout<<-1;
			return 0;
		}
		if (a == 2)ans = max(ans, tmp.back());
		else ans = max(ans,tmp[SZ(tmp)-2]);
	}
	cout<<des[ans];
}