#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7;
int n,sz[505],ans,pw[505];
int main(){
	scanf("%d",&n),pw[0]=1;
	for(int i=1;i<=n;i++)pw[i]=pw[i-1]*2%M;
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		if(x!=-1)sz[x]++;
	}
	int ans=pw[n-1]-1;
	for(int i=1;i<=n;i++)(ans+=M-pw[sz[i]]+1)%=M;
	printf("%d",ans);
}