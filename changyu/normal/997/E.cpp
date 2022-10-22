#include<bits/stdc++.h>
#define M (L+R>>1)
typedef long long ll;
const int N=120003,V=1<<18;
int n,m,a[N],p[N];
ll ans[N];
struct query{int l,r,p;}q[N];
bool Cmp(const query&a,const query&b){return a.r<b.r;}
int mn[V],c[V],lz[V],lz1[V];
ll c1[V];
inline void Addtag(int x,int k){
	lz1[k]+=x,c1[k]+=(ll)c[k]*x;
}
inline void Down(int k){
	if(lz[k]){
		lz[k<<1]+=lz[k],lz[k<<1|1]+=lz[k];
		mn[k<<1]+=lz[k],mn[k<<1|1]+=lz[k]; 
		lz[k]=0;
	}
	if(lz1[k]){
		if(mn[k<<1  ]==mn[k])Addtag(lz1[k],k<<1  );
		if(mn[k<<1|1]==mn[k])Addtag(lz1[k],k<<1|1);
		lz1[k]=0;
	}
}
inline void Up(int k){
	if(mn[k<<1]==mn[k<<1|1])
		mn[k]=mn[k<<1],c[k]=c[k<<1]+c[k<<1|1];
	else if(mn[k<<1]<mn[k<<1|1])
		mn[k]=mn[k<<1],c[k]=c[k<<1];
	else
		mn[k]=mn[k<<1|1],c[k]=c[k<<1|1];
}
void Build(int L,int R,int k){
	if(L==R){mn[k]=n+1,c[k]=1;return;}
	Build(L,M,k<<1),Build(M+1,R,k<<1|1);
	Up(k);
}
void Update(int p,int a,int L,int R,int k){
	if(L==R){mn[k]=a;return;}
	Down(k);
	p<=M?Update(p,a,L,M,k<<1):Update(p,a,M+1,R,k<<1|1);
	Up(k);
}
void Add(int l,int r,int a,int L,int R,int k){
	if(l>r)return;
	if(l<=L&&R<=r){mn[k]+=a,lz[k]+=a;return;}
	Down(k);
	if(l<=M)Add(l,r,a,L,M,k<<1);
	if(r> M)Add(l,r,a,M+1,R,k<<1|1); 
	Up(k);
}
ll Query(int l,int r,int L,int R,int k){
	if(l<=L&&R<=r)return c1[k];
	Down(k);
	if(r<=M)return Query(l,r,L,M,k<<1);
	if(l> M)return Query(l,r,M+1,R,k<<1|1);
	return Query(l,r,L,M,k<<1)+Query(l,r,M+1,R,k<<1|1);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),p[a[i]]=i;
	scanf("%d",&m);
	for(int j=1;j<=m;j++)scanf("%d%d",&q[j].l,&q[j].r),q[j].p=j;
	std::sort(q+1,q+1+m,Cmp);
	Build(1,n,1);
	for(int i=1,j=1;i<=n;i++){
		if(a[i]-1>=1&&p[a[i]-1]<i)Add(1,p[a[i]-1],-1,1,n,1);
		if(a[i]+1<=n&&p[a[i]+1]<i)Add(1,p[a[i]+1],-1,1,n,1);
		Add(1,i-1,1,1,n,1);
		Update(i,0,1,n,1);
		Addtag(1,1);
		for(;j<=m&&q[j].r==i;j++)
			ans[q[j].p]=Query(q[j].l,q[j].r,1,n,1);
	}
	for(int j=1;j<=m;j++)printf("%lld\n",ans[j]);
	return 0;
}