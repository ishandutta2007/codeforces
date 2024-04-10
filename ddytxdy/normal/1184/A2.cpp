#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n,a[N],cnt[N],ans,vis[N];
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%1d",&a[i]);
	cnt[0]=1;
	for(int i=1;i<n;i++)cnt[gcd(i,n)]++;
	memset(vis,-1,sizeof(vis));
	for(int i=0;i<n;i++)if(cnt[i]){
		bool flag=1;
		for(int j=0;j<n;j++)if(vis[j]!=i){
			int x=j,op=0;
			while(vis[x]!=i)vis[x]=i,op^=a[x],x=(x+i)%n;
			if(op){flag=0;break;}
		}
		if(flag)ans+=cnt[i];
	}
	printf("%d\n",ans);
	return 0;
}