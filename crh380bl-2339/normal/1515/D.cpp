#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	int T,n,i,j,l,r,x,ans;
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d%d%d",&n,&l,&r);
		int l1=l,r1=r;
		for(i=1;i<=n;++i)a[i]=0;
		for(i=1;i<=l;++i){
			scanf("%d",&x);
			++a[x];
		}
		for(i=1;i<=r;++i){
			scanf("%d",&x);
			--a[x];
		}
		if(l>r){
			for(i=1;i<=n;++i){
				while(l>r&&a[i]>=2){
					--l;
					++r;
					a[i]-=2;
					++ans;
				}
			}
		}
		else{
			for(i=1;i<=n;++i){
				while(r>l&&a[i]<=-2){
					++l;
					--r;
					a[i]+=2;
					++ans;
				}
			}
		}
		l1=r1=0;
		for(i=1;i<=n;++i){
			if(a[i]>0)l1+=a[i];
			else if(a[i]<0)r1-=a[i];
		}
		printf("%d\n",ans+max(l1,r1));
	}
	return 0;
}