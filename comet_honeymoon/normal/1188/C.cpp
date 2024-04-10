#include<bits/stdc++.h>
using namespace std;

int N,K,A[1005];
int f[1005][1005],s[1005][1005];

int main(){
	scanf("%d%d",&N,&K);
	for(int i=1;i<=N;i++) scanf("%d",&A[i]);
	sort(A+1,A+N+1);
	int ans=0;
	for(int L=1;L<=100000/(K-1);L++){
		int j=0;
		f[0][0]=s[0][0]=1;
		for(int i=1;i<=N;i++){
			while(j+1<i&&A[i]-A[j+1]>=L) j++;
			s[i][0]=1;
			for(int k=1;k<=K;k++)
				f[i][k]=s[j][k-1],
				s[i][k]=(s[i-1][k]+f[i][k])%998244353;
			ans=(ans+f[i][K])%998244353;
		}
	}
	printf("%d\n",ans);
}