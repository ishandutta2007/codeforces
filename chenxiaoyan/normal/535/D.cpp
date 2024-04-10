/*



*/
#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int qpow(int x,int y){
	int res=1;
	while(y){
		if(y&1)res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return res;
}
const int M=1000000,S=1000000;
int n,m,s;
char a[M+5];
int z[M+1];
void z_init(){
	int zl=0,zr=0;
	for(int i=2;i<=m;i++)
		if(zr<i){
			while(i+z[i]<=m&&a[i+z[i]]==a[1+z[i]])z[i]++;
			if(z[i])zl=i,zr=i+z[i]-1;
		}
		else if(i+z[i-zl+1]<=zr)z[i]=z[i-zl+1];
		else{
			z[i]=zr-i+1;
			while(i+z[i]<=m&&a[i+z[i]]==a[1+z[i]])z[i]++;
			zl=i;zr=i+z[i]-1;
		}
}
int pos[S+1];
int main(){
	cin>>n>>s>>a+1;
	if(!s)return cout<<qpow(26,n),0; 
	m=strlen(a+1);
	z_init();
	for(int i=1;i<=s;i++)cin>>pos[i];
	int ans=pos[1]-1;
	for(int i=2;i<=s;i++)
		if(pos[i]>pos[i-1]+m-1)ans+=pos[i]-pos[i-1]-m;
		else if(pos[i]-pos[i-1]+1+z[pos[i]-pos[i-1]+1]-1<m)return cout<<0,0;
	ans+=n-(pos[s]+m-1);
	cout<<qpow(26,ans);
	return 0;
}
/*1
6 2
ioi
1 3
*/
/*2
5 2
ioi
1 2
*/
/*3
1 0
a
*/