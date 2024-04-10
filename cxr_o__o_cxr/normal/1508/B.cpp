//starusc
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1,c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline bool cmp(int x,int y){
	return x<=60?(1ll<<x)<y:0;
}
const int N=1e5+4;
int n,k,a[N];
inline void solve(){
	n=read();k=read();
	if(cmp(n-1,k)){puts("-1");return;}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(cmp(max(0ll,n-j-1),k))k-=(1ll<<(n-j-1));
			else{
				for(int u=i;u<=j;u++)cout<<i+j-u<<" ";
				i=j; 
				break;
			}
		}
	}
	puts("");
}
signed main(){
	for(int T=read();T--;)solve();
	return (0-0);
}