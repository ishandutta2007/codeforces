#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
} 
int n,k,a[4005][4005],s[4005][4005],val[4005][4005],f[805][4005];
void calc(int nowl,int nowr,int pl,int pr,int s){
	if (nowl>nowr)return;
	int mid=(nowl+nowr)/2,p=-1;
	for (int i=pl;i<=min(mid,pr);i++)
		if (f[s-1][i-1]+val[i][mid]<=f[s][mid])f[s][mid]=f[s-1][i-1]+val[i][mid],p=i;
	calc(nowl,mid-1,pl,p,s);
	calc(mid+1,nowr,p,pr,s);
	return;
}
int main(){
	cin>>n>>k;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			a[i][j]=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			s[i][j]=s[i][j-1]+a[i][j];
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
			val[i][j]=val[i][j-1]+(s[j][j]-s[j][i-1]);
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	for (int i=1;i<=k;i++)calc(1,n,1,n,i);
	cout<<f[k][n]<<endl;
	return 0;
}