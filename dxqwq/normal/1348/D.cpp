#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 100000
int t,n;
int ans,a[N];
signed main()
{
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		for(int i=0,j=1,k=0;;i++,j<<=1){
			k+=j;
			if(k>=n){
				ans=i;
				break;
			}
		}
		printf("%lld\n",ans);
		int x=1,y;
		for(int i=0;i<=ans;i++)
			a[i]=x,x<<=1;
		y=x>>2,x--;
		int tot=ans;
		long long qwq=n+1,awa=1;
		while(awa<qwq) awa<<=1;
		if(awa==qwq) 
		{
			for(int i=0; i<ans; i++) printf("%lld ",1<<i);
		}
		else while(n<x){
			x-=y*(ans-tot+1),y>>=1;
			if(n>=x){
				int xxx=ans-tot+1,yyy;
				for(int i=tot;i<=ans;i++)
					a[i]=a[tot-1];
				n-=x;
				yyy=n/xxx;
				n-=yyy*xxx;
				for(int i=ans;i>0;i--) if(i<tot)continue;
					else if(n) a[i]+=(yyy+1),n--;
					else a[i]+=yyy;
				for(int i=1;i<=ans;i++)
					printf("%lld ",a[i]-a[i-1]);
				break;
			}
			tot--;
		}
		puts("");
	}
	return 0;
}