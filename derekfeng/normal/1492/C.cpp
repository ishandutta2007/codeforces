#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[200004],t[200004];
int L[200004],R[200004],ans;
int main(){
	scanf("%d%d%s%s",&n,&m,s+1,t+1);
	int N=0;
	for(int i=1;i<=n;i++)if(N<m&&t[N+1]==s[i])N++,L[N]=i;
	N=m+1;
	for(int i=n;i;i--)if(N>1&&t[N-1]==s[i])N--,R[N]=i;
	for(int i=1;i<m;i++)ans=max(ans,R[i+1]-L[i]);
	printf("%d",ans);
}