#include<cstdio>
#include<algorithm>
const int N=1e5+3;
struct op{int o,p,a,pos;double val;}b[N+N],ans[N];
bool Cmp1(const op&a,const op&b){return a.a>b.a;}
bool Cmp2(const op&a,const op&b){return a.val>b.val;}
bool Cmp3(const op&a,const op&b){return a.o<b.o;}
int n,m,d,x[N],tp;long long a[N];
int main(){
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1;i<=n;i++)scanf("%I64d",a+i);
	for(int j=1;j<=m;j++){
	  scanf("%d%d%d",&b[j].o,&b[j].p,&b[j].a);
	  b[j].pos=j;
	  if(b[j].o==1)b[j].o=0;
	  if(!b[j].o&&(x[b[j].p]&&b[j].a>b[x[b[j].p]].a||!x[b[j].p]&&b[j].a>a[b[j].p]))x[b[j].p]=j;
	  if(b[j].o==3)b[j].val=b[j].a;
	}
	for(int i=1;i<=n;i++)if(x[i])
	  b[++m]=(op){1,i,b[x[i]].a-a[i],b[x[i]].pos};
	std::sort(b+1,b+1+m,Cmp1);
	for(int j=1;j<=m;j++)if(b[j].o==1||b[j].o==2)
	  b[j].val=(1+(double)b[j].a/a[b[j].p]),a[b[j].p]+=b[j].a;
	std::sort(b+1,b+1+m,Cmp2);
	for(int j=1;j<=d;j++)if(b[j].o)
	  ans[++tp]=b[j];
	std::sort(ans+1,ans+1+tp,Cmp3);
	printf("%d\n",tp);
	for(int i=1;i<=tp;i++)printf("%d ",ans[i].pos);puts("");
	return 0;
}