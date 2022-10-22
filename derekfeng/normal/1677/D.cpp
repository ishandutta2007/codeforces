#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353;
int t,n,k,v[1000005];
void sol(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	int ans=1;
	for(int i=n-k+1;i<=n;i++)if(v[i]>0)ans=0;
	for(int i=1;i<=k;i++)ans=(ll)ans*i%M;
	for(int i=k+1;i<=n;i++){
		if(v[i-k]==0)ans=(ll)ans*min(k+1,i)%M;
		else if(v[i-k]==-1)ans=(ll)ans*i%M;
		else if(v[i-k]+k>i-1)ans=0;
	}
	printf("%d\n",ans);
}
int main(){
	scanf("%d",&t);
	while(t--)sol();
}