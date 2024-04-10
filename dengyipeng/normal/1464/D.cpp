#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 1000005
#define ll long long 
#define mo 1000000007
using namespace std;

int T,n,i,j,k,a[maxn],c[3],tot,d[maxn],bz[maxn];
ll ans,sum;

void dfs(int x,int c){
	bz[x]=1;
	if (bz[a[x]]) d[++tot]=c; 
	else dfs(a[x],c+1);
}

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n),tot=0;
		for(i=1;i<=n;i++) scanf("%d",&a[i]),bz[i]=0;
		for(i=1;i<=n;i++) if (!bz[i]) dfs(i,1);
		c[0]=c[1]=c[2]=0,sum=0;
		if (n%3==0){
			ans=1;
			for(i=1;i<=n/3;i++) ans=ans*3%mo;
			for(i=1;i<=tot;i++) c[d[i]%3]++,sum+=(d[i]-1)/3;
			k=min(c[1],c[2]),c[1]-=k,c[2]-=k,sum+=k;
			if (c[1]) sum+=c[1]/3*2;
			if (c[2]) sum+=c[2];
		} else 
		if (n%3==1){
			ans=1;
			for(i=1;i<=n/3-1;i++) ans=ans*3%mo;
			ans=ans*4%mo;
			for(i=1;i<=tot;i++) c[d[i]%3]++,sum+=(d[i]-1)/3;
			if (c[1]==1&&c[2]==0){
				for(i=1;i<=tot;i++) if (d[i]%3==1){
					if (d[i]==1) sum+=1;
					else sum--;
				}
			} else {
				ll tmps=sum,c1=c[1],c2=c[2],mi=1e18;
				for(i=1;i<=tot;i++) if (d[i]%3==1&&d[i]>3){
					c[1]=c1-1,c[2]=c2;
					ll sum=tmps-1;
					k=min(c[1],c[2]),c[1]-=k,c[2]-=k;
					sum+=k;
					if (c[1]) sum+=c[1]/3*2;
					if (c[2]) sum+=c[2];
					mi=min(mi,sum);
				}
				sum=tmps;
				c[1]=c1,c[2]=c2;
				if (c[2]>=2) c[2]-=2; else 
				if (c[2]>=1) c[2]--,c[1]-=2,sum++; else 
					c[1]-=4,sum+=2;
				k=min(c[1],c[2]),c[1]-=k,c[2]-=k;
				sum+=k;
				if (c[1]) sum+=c[1]/3*2;
				if (c[2]) sum+=c[2];
				sum=min(sum,mi);
			}
		} else {
			ans=1;
			for(i=1;i<=n/3;i++) ans=ans*3%mo;
			ans=ans*2%mo;
			for(i=1;i<=tot;i++) c[d[i]%3]++,sum+=(d[i]-1)/3;
			if (c[2]>=1) c[2]--; else c[1]-=2,sum++;
			k=min(c[1],c[2]),c[1]-=k,c[2]-=k;
			sum+=k;
			if (c[1]) sum+=c[1]/3*2;
			if (c[2]) sum+=c[2];			
		}
		printf("%lld %lld\n",ans,sum);
	}
}