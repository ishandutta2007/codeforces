//starusc
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
int n,c[2];
int main(){
	for(int T=read();T--;){
		n=read();
		c[0]=c[1]=0;
		for(int i=1;i<=n;i++)c[read()]++;
		if(c[1]<=(n>>1)){
			cout<<c[0]<<"\n";
			for(int i=1;i<=c[0];i++)cout<<"0 ";puts("");
		}
		else{
			c[1]-=c[1]&1;
			cout<<c[1]<<"\n";
			for(int i=1;i<=c[1];i++)cout<<"1 ";puts("");
		}
	}	
	return (0-0);
}