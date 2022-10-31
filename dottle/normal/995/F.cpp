#include<bits/stdc++.h>
#define int long long
const int N=3005,mod=1e9+7; 
using namespace std;

int f[N][N],s[N][N],n,d,ans;
#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx;
}e[N<<1];int hd[N],S;
void add(int fr,int to){
    e[++S]=(edge){to,hd[fr]},hd[fr]=S;
}

int gsc(int x,int y){
    int ans=1;
    for(int i=1;i<=y;i<<=1,x=x*x%mod)
        if(y&i)
            ans=ans*x%mod;
    return ans;
}int inv(int k){return gsc(k,mod-2);}

void dfs(int k,int fa){
	for(int i=1;i<=n;i++)f[k][i]=1;
	fore(k)if(_to!=fa){
		dfs(_to,k);
		for(int j=1;j<=n;j++)
			f[k][j]=f[k][j]*s[_to][j]%mod;
	}
	for(int i=1;i<=n;i++)
		s[k][i]=(s[k][i-1]+f[k][i])%mod;
}

main(){
	ios::sync_with_stdio(false);
	cin>>n>>d;
	for(int i=2,x;i<=n;i++)cin>>x,add(x,i);
	++n,dfs(1,0);
	
	for(int i=1;i<=n;i++){
		int nw=s[1][i],iv=1;
		for(int j=1;j<=n;j++)
			if(i!=j)
				nw=nw*(d-j)%mod,iv=iv*(i-j)%mod;
		ans+=nw*inv(iv)%mod; 
	}
	cout<<(ans%mod+mod)%mod;
}