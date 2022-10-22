#include<cstdio>
typedef long long ll;
const int N=7003;
int n,b[N],g[N][N],d[N],f[N];ll a[N],ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
	  scanf("%lld",a+i);
	  for(int j=1;j<i;j++){
		if(a[i]-(a[i]&a[j]))g[i][j]=1,d[i]++;
		if(a[j]-(a[i]&a[j]))g[j][i]=1,d[j]++;
	  }f[i]=1;
	}
	for(int i=1;i<=n;i++)scanf("%d",b+i);
	for(int j=n;j;j--){
	  for(int i=1;i<=n;i++)if(f[i]&&d[i]==j-1){
	  	f[i]=0;
	  	for(int j=1;j<=n;j++)
		  if(g[j][i])d[j]--;
		goto Brk;
	  }
	  for(int i=1;i<=n;i++)ans+=b[i]*f[i];
	  return 0*printf("%lld",ans);
	  Brk:;
	}return 0*puts("0");
}