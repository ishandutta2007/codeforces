#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e9+7;
void add(int &A,int B){
	A+=B;
	if(A>=M)A-=M;
}
int f[10004],g[10004],sum,sb;
int n,q,x,c[103],b[103],pans=1;
int l=1e9,r=1e9;
int mp[103];
void solve(int x){
	memset(f,0,sizeof(f));
	sum=sb=0;
	f[0]=1;
	for(int i=1;i<=n;i++){
		sum+=b[i-1],sb+=sum;
		memset(g,0,sizeof(g));
		for(int j=0;j<=i*100;j++)g[j]=g[j-1],add(g[j],f[j]);
		memset(f,0,sizeof(f));
		for(int j=max(sb+i*x,0);j<=i*100;j++){
			f[j]=g[j];
			if(j>c[i])add(f[j],M-g[j-c[i]-1]);
		}
	}
	int ans=0;
	for(int i=0;i<=n*100;i++)add(ans,f[i]);
	mp[x-l]=ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]),pans=(ll)pans*(c[i]+1)%M;
	for(int i=1;i<n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++){
		sum+=b[i-1],sb+=sum;
		l=min(l,-((sb-1)/i+1)),r=min(r,(100*n-1-sb)/i+1);
	}
	for(int i=l;i<=r;i++)solve(i);
	scanf("%d",&q);
	while(q--){
		scanf("%d",&x);
		if(x<l)printf("%d\n",pans);
		else if(x>r)puts("0");
		else printf("%d\n",mp[x-l]);
	}
}