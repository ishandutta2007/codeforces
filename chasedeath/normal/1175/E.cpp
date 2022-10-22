#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define reg register
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)

char IO;
inline int rd(){
	int s=0,f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}


const int N=5e5+10,P=2015;



int n,m;

struct Seg{
	int l,r,id;
	void Get(){ l=rd(),r=rd(); }
	bool operator < (const Seg __) const {
		return r<__.r;
	}
} Q[N];

int fa[N],maxr[N];
ll dis[N];
int Find(int x){
	if(fa[x]==x) return x;
	int f=fa[x];
	fa[x]=Find(fa[x]);
	dis[x]+=dis[f];
	return fa[x];
}

int ans[N];

int main(){
	n=rd(),m=rd();
	rep(i,1,n) {
		int l=rd(),r=rd();
		maxr[l]=max(maxr[l],r);
	}
	rep(i,0,5e5) fa[i]=i;
	rep(i,1,m) {
		Q[i].Get();
		Q[i].id=i;
	}
	sort(Q+1,Q+m+1);
	int ma=-1,p=1;
	rep(i,0,5e5) {
		ma=max(ma,maxr[i]);
		while(p<=m && Q[p].r<=i) {
			int t=Q[p].l;
			Find(t);
			if(dis[t]<1e9) ans[Q[p].id]=dis[t];
			else ans[Q[p].id]=-1;
			p++;
		}
		if(ma<=i) dis[i]=1e9;
		else fa[i]=ma,dis[i]=1;
	}
	rep(i,1,m) printf("%d\n",ans[i]);
}