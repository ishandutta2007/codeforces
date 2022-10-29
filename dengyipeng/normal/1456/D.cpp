#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 5005
using namespace std;

int n,i,j,k,f[maxn][maxn],s[maxn][maxn];
int t[maxn],x[maxn],ans,id[maxn],xx[maxn];
int cmp(int i,int j){return x[i]<x[j];}

int findl(int a,int b,int res){
	int l=1,r=xx[b],mid,ans;
	while (l<=r){
		mid=(l+r)>>1;
		if (min(res-abs(x[a]-x[id[mid]]),t[b]-t[a])>=abs(x[b]-x[id[mid]]))
			r=mid-1,ans=mid;
		else l=mid+1;
	}
	return ans;
}
int findr(int a,int b,int res){
	int l=xx[b],r=n,mid,ans;
	while (l<=r){
		mid=(l+r)>>1;
		if (min(res-abs(x[a]-x[id[mid]]),t[b]-t[a])>=abs(x[b]-x[id[mid]]))
			l=mid+1,ans=mid;
		else r=mid-1;
	}
	return ans;
}

void doit(int i,int j){
	if (abs(x[j]-x[i])<=t[j]-t[i]){
		f[j][0]=1;
		for(k=j+1;k<=n;k++){
			if (j==i+1)
				if (abs(x[k]-x[i])+abs(x[k]-x[j])<=t[j]-t[i])
					f[j][k]=1;
			if (j==i+2)
				if (min(t[j]-t[i]-abs(x[k]-x[i]),t[i+2]-t[i+1])>=abs(x[k]-x[j]))
					f[j][k]=1;
		}
		int res;
		res=t[j]-t[i]-abs(x[j]-x[i]);
		if (j==i+2) res=min(res,t[j]-t[j-1]);
		for(k=j+1;k<=n;k++){
			if (t[k]-t[k-1]+res>=abs(x[k]-x[k-1])){
				f[k][0]=1;
				int lim=t[k]-t[k-1]+res;
				int L=findl(k-1,k,lim);
				int R=findr(k-1,k,lim);
				s[k][L]++,s[k][R+1]--;
				if (res>=abs(x[k]-x[k-1]))
					res=t[k]-t[k-1];
				else res=t[k]-t[k-1]+res-abs(x[k]-x[k-1]);
			} else break;
		}		
	}
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d%d",&t[i],&x[i]),id[i]=i;
	sort(id+1,id+1+n,cmp);
	for(i=1;i<=n;i++) xx[id[i]]=i;
	f[0][0]=1;
	for(i=0;i<n;i++) {
		for(j=1;j<=n;j++) {
			s[i][j]+=s[i][j-1];
			if (id[j]!=i&&id[j]>i)
				f[i][id[j]]|=s[i][j]>0;
		}
		for(j=0;j<=n;j++) if (f[i][j]){
			if (j==0) doit(i,i+1); else 
			if (j==i+1){
				if (j==n) ans=1; else
					doit(i,i+2);
			} else {
				if (abs(x[i+1]-x[i])<=t[i+1]-t[i])
					f[i+1][j]=1;
			}
		}
	}
	for(i=0;i<=n;i++) ans|=f[n][i];
	if (ans) printf("YES\n");
	else printf("NO\n");
}