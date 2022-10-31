#include<bits/stdc++.h>
#define int long long
const int N=105,M=1005;
using namespace std;

int n,s;
int k[N],v[N][M],t[N][M];
int ans;

void calc(int x,int y){
	int nx=1,ny=1,nt=0,sx=0,sy=0,px=0,py=0,ppx=0,ppy=0;
	while(nx<=k[x]||ny<=k[y]){
		int xt=min(t[x][nx],t[y][ny]);
		int del=xt-nt;
		sx+=del*v[x][nx],sy+=del*v[y][ny];
		if(px==py){
			if((ppx<ppy&&sx>sy)||(ppx>ppy&&sx<sy))
				ans++;
		}else{
			if((px<py&&sx>sy)||(px>py&&sx<sy))
				ans++;
		}
		ppx=px,ppy=py;
		px=sx,py=sy;
		nt=xt;
		if(nt==t[x][nx])nx++;
		if(nt==t[y][ny])ny++;
	}
}

void solve(){
	cin>>n>>s;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>v[i][j]>>t[i][j],t[i][j]+=t[i][j-1];
		t[i][k[i]+1]=1e9;
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			calc(i,j);
	cout<<ans<<endl;
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}