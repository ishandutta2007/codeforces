#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
inline int read(){
	register int x=0;
	register char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
} 
int t,n,a[300005],b[300005],f[300005][3];
inline void out(register int x){
	if (x<10){
		putchar(x+'0');
		return;
	}
	out(x/10);
	putchar(x%10+'0');
	return;
}
signed main(){
	cin>>t;
	memset(f,0x7f,sizeof(f));
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)a[i]=read(),b[i]=read();
		f[1][0]=0,f[1][1]=f[1][2]=b[1];
		for (int i=1;i<=n;i++)
			for (int j=0;j<3;j++)
				for (int k=0;k<3;k++){
					if (a[i]+j==a[i-1]+k)continue;
					f[i][j]=min(f[i][j],f[i-1][k]+j*b[i]);
				}
		int ans=min(min(f[n][0],f[n][1]),f[n][2]);
		out(ans),putchar('\n');
		for (int i=1;i<=n;i++)f[i][0]=f[i][1]=f[i][2]=9e18;
	}
}
// I AK IOI