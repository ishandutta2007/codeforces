#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50,mod=998244353;
int n,m,a[N],b[N],mn[N],ans=1;
map<int,int>cnt;
int read(){
	int x=0,c;
	while(!isdigit(c=getchar()));
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x;
}
int main(){
	n=read();m=read();
	if(m>n)puts("0"),exit(0);
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++)b[i]=read();mn[n]=a[n];cnt[mn[n]]++;
	for(int i=n-1;i;i--)mn[i]=min(mn[i+1],a[i]),cnt[mn[i]]++;
	if(mn[1]!=b[1])puts("0"),exit(0);
	for(int i=2;i<=m;i++)ans=1ll*ans*cnt[b[i]]%mod;
	cout<<ans;
	return 0;
}