#include<cstdio>
#include<queue>
#define max(a,b)((a)>(b)?(a):(b))
const int N=5003;
struct edge{int v,nxt;}g[N];
int n,m,d,h[N],a[N],b[N],c[N],s[N],head[N],k,ans;
inline void Insert(int u,int v){g[++k]=(edge){v,head[u]};head[u]=k;}
std::priority_queue<int,std::vector<int>,std::greater<int> >p;
signed main(){
	int u,v;
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1;i<=n;i++)scanf("%d%d%d",a+i,b+i,c+i),h[i]=i;
	for(;m--;)scanf("%d%d",&u,&v),h[v]=max(h[v],u);
	for(int i=1;i<=n;i++)Insert(h[i],i);//,printf(" %d %d\n",h[i],i);
	s[0]=d;
	for(int i=1,j;i<=n;i++){
	  s[i]=s[i-1];
	  if(s[i]<a[i]){
		if(s[i]+p.size()<a[i])return 0*puts("-1");//*printf(" %d",i);
		for(int j=0;j<a[i]-s[i];j++)p.pop();
		s[i]=a[i];
	  }
	  s[i]=s[i]+b[i];
	  for(int x=head[i];x;x=g[x].nxt){
		j=g[x].v;
		p.push(c[j]),s[i]--;//,printf("%d %d %d\n",i,j,c[j]);
	  }
	}
	for(;!p.empty();p.pop())ans+=p.top();
	printf("%d",ans);
	return 0;
}