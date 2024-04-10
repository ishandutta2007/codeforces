#include<cstdio>
#include<algorithm>
const int N=1e5+3,D=1<<17;
struct query{int l,r,a;}q[N+N];
bool Cmp(const query&a,const query&b){return a.l<b.l;}
int n,a[N],la[N],lst[N],nxt[N],k,f[N],ans,bt[D+5];
inline void Update(int k,int a){for(;k&&k<D;k+=k&-k)bt[k]=std::max(bt[k],a);}
inline int Mex(int g){
	int l=0,r=D,m;
	for(;r-l>1;)m=l+r>>1,bt[m]<=g?l=m:r=m;
	return l+1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++){
	  lst[i]=la[a[i]];
	  if(lst[i])nxt[lst[i]]=i;
	  else Update(a[i],i);
	  q[++k]=(query){lst[i]+1,i,a[i]};
	  la[a[i]]=i;
	}
	for(int i=1;i<=n+1;i++){
	  if(la[i])nxt[la[i]]=n+1;
	  else Update(i,n+1);
	  q[++k]=(query){la[i]+1,n+1,i};
	}
	std::sort(q+1,q+1+k,Cmp);
	for(int i=1,j=1;i<=n;i++){
	  for(;j<=k&&q[j].l<=i;j++)if(q[j].a==(q[j].l>=q[j].r?0:Mex(q[j].r-1)))f[q[j].a]=1;
	  Update(a[i],nxt[i]);
	}
	for(ans=1;f[ans];++ans);
	printf("%d\n",ans);
	return 0;
}