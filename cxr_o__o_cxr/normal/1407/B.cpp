//starusc
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
int a[1004],vis[1004];
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
int main(){
	for(int T=read(),n,p,pp,d;T--;){
		n=read();
		for(int i=1;i<=n;i++)vis[i]=0;
		for(int i=1;i<=n;i++)a[i]=read();
		p=1;
		for(int i=2;i<=n;i++)if(a[i]>a[p])p=i;
		cout<<a[p]<<" ";
		vis[p]=1;
		d=a[p];
		for(int i=2;i<=n;i++){
			pp=0;
			for(int j=1;j<=n;j++)if(!vis[j]&&(!pp||gcd(d,a[j])>gcd(d,a[pp])))pp=j;
			p=pp;
			cout<<a[p]<<" ";
			vis[p]=1;
			d=gcd(d,a[p]);
		}
		puts("");
	}	
	return (0-0);
}