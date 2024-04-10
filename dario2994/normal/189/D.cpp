#include <iostream>
#define rp(i,n) for(int i=1;i<=n;i++)
using namespace std;

int n,m,r;
int real[61][61][61];
int res[61][61][61];

int main(){
	cin >> n >> m >> r;
	rp(i,m)rp(u,n)rp(v,n)cin >> real[i][u][v];
	rp(c,m)rp(h,n)rp(i,n)rp(j,n)real[c][i][j]=min(real[c][i][j],real[c][i][h]+real[c][h][j]);
	for(int k=0;k<=n;k++)rp(i,n)rp(j,n)res[k][i][j]=1000000000;
	rp(i,n)rp(j,n)rp(c,m)res[0][i][j]=min(res[0][i][j],real[c][i][j]);
	rp(k,n)rp(i,n)rp(j,n)rp(v,n)res[k][i][j]=min(res[k][i][j],res[0][i][v]+res[k-1][v][j]);
	for(int i=0;i<r;i++){
		int u,v,w;
		cin >> u >> v >> w;
		cout << res[min(w,n)][u][v]<< endl;
	}
}