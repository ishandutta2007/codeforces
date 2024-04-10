#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(a=0;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
inline int Min(int a,int b){return a<b?a:b;}
inline int Max(int a,int b){return a>b?a:b;}
const int o=2.2e7+10,O=1e6+10;
int n,m,p[O],q[O],rt[O],s[o],ls[o],rs[o],cnt,ans=-1;
void modify(int&id1,int id2,int pos,int l=1,int r=n){
	id1=++cnt;
	if(l==r){s[id1]=1;return;}
	int md=l+r>>1;
	if(pos<=md) rs[id1]=rs[id2],modify(ls[id1],ls[id2],pos,l,md);
	else ls[id1]=ls[id2],modify(rs[id1],rs[id2],pos,md+1,r);
	s[id1]=s[ls[id1]]+s[rs[id1]];
}
int query(int id,int ql,int qr,int l=1,int r=n){
	if(l==ql&&r==qr) return s[id];
	int md=l+r>>1;
	if(qr<=md) return query(ls[id],ql,qr,l,md);
	if(md<ql) return query(rs[id],ql,qr,md+1,r);
	return query(ls[id],ql,md,l,md)+query(rs[id],md+1,qr,md+1,r);
}
inline int f(int z){return (z+ans)%n+1;}
int main(){
	read(n);
	for(int i=1;i<=n;++i) read(p[i]);
	for(int i=1,j;i<=n;++i) read(j),q[j]=i;
	rt[0]=cnt=1;
	for(int i=1;i<=n;++i) modify(rt[i],rt[i-1],q[p[i]]);
	read(m);
	for(int a,b,c,d,l1,r1,l2,r2;m--;printf("%d\n",ans=query(rt[r1],l2,r2)-query(rt[l1-1],l2,r2)))
		read(a),read(b),read(c),read(d),l1=Min(a=f(a),b=f(b)),r1=Max(a,b),l2=Min(c=f(c),d=f(d)),r2=Max(c,d);
	return 0;
}