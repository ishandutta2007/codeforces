#include<cstdio>
#include<algorithm> 
const int N=2e5+3,S=1<<18;
int n,a[N],t[N],m,ans[N],bt[S];
struct query{int k,p,ind;}q[N];
bool Cmp(const query&a,const query&b){return a.k<b.k;}
bool Cmpt(const int&i,const int&j){return a[i]==a[j]?i<j:a[i]>a[j];}
inline void Add(int k,int a){for(;k&&k<S;k+=k&-k)bt[k]+=a;}
inline int Query(int k){
	int l,r,md,s=0;
	for(l=1,r=S;l<r;)md=l+r>>1,s+bt[md]>=k?r=md:(s+=bt[md],l=md+1);//puts("sfaef");
	return l;
}
int main(){
	int x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),t[i]=i;
	std::sort(t+1,t+n+1,Cmpt);
	scanf("%d",&m);
	for(int j=1;j<=m;j++)
	  scanf("%d%d",&q[j].k,&q[j].p),q[j].ind=j;
	std::sort(q+1,q+1+m,Cmp);
	for(int i=1,j=1;i<=n;i++){
	  Add(t[i],1);//printf("%d\n",t[i]);
	  for(;q[j].k==i&&j<=m;j++)ans[q[j].ind]=a[Query(q[j].p)];//,printf(" %d\n",q[j].ind);
	}
	for(int j=1;j<=m;j++)printf("%d\n",ans[j]);
	return 0;
}