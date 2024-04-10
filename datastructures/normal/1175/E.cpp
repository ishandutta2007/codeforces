#include <iostream>
#include <cstdio>
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x; 
}
int n,m,f[500005][21],l,r;
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		l=read(),r=read();
		f[l][0]=max(f[l][0],r);
	}
	for (int i=1;i<=500000;i++)f[i][0]=max(f[i][0],f[i-1][0]);
	for (int j=1;j<=20;j++)
		for (int i=0;i<=500000;i++){
			f[i][j]=f[i][j-1];
			if (i>0)f[i][j]=max(f[i][j],f[i-1][j]);
			f[i][j]=max(f[i][j],f[f[i][j-1]][j-1]);
		}
	while(m--){
		l=read(),r=read();
		int ans=0;
		for (int i=20;i>=0;i--)
			if (f[l][i]<r)l=f[l][i],ans+=(1<<i);
		l=f[l][0],ans++;
		if (l>=r)printf("%d\n",ans);
		else puts("-1");
	}
	return 0;
}