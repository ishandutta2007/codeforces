#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#define maxn 3005
#define ll long long 
using namespace std;

int n,m,i,j,k,c[maxn]; vector<ll> a[maxn];
ll f[20][maxn],ans;
ll max(ll a,ll b){return (a>b)?a:b;}

void merge(int l,int r,int d){
	if (l==r){
		for(int i=m;i>=0;i--) if (i+c[l]>=m)
			ans=max(ans,f[d][i]+a[l][m-i]);
		return;
	}
	int mid=(l+r)>>1;
	memcpy(f[d+1],f[d],sizeof(f[d]));
	for(int i=mid+1;i<=r;i++) {
		for(int j=max(0,m-c[i]);j>=0;j--)
			f[d+1][j+c[i]]=max(f[d+1][j+c[i]],f[d+1][j]+a[i][c[i]]);
	}
	merge(l,mid,d+1);
	memcpy(f[d+1],f[d],sizeof(f[d]));
	for(int i=l;i<=mid;i++) {
		for(int j=max(0,m-c[i]);j>=0;j--) 
			f[d+1][j+c[i]]=max(f[d+1][j+c[i]],f[d+1][j]+a[i][c[i]]);
	}
	merge(mid+1,r,d+1);
}

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) {
		scanf("%d",&c[i]),a[i].push_back(0);
		for(j=1;j<=c[i];j++) {
			scanf("%d",&k),a[i].push_back(k);
			a[i][j]+=a[i][j-1];
		}
	}
	merge(1,n,0);
	printf("%lld\n",ans);
}