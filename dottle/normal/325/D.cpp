#pragma GCC optimize(3) 
#include<bits/stdc++.h>
const int N=4096,Z=12;
using namespace std;

int r,c,n,ans;
int P(int x,int y){if(y==0)y=c<<1;if(y==(c<<1)+1)y=1;return ((x<<Z+1)|y);} 
int fa[2*N*N],del[2*N*N],v[2*N*N];
int gf(int k){return k==fa[k]?k:fa[k]=gf(fa[k]);}
int dx[]={0,1,-1,0,1,1,-1,-1},dy[]={-1,0,0,1,1,-1,1,-1};

void mrg(int x,int y){
	int fx=gf(x),fy=gf(y);
	if(fx!=fy)fa[fx]=fy;
}

void solve(){
	cin>>r>>c>>n;
	if(c==1)cout<<0,exit(0);
	for(int i=0;i<2*N*N;i++)fa[i]=i;
	for(int i=1;i<=n;i++){
		int x,y;cin>>x>>y;
		int fl=0;
		for(int i=0;i<8;i++)
			if(del[P(x+dx[i],y+dy[i])])
				v[gf(P(x+dx[i],y+dy[i]))]=1;
		for(int i=0;i<8;i++)
			if(del[P(x+dx[i],y+c+dy[i])])
				fl|=v[gf(P(x+dx[i],y+c+dy[i]))];
		for(int i=0;i<8;i++)
			if(del[P(x+dx[i],y+dy[i])])
				v[gf(P(x+dx[i],y+dy[i]))]=0;
		if(fl)continue;
		ans++;
		for(int i=0;i<8;i++){
			int tx=x+dx[i],ty=y+dy[i];
			if(tx==0||tx==r+1)continue;
			if(del[P(tx,ty)])mrg(P(x,y),P(tx,ty));
		}del[P(x,y)]=1; 
		y+=c;
		for(int i=0;i<8;i++){
			int tx=x+dx[i],ty=y+dy[i];
			if(tx==0||tx==r+1)continue;
			if(del[P(tx,ty)])mrg(P(x,y),P(tx,ty));
		}del[P(x,y)]=1;
	}
	cout<<ans<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;//cin>>_T;
	while(_T--)solve();
}