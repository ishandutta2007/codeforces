#include<bits/stdc++.h>
const int N=1000050;
using namespace std;

int n,l,r,x,c[2][N],ans,t;

int main(){
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d%d%d",&n,&l,&r),ans=n;
		for(int i=1;i<=l;i++)scanf("%d",&x),c[0][x]++;
		for(int i=1;i<=r;i++)scanf("%d",&x),c[1][x]++;
		for(int i=1;i<=n;i++)x=min(c[0][i],c[1][i]),ans-=2*x,c[0][i]-=x,c[1][i]-=x,l-=x,r-=x;
		for(int i=1;i<=n;i++){
			while(c[0][i]>1&&l>r)l-=2,c[0][i]-=2,ans--;
			while(c[1][i]>1&&r>l)r-=2,c[1][i]-=2,ans--;
		}
		for(int i=1;i<=n;i++)c[0][i]=c[1][i]=0;
		ans-=min(l,r);
		printf("%d\n",ans);
	}
}