#include <iostream>
#include <cstdio>
#include <cstring>
#pragma GCC optimize(2)
#define inf 1000000000
using namespace std;
int t,n,c[105],f[2][205][205][47];
char s[105];
void upd(int &x,int y){
	if (y<x)x=y;
	return;
}int cnt;
int main(){
	//cin>>t;
	t=1;
	while(t--){
		scanf("%s",s+1);
		n=strlen(s+1);
		memset(c,0,sizeof(c));
		for (int i=1;i<=n;i++)c[i+3]=s[i]-'0';
		n+=3;
		memset(f,0x3f,sizeof(f));
		for (int i=0;i<=200;i++)
			for (int j=0;j<=200;j++)f[n&1][i][j][23]=0;
		for (int i=n;i>0;i--){
			for (int j=0;j<=200;j++)
				for (int k=0;k<=200;k++)
					for (int l=-23;l<=23;l++){
						if (f[i&1][j][k][l+23]>=10000)continue;
						for (int p=j;p>=max(0,j-9);p--){
							int t=p-k+l,d=0;
							if (t>=0)d=t/10;
							else d=-((-t+9)/10);
							if (t-d*10!=c[i])continue;
							upd(f[(i-1)&1][p][k][d+23],f[i&1][j][k][l+23]+p+k);
						}
						for (int p=k;p>=max(0,k-9);p--){
							int t=j-p+l,d=0;
							if (t>=0)d=t/10;
							else d=-((-t+9)/10);
							if (t-d*10!=c[i])continue;
							upd(f[(i-1)&1][j][p][d+23],f[i&1][j][k][l+23]+j+p);
						}
					}
			memset(f[i&1],0x3f,sizeof(f[i&1]));
		}
		int ans=f[0][0][0][23];
		cout<<ans<<endl;
	}
	return 0;
}