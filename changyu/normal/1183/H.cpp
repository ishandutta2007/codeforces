#include<cstdio>
typedef long long ll;
const int N=103;
int n,g[26];ll m,f[N][N],ans;char a[N];
int main(){
	scanf("%d%lld%s",&n,&m,a+1);
	for(int i=n;~i;i--){
	  for(int c=0;c<26;c++)g[c]=0;
	  for(int j=n;j>i;j--)
		g[a[j]-'a']=j;
	  f[i][1]=1;
	  for(int j=1;j<=n-i+1;j++){
		for(int c=0;c<26;c++)if(g[c])
		  f[i][j]+=f[g[c]][j-1];
		if(f[i][j]>m)f[i][j]=m;
	  }
	}
	for(int i=n;~i;i--)
	  if(m>=f[0][i+1])m-=f[0][i+1],ans+=f[0][i+1]*(n-i);
	  else{ans+=m*(n-i),m=0;break;}
	printf("%lld\n",m?-1:ans);
	return 0;
}