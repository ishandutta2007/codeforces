#include<bits/stdc++.h>
#define int long long
const int N=2005000;
using namespace std;

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx;
}e[N];int hd[N],S;
void add(int fr,int to){
    e[++S]=(edge){to,hd[fr]},hd[fr]=S;
}
void gx(int&x,int y){x=max(x,y);}

int n,ans;
int w[N],f[6][N];

void dfs(int k,int fa){
	f[1][k]=f[3][k]=w[k];
	fore(k)if(_to!=fa){
		dfs(_to,k);
		gx(f[4][k],f[3][_to]+f[1][k]);
		gx(f[4][k],f[4][_to]);
		gx(f[4][k],f[2][_to]+f[2][k]);
		gx(f[4][k],f[1][_to]+f[3][k]);
		gx(f[3][k],f[3][_to]+w[k]);
		gx(f[3][k],f[2][_to]+f[1][k]);
		gx(f[3][k],f[1][_to]+f[5][k]+w[k]);
		gx(f[2][k],f[1][_to]+f[1][k]);
		gx(f[5][k],f[2][_to]);
		gx(f[2][k],f[2][_to]);
		gx(f[1][k],f[1][_to]+w[k]);
	}
	for(int i=2;i<=4;i++)gx(f[i][k],f[i-1][k]);
}

main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		add(x,y),add(y,x);
	}
	dfs(1,0);
	cout<<f[4][1];
}