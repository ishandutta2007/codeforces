#include<cstdio>
#include<algorithm>
using namespace std;
const int N=500500,M=1001000,oo=1000000000;
int i,j,k,n,m,ch,nls,x,y,nn,ma,ans;
int a[N],b[N],s[M],Ls[M],dp[N],f[N][22],ST[N][22],sz[N],fa[N];
struct edge { int s,n;};
void R(int &x) {
	x=0;ch=getchar();
	while (ch<'0' || '9'<ch) ch=getchar();
	while ('0'<=ch && ch<='9') x=x*10+ch-'0',ch=getchar();
}
int min(const int &x,const int &y) {
	if (x<y) return x;
	return y;
}
struct tree { int mi,ad;} T[M<<2];
struct tree_edge {
	int i,j,k,En;
	int h[N];
	edge E[M];
	void add(int x,int y) {
		E[++En].s=y;E[En].n=h[x];h[x]=En;
	}
} A,B;
int get_fa(int x) {
	if (x==1) return 0;
	int k=dp[x],v=a[x];
	for (j=nn;j>=0;j--) {
		if (k<=(1<<j)) continue;
		if (a[ST[x][j]]>v) x=f[x][j],k-=1<<j;
	}
	if (a[ST[x][0]]<=v) return ST[x][0];
	return 0;
}
int get_min(int x) {
	int k=dp[x],mi=oo;
	//if (x==2) printf("QAQ%d\n",ST[2][0]);
	for (j=nn;j>=0;j--) {
		if (k<=(1<<j)) continue;
		mi=min(mi,a[ST[x][j]]);
		x=f[x][j];
		k-=1<<j;
	}
	return mi;
}
void dfs(int x,int F) {
	dp[x]=dp[F]+1;
	for (int j=1;j<=nn;j++) {
		if (dp[x]<=(1<<j)) break;
		if (a[ST[x][j-1]]<a[ST[f[x][j-1]][j-1]]) ST[x][j]=ST[x][j-1];
		else ST[x][j]=ST[f[x][j-1]][j-1];
		f[x][j]=f[f[x][j-1]][j-1];
	}
	for (int k=A.h[x];k;k=A.E[k].n) if (A.E[k].s!=F) {
		int y=A.E[k].s;
		ST[y][0]=x;
		f[y][0]=x;
		dfs(y,x);
	}
}
void get_sz(int x) {
	sz[x]=1;
	for (int k=B.h[x];k;k=B.E[k].n) {
		get_sz(B.E[k].s);
		sz[x]+=sz[B.E[k].s];
	}
}
int find(int x) {
	int l=1,r=nls,mid;
	while (l<r) {
		mid=(l+r)>>1;
		if (Ls[mid]==x) return mid;
		if (Ls[mid]<x) l=mid+1;
		else r=mid-1;
	}
	return l;
}
void down(int k) {
	if (T[k].ad) {
		T[k<<1].ad+=T[k].ad;
		T[k<<1|1].ad+=T[k].ad;
		T[k<<1].mi+=T[k].ad;
		T[k<<1|1].mi+=T[k].ad;
		T[k].ad=0;
	}
}
void T_build(int L,int R,int k) {
	if (L==R) {
		T[k].mi=s[L];
		return;
	}
	int mid=(L+R)>>1;
	T_build(L,mid,k<<1);
	T_build(mid+1,R,k<<1|1);
	T[k].mi=min(T[k<<1].mi,T[k<<1|1].mi);
}
void T_add(int L,int R,int l,int r,int ad,int k) {
	if (l>r) return;
	//printf("%d %d %d %d %d %d\n",L,R,l,r,ad,k);
	if (L==l && R==r) {
		//printf("%d\n",T[k].mi);
		T[k].ad+=ad;
		T[k].mi+=ad;
		//printf("%d\n",T[k].mi);
		return;
	}
	down(k);
	int mid=(L+R)>>1;
	if (r<=mid) T_add(L,mid,l,r,ad,k<<1);
	else {
		if (l>mid) T_add(mid+1,R,l,r,ad,k<<1|1);
		else T_add(L,mid,l,mid,ad,k<<1),T_add(mid+1,R,mid+1,r,ad,k<<1|1);
	}
	T[k].mi=min(T[k<<1].mi,T[k<<1|1].mi);
	//printf("%d %d %d\n",T[k].mi,T[k<<1].mi,T[k<<1|1].mi);
}
int main() {
	R(n);ans=oo;
	while ((1<<nn)<n) nn++;
	for (i=1;i<=n;i++) {
		R(a[i]);
		Ls[++nls]=a[i];
	}
	for (i=1;i<n;i++) {
		R(x);R(y);
		A.add(x,y);
		A.add(y,x);
	}
	R(m);
	for (i=1;i<=m;i++) {
		R(b[i]);
		Ls[++nls]=b[i];
	}
	if (m>n) return puts("-1"),0;
	sort(Ls+1,Ls+nls+1);
	int tmp=nls;nls=0;
	Ls[tmp+1]=-1;
	for (i=1;i<=tmp;i++) if (Ls[i]!=Ls[i+1]) Ls[++nls]=Ls[i];
	for (i=1;i<=n;i++) a[i]=find(a[i]);
	for (i=1;i<=m;i++) b[i]=find(b[i]);
	dfs(1,0);
	for (i=1;i<=n;i++) {
		fa[i]=get_fa(i);
		B.add(fa[i],i);
	}
	get_sz(0);
	for (k=B.h[0];k;k=B.E[k].n) s[a[B.E[k].s]]+=sz[B.E[k].s];
	for (i=1;i<=m;i++) s[b[i]]--;
	for (i=nls;i;i--) s[i]+=s[i+1];
	for (i=nls;i;i--) if (s[i]<0) break;
	if (!i) return puts("0"),0;
	ma=i;
	//printf("%d\n",ma);
	//for (i=1;i<=nls;i++) printf("%d ",s[i]);
	//puts("");
	T_build(1,nls,1);
	for (k=B.h[0];k;k=B.E[k].n) {
		int x=B.E[k].s;
		if (a[x]>=ma) continue;
		int t=get_min(x);
		//printf("x=%d min=%d ma=%d\n",x,t,ma);
		if (t<ma) continue;
		if (Ls[ma]-Ls[a[x]]>=ans) continue;
		//printf("x=%d\n",x);
		for (int kk=B.h[x];kk;kk=B.E[kk].n) {
			int y=B.E[kk].s;
			//printf("y=%d ay=%d ax=%d ma=%d sz=%d\n",y,a[y],a[x],ma,sz[y]);
			if (a[y]<ma) {
				if (a[x]<a[y]) T_add(1,nls,a[x]+1,a[y],sz[y],1);
			}
			else T_add(1,nls,a[x]+1,ma,sz[y],1);
		}
		T_add(1,nls,a[x]+1,ma,1,1);
		//printf("QAQ%d\n",T[1].mi);
		if (T[1].mi>=0) ans=Ls[ma]-Ls[a[x]];
		for (int kk=B.h[x];kk;kk=B.E[kk].n) {
			int y=B.E[kk].s;
			if (a[y]<ma) {
			 	if (a[x]<a[y]) T_add(1,nls,a[x]+1,a[y],-sz[y],1);
			 }
			else T_add(1,nls,a[x]+1,ma,-sz[y],1);
		}
		T_add(1,nls,a[x]+1,ma,-1,1);
	}
	if (ans==oo) puts("-1");
	else printf("%d\n",ans);
}