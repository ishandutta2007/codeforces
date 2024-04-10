#include<bits/stdc++.h>
#define iter(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,a) iter(i,0,a)
#define rep1(i,a) iter(i,1,(a)+1)
using namespace std;
long long w[605][605];
long long sp[605][605];
long long iw[605][605];
int main() {
	int n,m;cin>>n>>m;
	rep1(i,n)rep1(j,n)sp[i][j]=1e18;
	rep1(i,n)sp[i][i]=0;
	rep1(i,m){
		int u,v,x;cin>>u>>v>>x;
		w[u][v]=w[v][u]=sp[u][v]=sp[v][u]=x;
	}
	rep1(k,n)rep1(i,n)rep1(j,n)
		sp[i][j]=min(sp[i][j],sp[i][k]+sp[k][j]);
	//rep1(i,n)rep1(j,n)cout<<sp[i][j]<<" \n"[j==n];
	int q;cin>>q;
	rep1(i,q){
		int u,v,l;cin>>u>>v>>l;
		iw[u][v]=iw[v][u]=l;
	}
	for(int k=n;k>=1;k--)rep1(i,n)rep1(j,n)
		iw[j][i]=iw[i][j]=max(iw[i][j],iw[i][k]-sp[k][j]);
	int ans=0;
	//rep1(i,n)rep1(j,n)cout<<iw[i][j]<<" \n"[j==n];
	rep1(i,n)iter(j,i+1,n+1)if(w[i][j]&&iw[i][j]>=w[i][j])ans++;
	cout<<ans<<endl;
}