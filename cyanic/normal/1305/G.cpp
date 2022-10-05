#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
mt19937 rnd((long int)(new char));
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=1<<18;
int pa[N],cur[N],val[N],a[N],n,con;
pii f[N],g[N];
ll ans;

int gp(int x){
	return pa[x]==x?x:pa[x]=gp(pa[x]);
}
void upd(int x,pii y){
	if(y>f[x]){
		if(f[x].se!=y.se) g[x]=f[x];
		f[x]=y;
	}
	else if(y>g[x]&&f[x].se!=y.se){
		g[x]=y;
	}
}

int main(){
	read(n),con=++n;
	rep(i,1,n-1) read(a[i]);
	rep(i,1,n) pa[i]=i;
	for(;con>=2;){
		REP(i,N) f[i]=g[i]=mp(-1,0);
		rep(i,1,n) cur[i]=-1,val[i]=0;
		rep(i,1,n) upd((~a[i])&(N-1),mp(a[i],gp(i)));
		REP(k,18) REP(i,N) if(i>>k&1)
			upd(i^(1<<k),f[i]),upd(i^(1<<k),g[i]);
		rep(i,1,n){
			pii x=(f[a[i]].se==gp(i)?g[a[i]]:f[a[i]]);
			if(x.se>0&&(cur[gp(i)]==-1||x.fi+a[i]>val[gp(i)])){
				cur[gp(i)]=x.se,val[gp(i)]=x.fi+a[i];
			}
		}
		rep(i,1,n) if(pa[i]==i&&cur[i]>0){
			int u=i,v=gp(cur[i]);
			if(u==v) continue;
			pa[u]=v,ans+=val[i],con--;
		}
	}
	rep(i,1,n) ans-=a[i];
	cout<<ans<<endl;
	return 0;
}