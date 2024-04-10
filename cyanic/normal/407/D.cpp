#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=405,M=160000;
int a[N][N],r[N][N],L[N*N],R[N*N],p[N*N];
vector<pii> q[M+5];
int n,m,ans,tot;
vi c[N];

void upd(int i,int x,int y){
	r[i][x]=min(r[i][x],y);
}

int main(){
	read(n),read(m);
	rep(i,1,n) rep(j,1,m){
		read(a[i][j]);
	}
	rep(U,1,n) {
		memset(r,0x3f,sizeof r);
		rep(i,1,M){
			q[i].clear();
		}
		rep(i,1,m) rep(j,U,n){
			if(q[a[j][i]].size()&&q[a[j][i]].back().fi==i){
				r[j][i]=i;
				continue;
			}
			q[a[j][i]].pb(mp(i,j));
		}
		tot=0;
		rep(i,1,M){
			vector<pii> &v=q[i];
			int sz=SZ(v);
			rep(j,0,sz-1){
				p[++tot]=v[j].fi;
				L[tot]=tot-1;
				R[tot]=tot+1;
				if(j==0) L[tot]=0;
				if(j==sz-1) R[tot]=0;
				c[v[j].se].pb(tot);
			}
		}
		per(D,n,U){
			for(auto t:c[D]){
				if(!L[t]&&!R[t]) continue;
				if(!L[t]){
					upd(D,p[t],p[R[t]]);
					L[R[t]]=L[t];
					continue;
				}
				if(!R[t]){
					upd(D,p[L[t]],p[t]);
					R[L[t]]=R[t];
					continue;
				}
				upd(D,p[L[t]],p[t]);
				upd(D,p[t],p[R[t]]);
				L[R[t]]=L[t],R[L[t]]=R[t];
			}
			c[D].clear();
		}
		rep(D,U,n) rep(i,1,m){
			r[D][i]=min(r[D][i],r[D-1][i]);
		}
		rep(D,U,n){
			int r=m;
			per(l,m,1){
				r=min(r,::r[D][l]-1);
				ans=max(ans,(D-U+1)*(r-l+1));
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}