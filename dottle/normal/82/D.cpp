#include<bits/stdc++.h>
#define int long long
const int N=1050;
using namespace std;

int f[N][N],n,m,a[N],ans,b[N],bg,fl;
struct node{
	int x,y,a,b;
}e[N][N],as;

void print(node a){
	if(a.x)print(e[a.x][a.y]);
	if(a.a||a.b)printf("%lld %lld\n",min(a.a,a.b),max(a.a,a.b));
}

main(){
	scanf("%lld",&n),a[0]=1ll<<62;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	if(n%2==0)++n,fl=1;
	memset(f,1,sizeof(f));
	f[1][1]=f[0][0]=0;
	for(int i=2;i<=n;i++)
		for(int j=0;j<i-1;j++){
			if(f[i-2][j]+max(a[i],a[i-1])<f[i][j])
				f[i][j]=f[i-2][j]+max(a[i],a[i-1]),e[i][j]=(node){i-2,j,i,i-1};
			if(f[i-2][j]+max(a[i],a[j])<f[i][i-1])
				f[i][i-1]=f[i-2][j]+max(a[i],a[j]),e[i][i-1]=(node){i-2,j,i,j};
			if(f[i-2][j]+max(a[j],a[i-1])<f[i][i])
				f[i][i]=f[i-2][j]+max(a[j],a[i-1]),e[i][i]=(node){i-2,j,i-1,j};
		}
	ans=f[n][0],as=e[n][0];
	for(int i=1;i<=n;i++)
		if(ans>f[n][i]+a[i])
			ans=f[n][i]+a[i],as=e[n][i],bg=i;
	printf("%lld\n",ans);
	print(as);
	if(bg&&!fl)printf("%lld",bg);
}