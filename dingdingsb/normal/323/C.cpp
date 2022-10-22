#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,a[N],b[N],pos[N],m;
int s[N<<5],lc[N<<5],rc[N<<5];
int rt[N];
int cnt;
#define mid (l+r>>1)
void upd(int&x,int lst,int l,int r,int pos){
	x=++cnt;
	lc[x]=lc[lst];
	rc[x]=rc[lst];
	s[x]=s[lst]+1;
	if(l==r)return;
	if(pos<=mid)upd(lc[x],lc[lst],l,mid,pos);
	else upd(rc[x],rc[lst],mid+1,r,pos);
}
int qry(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)return s[x];
	if(qr<l||r<ql)return 0;
	return qry(lc[x],l,mid,ql,qr)+qry(rc[x],mid+1,r,ql,qr);
}
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),pos[a[i]]=i;
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]),upd(rt[i],rt[i-1],1,n,pos[b[i]]);
	scanf("%d",&m);int ans=0;
	while(m--){
		#define f(z) (z-1+ans)%n+1
		int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
		int l1=min(f(a),f(b)),r1=max(f(a),f(b));
		int l2=min(f(c),f(d)),r2=max(f(c),f(d));
		ans=qry(rt[r2],1,n,l1,r1)-qry(rt[l2-1],1,n,l1,r1);
		printf("%d\n",ans++);
	}
}