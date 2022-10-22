#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int i,j,k,n,m,B,t,a[maxn],is[maxn],b[maxn];
int tree[maxn];
int lowbit(int x){return x&(-x);}
void add(int x,int y){for(;x<=5000;x+=lowbit(x))tree[x]=max(tree[x],y);}
int find(int x){int ans=0;for(;x;x-=lowbit(x))ans=max(ans,tree[x]);return ans;}
int main(){
	cin>>m>>n>>B>>t;
	while(m--){
		int sum=0,ans=0;
		memset(is,0,sizeof(is));
		memset(tree,0,sizeof(tree));
		for(i=1;i<=n;i++)scanf("%d",&a[i]),sum+=is[a[i]]++?0:1,b[i]=a[i];
		sort(b+1,b+1+n);int len=1;for(i=2;i<=n;i++)if(b[i]!=b[len])b[++len]=b[i];
		for(i=1;i<=n;i++)a[i]=lower_bound(b+1,b+1+len,a[i])-b+1;
		if(t>=sum){printf("%d\n",sum);continue;}
		else{
			for(i=1;i<=t;i++)
				for(j=1;j<=n;j++){
					int dp=find(a[j])+1;
//					cout<<"dp="<<dp<<' '<<a[j]<<endl;
					ans=max(ans,dp);
					add(a[j]+1,dp);
				}
		}printf("%d\n",ans);
	}
}