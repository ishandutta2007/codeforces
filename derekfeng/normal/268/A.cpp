#include<bits/stdc++.h>
using namespace std;
int n,h[33],g[33],ans;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>h[i]>>g[i];
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(i!=j&&h[i]==g[j])ans++;
	cout<<ans;	
}