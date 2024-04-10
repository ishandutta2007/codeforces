#include<cstdio>
#include<algorithm>
const int N=2e5+3,INF=0x3f3f3f3f;
int n,m,a[N],b[N],c[N],d,s,ans;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int j=1;j<=m;j++){
	  scanf("%d",b+j),s+=b[j];
	  if(!b[j])++d;
	}
	ans=INF;
	for(int i=1,j=1;i<=n;i++){
	  ++c[a[i]];
	  if(c[a[i]]==b[a[i]])++d;
	  for(;c[a[j]]>b[a[j]];c[a[j]]--,j++);
	  if(d==m)ans=std::min(ans,i-j+1-s);
	}
	printf("%d\n",ans<INF?ans:-1);
	return 0;
}