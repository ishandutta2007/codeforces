#include<cstdio>
typedef long long ll;
const int N=1e6+3;
int n,a[N];ll m,s;
int main(){
	scanf("%d%lld",&n,&m);s=(ll)n*(n+1)/2;
	if(s>m)return 0*puts("-1");
	for(int i=1;i<=n;i++)a[i]=i;
	for(int i=1;i<=n/2;i++){
	  if(s+(n-i+1-i)<=m)s+=(n-i+1-i),a[i]=n-i+1,a[n-i+1]=i;
	  else{
		for(int j=n-i;j>=i;j--)if(s+j-i<=m)
		  {s+=j-i;a[i]=j,a[j]=i;break;}
		break;
	  }
	}
	printf("%lld\n",s);
	for(int i=1;i<=n;i++)printf("%d ",i);puts("");
	for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
	return 0;
}