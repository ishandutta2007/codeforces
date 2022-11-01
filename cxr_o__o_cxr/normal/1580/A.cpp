//starusc
#include<bits/stdc++.h>
using namespace std;
#define O(x) cerr<<(x)<<" : "<<#x<<"\n"
inline int read(){
	int x=0,f=1,c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=404,inf=1e9;
int n,m,mn,ans,s[N],w[N];
char a[N][N];
inline void solve(){
	ans=inf;
	n=read();m=read();
	for(int i=1;i<=n;i++){
		scanf("%s",a[i]+1);
		for(int j=1;j<=m;j++)a[i][j]&=1;
	}
	for(int l=1;l<=n-4;l++){
		for(int i=1;i<=m;i++)w[i]=(!a[l+1][i])+(!a[l+2][i])+(!a[l+3][i]);
		for(int r=l+4;r<=n;r++){
			mn=inf;
			for(int i=1;i<=m;i++){
				s[i]=s[i-1]+(!a[l][i])+(!a[r][i])+(r-l-1-w[i]);
				if(i>=4){
					mn=min(mn,w[i-3]-s[i-3]);
					ans=min(ans,s[i-1]+w[i]+mn);
				}
			}
			for(int i=1;i<=m;i++)w[i]+=(!a[r][i]);
		}
	}
	cout<<ans<<"\n";
}
int main(){
	for(int T=read();T--;)solve();
	return (0-0);
}