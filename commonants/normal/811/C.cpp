#include<cstdio>
#include<cstring>
#include<cstring>
#include<algorithm>

using namespace std;
int n;const int MX=5111;
int a[MX],dp[MX],mxdp[MX],L[MX],R[MX];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)if(!L[a[i]])L[a[i]]=i;
	for(int i=n;i;i--)if(!R[a[i]])R[a[i]]=i;
	for(int i=1;i<=n;i++){
		if(R[a[i]]==i){
			int xs=0,mnl=i;
			for(int j=i;j;j--){
				if(R[a[j]]>i)break;
				if(R[a[j]]==j)xs^=a[j];
				mnl=min(mnl,L[a[j]]);
				if(j==mnl)dp[i]=max(dp[i],xs+mxdp[j-1]);
			}
		}
		mxdp[i]=max(mxdp[i-1],dp[i]);
	}
	printf("%d\n",mxdp[n]);
	return 0;
}