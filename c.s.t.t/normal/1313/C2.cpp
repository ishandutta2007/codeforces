#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,num[500100],mx,mxp,s1[500100],s2[500100];
stack<int>s;
signed main(){
	scanf("%I64d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d",&num[i]);
	s.push(0);
	for(int i=1;i<=n;i++){
		while(num[i]<=num[s.top()])s.pop();
		s1[i]=s1[s.top()]+num[i]*(i-s.top());
		s.push(i);
	}
	while(!s.empty())s.pop();
	s.push(n+1);
	for(int i=n;i>=1;i--){
		while(num[i]<=num[s.top()])s.pop();
		s2[i]=s2[s.top()]+num[i]*(s.top()-i);
		s.push(i);
	}
	for(int i=1;i<=n;i++)if(mx<s1[i]+s2[i]-num[i])mx=s1[i]+s2[i]-num[i],mxp=i;
	for(int j=mxp+1;j<=n;j++)num[j]=min(num[j],num[j-1]);
	for(int j=mxp-1;j>=1;j--)num[j]=min(num[j],num[j+1]);
	for(int i=1;i<=n;i++)printf("%I64d ",num[i]);
	return 0;
}