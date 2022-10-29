#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define maxn 100005
#define ll long long 
using namespace std;

int T,n,i,j,k,ans[maxn];
ll m;
ll F(int x){return (x==0)?1:(1ll<<x-1);}

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%lld",&n,&m);
		if (n<=63&&(1ll<<n-1)<m) {printf("-1\n");continue;}
		for(i=1;i<=n;i++){
			j=i;
			while (n-j<=63&&F(n-j)<m)
				m-=F(n-j),j++;
			for(k=j;k>=i;k--)
				ans[i+j-k]=k;
			i=j;
		}
		for(i=1;i<=n;i++) printf("%d ",ans[i]);
		printf("\n");
	}
}