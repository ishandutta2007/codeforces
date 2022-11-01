#include<iostream>
using namespace std;
#define R register int
const int v[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int f[1001][1001][2];
bool tag[1001][1001];
inline int Go(int x,int y,int d,const int n,const int m){
	int res=0;
	while(x<=n&&y<=m&&x!=0&&y!=0&&tag[x][y]==false){
		res++;
		x+=v[d][0];
		y+=v[d][1];
		d^=1;
	}
	return res;
}
inline int Calc(int x,int y,const int n,const int m){
	tag[x][y]=false;
	int q[4];
	for(R i=0;i!=4;i++){
		q[i]=Go(x,y,i,n,m);
	}
	return q[0]*q[3]+q[1]*q[2]-1;
}
int main(){
	int n,m,q,ans,x,y;
	cin>>n>>m>>q;
	ans=-n*m;
	for(R i=1;i<=n;i++){
		for(R j=1;j<=m;j++){
			f[i][j][0]=f[i-1][j][1]+1;
			f[i][j][1]=f[i][j-1][0]+1;
			ans+=f[i][j][0]+f[i][j][1];
		}
	}
	for(R i=0;i!=q;i++){
		cin>>x>>y;
		bool t=tag[x][y]^true;
		if(tag[x][y]==true){
			ans+=Calc(x,y,n,m); 
		}else{
			ans-=Calc(x,y,n,m);
		}
		tag[x][y]=t;
		cout<<ans<<endl;
	}
	return 0;
}