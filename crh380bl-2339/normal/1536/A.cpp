#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[102];
bool bo[102];
int main(){
	int T,n,i,j,mx;
	bool flg;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		flg=1;mx=0;
		memset(bo,0,sizeof(bo));
		for(i=1;i<=n;++i){
			scanf("%d",&a[i]);
			if(a[i]<0)flg=0;
			else{
				bo[a[i]]=1;
				mx=max(mx,a[i]);
			}
		}
		if(!flg)puts("NO");
		else{
			printf("YES\n%d\n",mx+1);
			for(i=0;i<=mx;++i){
				if(!bo[i])printf("%d ",i);
			}
			for(i=1;i<=n;++i)printf("%d ",a[i]);
			puts("");
		}
	}
	return 0;
}