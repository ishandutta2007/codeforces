//starusc
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=1e6+4;
int n,r1,r2,r3,d,a[N],f[N][2][2];
signed main(){
	n=read();r1=read();r2=read();r3=read();d=read();
	for(int i=1;i<=n;i++)a[i]=read();
	memset(f,0x3f,sizeof(f));
	f[0][0][0]=0;
	for(int i=1,one,two;i<=n;i++){
		one=r1*a[i]+r3;
		two=min(r1*(a[i]+1),r2)+min(min(r1,r2),r3);
		f[i][0][0]=min(f[i-1][0][1]+two,min(f[i-1][0][0],f[i-1][0][1])+one)+d;
		f[i][0][1]=min(f[i-1][0][0],f[i-1][0][1])+two+d*3;
		f[i][1][0]=min(f[i-1][1][0],f[i-1][1][1])+one+d*2;
		f[i][1][1]=min(min(f[i-1][0][0],f[i-1][0][1])+two,min(f[i-1][1][0],f[i-1][1][1])+two)+d*2;
	}
	cout<<min(min(f[n][1][0]-d*2,f[n][1][1]),min(f[n][0][0],f[n][0][1])-d);
	return (0-0);
}