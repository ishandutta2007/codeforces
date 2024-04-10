#include<bits/stdc++.h>
using namespace std;
long long ntcan[1048576],n,m,pw[53];
string s[53];
double dp[1048576];
int main(){
	cin>>n;
	pw[0]=1;
	for(int i=1;i<51;i++) 
		pw[i]=pw[i-1]*2;
	for(long long i=0;i<n;i++)
		cin>>s[i];
	m=s[0].size();
	for(long long i=0;i<n;i++)
		for(long long j=i+1;j<n;j++){
			long long tmp=0;
			for(long long k=0;k<m;k++)
				if(s[i][k]==s[j][k])
					tmp+=(1<<k);
			ntcan[tmp]|=1ll*pw[i];
			ntcan[tmp]|=1ll*pw[j];
		}
	for(long long msk=(1<<m)-1;msk>=0;msk--)
		for(long long i=0;i<m;i++)
			ntcan[msk&((1<<m)-1-pw[i])]|=ntcan[msk];
	dp[0]=1;double ans=0;
	for(long long msk=0;msk<(1<<m);msk++){
		long long cnt=0;
		for(long long i=0;i<m;i++)
			if((msk|pw[i])!=msk)
				cnt++;
		for(long long i=0;i<m;i++)
			if((msk|pw[i])!=msk)
				dp[msk+pw[i]]+=dp[msk]*1.0/cnt;
		cnt=0;
		for(long long i=0;i<n;i++)
			if((ntcan[msk]|(1ll*pw[i]))==ntcan[msk])
				cnt++;
		ans+=dp[msk]*cnt;
	}
	printf("%.15f\n",ans*1.0/n);
}