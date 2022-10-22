#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,num[500100],mx,mxp;
signed main(){
	scanf("%I64d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d",&num[i]);
	for(int i=1;i<=n;i++){
		int res=-num[i];
		for(int j=i,bd=num[i];j<=n;j++)bd=min(bd,num[j]),res+=bd;
		for(int j=i,bd=num[i];j>=1;j--)bd=min(bd,num[j]),res+=bd;
		if(mx<res)mx=res,mxp=i;
	}
	for(int j=mxp+1;j<=n;j++)num[j]=min(num[j],num[j-1]);
	for(int j=mxp-1;j>=1;j--)num[j]=min(num[j],num[j+1]);
	for(int i=1;i<=n;i++)printf("%I64d ",num[i]);
	return 0;
}