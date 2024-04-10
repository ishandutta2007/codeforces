#include<bits/stdc++.h>
using namespace std;
bool tmp(int a,int b){
	return a>b;
}
long long n,s[100003],q,pre[100003],x[100003],ax[100003],bx[100003];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i];
	sort(s+1,s+n+1); 
	ax[0]=0;
	for(int i=1;i<n;i++)
		ax[i]=s[i+1]-s[i];
	sort(ax,ax+n);
	for(int i=1;i<n;i++)
		bx[i]=bx[i-1]+(ax[i]-ax[i-1])*(n+1-i);
	for(int i=2;i<=n;i++)
		pre[i-2]=s[i]-s[i-1];
	sort(pre,pre+n-1,tmp); 
	x[0]=pre[0];
	for(int i=1;i<n-1;i++)
		x[i]=x[i-1]+pre[i];
	cin>>q;
	while(q--){
		long long tmp1,tmp2,c; 
		cin>>tmp1>>tmp2;
		c=tmp2-tmp1+1;
		int l=lower_bound(ax,ax+n,c)-&ax[0]-1;cout<<bx[l]+(c-ax[l])*(n-l)<<' ' ;
	}
}