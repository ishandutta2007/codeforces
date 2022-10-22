#include<bits/stdc++.h>
using namespace std;
const int N=110,M=2000;
int n,sum;
int a[N];int dp[N*M];
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),sum+=a[i];
	if(sum%2)return puts("0"),0;
	else{
		dp[0]=1;
		for(int i=1;i<=n;i++)
			for(int j=sum/2-a[i];j>=0;j--)
				dp[j+a[i]]|=dp[j];
		if(!dp[sum/2])return puts("0"),0;
		else{
			int maxx=0x3f3f3f3f;
			for(int i=1;i<=n;i++){
				int kk=0,tt=a[i];
				while(tt%2==0)
					tt/=2,kk++;
				maxx=min(maxx,kk);
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=maxx;j++)
					a[i]/=2;
				if(a[i]%2)return printf("1\n%d",i),0;
			}
		}
	}
}