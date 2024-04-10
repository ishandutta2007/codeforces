#include<bits/stdc++.h>
const int N=500050;
using namespace std;

int t,n,m,a[N],cnt[N],ans[N],c,sz[N];

int fa[N];
int gf(int k){
	return k==fa[k]?k:fa[k]=gf(fa[k]);
}
void mrg(int a,int b){
	int x=gf(a),y=gf(b);
	if(x!=y)fa[x]=y,sz[y]+=sz[x];
}
bool chk(int k){
	for(int i=1;i<=n;i++)
		fa[i]=i,sz[i]=1;
	for(int i=1;i<=n;i++)
		mrg(a[(i+k+n-1)%n+1],i);
	int ans=0;
	for(int i=1;i<=n;i++)
		if(gf(i)==i)
			ans+=sz[i]-1;
	return ans<=m;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),cnt[(i-a[i]+n)%n]++;
		for(int i=0;i<n;i++)
			if(cnt[i]>=n-2*m)
				if(chk(i))
					ans[++c]=i;
		printf("%d ",c);
		for(int i=1;i<=c;i++)printf("%d ",ans[i]); 
		putchar('\n');
		for(int i=0;i<=n;i++)cnt[i]=0;c=0;
	}
}