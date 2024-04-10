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
const int N=1e5+4;
int n,k,to[N][40],w[N][40],s[N][40];
signed main(){
	n=read();k=read();
	for(int i=1;i<=n;i++)to[i][0]=read()+1;
	for(int i=1;i<=n;i++)w[i][0]=s[i][0]=read();
	for(int j=1;(1ll<<j)<=k;j++)
		for(int i=1;i<=n;i++){
			to[i][j]=to[to[i][j-1]][j-1];
			w[i][j]=min(w[i][j-1],w[to[i][j-1]][j-1]);
			s[i][j]=s[i][j-1]+s[to[i][j-1]][j-1];
		}
	for(int i=1,x,wei,sum;i<=n;i++){
		x=i;
		wei=INT_MAX;
		sum=0;
		for(int j=0;(1ll<<j)<=k;j++)
			if((k>>j)&1){
				wei=min(wei,w[x][j]);
				sum+=s[x][j];
				x=to[x][j];
			}
		cout<<sum<<" "<<wei<<"\n";
	}
	return (0-0);
}