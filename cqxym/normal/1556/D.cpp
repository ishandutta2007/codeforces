#include<iostream>
#include<algorithm>
using namespace std;
#define R register int
int f[10001][30],a[10001],g[10001][2];
inline void Deal(int x,int y,int a,int b){
	for(R i=0;i!=30;i++){
		int c=a>>i&1,d=b>>i&1;
		if(c==d){
			f[x][i]=f[y][i]=c;
		}else if(f[x][i]!=-1){
			f[y][i]=f[x][i]^1;
		}else if(f[y][i]!=-1){
			f[x][i]=f[y][i]^1;
		}
	}
}
inline void Ask(int x,int y,int&a,int&b){
	cout<<"and "<<x<<' '<<y<<endl;
	cin>>a;
	cout<<"or "<<x<<' '<<y<<endl;
	cin>>b;
	Deal(x,y,a,b);
}
int main(){
	int n,k,a0,b0;
	cin>>n>>k;
	for(R i=1;i<=n;i++){
		for(R j=0;j!=30;j++){
			f[i][j]=-1;
		}
	}
	Ask(2,3,a0,b0);
	for(R i=2;i<=n;i++){
		Ask(1,i,g[i][0],g[i][1]);
	}
	Deal(2,3,a0,b0);
	for(R i=2;i<=n;i++){
		Deal(1,i,g[i][0],g[i][1]);
	}
	for(R i=1;i<=n;i++){
		for(R j=0;j!=30;j++){
			a[i]|=f[i][j]<<j;
		}
	}
	sort(a+1,a+1+n);
	cout<<"finish "<<a[k]<<endl;
	return 0;
}