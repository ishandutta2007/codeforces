#include <cstdio>
#include <algorithm>
using namespace std;
#define M ((L+R)>>1)
#define lc o<<1
#define rc o<<1|1
#define ls lc,L,M
#define rs rc,M+1,R

const int N=200005,E=400005;
int n,x,y,z,e,fd,tp,hd[N],nx[E],to[E],w[E],v[N],st[E];
long long a1,a2=0x3f3f3f3f3f3f3f3fLL,s[E],d[N],mx[E*4],m1[E*4],m2[E*4];
struct nd {
	long long mx,m1,m2;
};
void ad(int x,int y,int z) {
	to[++e]=y,w[e]=z,nx[e]=hd[x],hd[x]=e;
}

void dfs(int x,int fa) {
	v[x]=1;
	for(int i=hd[x]; i; i=nx[i]) if(to[i]^fa) {
			if(v[to[i]]) fd=to[i];
			else dfs(to[i],x);
			if(!~fd) return;
			if(fd) {
				st[++tp]=x,s[tp]=w[i];
				if(fd==x) fd=-1;
				return;
			}
		}
}
void dfs2(int x) {
	v[x]=2;
	for(int i=hd[x]; i; i=nx[i]) if(v[to[i]]^2) dfs2(to[i]),a1=max(a1,d[x]+d[to[i]]+w[i]),d[x]=max(d[x],d[to[i]]+w[i]);
}

void pu(int o) {
	mx[o]=max(max(mx[lc],mx[rc]),m1[lc]+m2[rc]),m1[o]=max(m1[lc],m1[rc]),m2[o]=max(m2[lc],m2[rc]);
}
void bd(int o,int L,int R) {
	if(L==R) {
		m1[o]=d[st[L]]-s[L],m2[o]=d[st[L]]+s[L];
		return;
	}
	bd(ls),bd(rs),pu(o);
}
nd qr(int o,int L,int R,int l,int r) {
	if(l<=L&&r>=R) return (nd) {
		mx[o],m1[o],m2[o]
	};
	if(r<=M) return qr(ls,l,r);
	if(l>M) return qr(rs,l,r);
	nd t1=qr(ls,l,r),t2=qr(rs,l,r);
	return (nd) {
		max(max(t1.mx,t2.mx),t1.m1+t2.m2),max(t1.m1,t2.m1),max(t1.m2,t2.m2)
	};
}

int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d%d%d",&x,&y,&z),ad(x,y,z),ad(y,x,z);
	dfs(1,0);
	for(int i=1; i<=tp; i++) v[st[i]]=2;
	for(int i=1; i<=tp; i++) dfs2(st[i]);
	for(int i=1; i<=tp; i++) st[i+tp]=st[i],s[i+tp]=s[i];
	for(int i=1; i<=tp*2; i++) s[i]+=s[i-1];
	bd(1,1,tp*2);
	for(int i=1; i<=tp; i++) a2=min(a2,max(qr(1,1,tp*2,i,i+tp-1).mx,a1));
	printf("%lld",a2);
	return 0;
}