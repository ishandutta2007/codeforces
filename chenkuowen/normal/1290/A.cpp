#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5005;
int a[MAX_N],b[MAX_N];
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n,m,k; scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		for(int i=1;i<=m;++i){
			b[i]=max(a[i],a[n-m+i]);
//			printf("(%d)",b[i]);
		}
		int ans=0;
		if(k>=m-1){
			for(int i=1;i<=m;++i)
				ans=max(ans,b[i]);
		}else{
			for(int i=1;i<=k+1;++i){
				int key=2e9;
				for(int j=i;j<=m-k-1+i;++j)
					key=min(key,b[j]);
				ans=max(ans,key);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}