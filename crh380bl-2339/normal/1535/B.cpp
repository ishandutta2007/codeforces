#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[2005],A=0;
int b[2005],B=0;
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
int main(){
	int T,n,i,j,x,ans;
	scanf("%d",&T);
	while(T--){
		A=B=0;
		scanf("%d",&n);
		for(i=1;i<=n;++i){
			scanf("%d",&x);
			if(x&1)b[++B]=x;
			else a[++A]=x;
		}
		ans=A*(A-1)/2+A*B;
		for(i=1;i<=B;++i)for(j=i+1;j<=B;++j)if(gcd(b[i],b[j])>1)++ans;
		printf("%d\n",ans);
	}
	return 0;
}