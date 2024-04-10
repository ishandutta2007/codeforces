#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
typedef long long ll;
const int N=1<<8,mod=998244353;
int n,aa,bb,cc,dd;
int a[N],b[N],in[N],vis[N],nxt[N],f[N],g[N],h[N],ans[N];
int fac[N],C[N][N],S[N][N],M[N][N];
void dfs(int x){
	if(!x)return;
	vis[x]=2;
	if(nxt[x]!=x){
		if(vis[nxt[x]]==2)dd++;
		else{dfs(nxt[x]);nxt[x]=nxt[nxt[x]];}
	}
	vis[x]=1;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	for(int i=1;i<=n;i++)nxt[i]=i;
	for(int i=1;i<=n;i++){
		if(a[i]){
			if(a[i]==b[i]){dd++;vis[a[i]]=1;}
			else nxt[a[i]]=b[i];
		}
		if(b[i])in[b[i]]++;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])dfs(i);
	for(int i=1;i<=n;i++){
		if(!a[i]){
			if(nxt[b[i]])bb++;
			else aa++;
		}
		else if(!in[a[i]]&&!nxt[b[i]])cc++;
	}
	for(int i=0;i<=n;i++){
		C[i][0]=M[i][0]=1;
		for(int j=1;j<=i;j++){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
			M[i][j]=(ll)M[i][j-1]*(i-j+1)%mod;
		}
	}
	S[0][0]=S[1][1]=fac[0]=fac[1]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=i;j++)
			S[i][j]=((ll)S[i-1][j]*(i-1)+S[i-1][j-1])%mod;
	for(int i=2;i<=n;i++)fac[i]=(ll)fac[i-1]*i%mod;
	for(int i=0;i<=bb;i++)
		for(int j=i;j<=bb;j++)
			f[i]=((ll)S[j][i]*C[bb][j]%mod*(aa+bb-j-1>=0?M[aa+bb-j-1][bb-j]:1)+f[i])%mod;
	for(int i=0;i<=cc;i++)
		for(int j=i;j<=cc;j++)
			g[i]=((ll)S[j][i]*C[cc][j]%mod*(aa+cc-j-1>=0?M[aa+cc-j-1][cc-j]:1)+g[i])%mod;
	for(int i=0;i<=aa;i++)
		h[i]=(ll)S[aa][i]*fac[aa]%mod;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=i;j++)
			for(int k=0;k<=i-j;k++)
				ans[i]=((ll)h[j]*f[k]%mod*g[i-j-k]+ans[i])%mod;
	for(int i=0;i<n;i++){
		if(n-i-dd<0)cout<<"0 ";
		else cout<<ans[n-i-dd]<<" ";
	}
	return (0-0);
}