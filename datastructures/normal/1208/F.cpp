#include <iostream>
#include <cstdio>
#include <cstring> 
using namespace std;
int n,a[1000005],dp[10000005][2],f[10000005];
int maxn=(1<<21),ans;
inline void upd(int now,int val){
	if (val>dp[now][0])dp[now][1]=dp[now][0],dp[now][0]=val;
	else if (val>dp[now][1]&&val!=dp[now][0])dp[now][1]=val;
	return;
}
inline bool chk(int num){
	for (register int i=0;i<=maxn;i++)
		if (dp[i][1]>f[num^(num&i)])return 1;
	return 0;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	memset(f,0x7f,sizeof(f));
	for (int i=1;i<=n;i++)f[a[i]]=min(f[a[i]],i),upd(a[i],i);
	for (register int i=maxn;i>=0;i--)
		for (register int j=0;j<=20;j++)
			if ((i&(1<<j))!=0){
				upd((i^(1<<j)),dp[i][0]);
				upd((i^(1<<j)),dp[i][1]);
				f[i^(1<<j)]=min(f[i^(1<<j)],f[i]);
			}
	for (register int i=20;i>=0;i--)
		if (chk(ans+(1<<i)))ans+=(1<<i);
	cout<<ans<<endl;
	return 0;
}