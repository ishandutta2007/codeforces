#include<bits/stdc++.h>

using namespace std;

const int MX=200005;

int n,m;
int pol[MX],*G[MX];
int nor[MX],noc[MX];
bool isc(int x,int y){
	int rx=(x-1)/m+1,cx=x-m*(rx-1),ry=(y-1)/m+1,cy=y-m*(ry-1);
	if(rx==ry&&abs(cx-cy)<=1)return true;
	if(cx==cy&&abs(rx-ry)<=1)return true;
	return false;
}
bool ck(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(j<m&&isc(G[i][j],G[i][j+1])){/*cerr<<i<<' '<<j<<endl;*/return false;}
			if(i<n&&isc(G[i][j],G[i+1][j])){/*cerr<<i<<' '<<j<<endl;*/return false;}
		}
	return true;
}
bool sol(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			G[i][j]=m*(i-1)+j;
	if(n==1&&m==1)return true;
	else if(n==1){
		if(m<=3)return false;
		int it=1;
		for(int i=2;i<=m;i+=2)G[1][i]=it++;
		for(int i=1;i<=m;i+=2)G[1][i]=it++;
		return true;
	}else if(m==1){
		if(n<=3)return false;
		int it=1;
		for(int i=2;i<=n;i+=2)G[i][1]=it++;
		for(int i=1;i<=n;i+=2)G[i][1]=it++;
		return true;
	}else if(n>=2&&m>=4){
		for(int i=1;i<=n;i+=2){
			int t1=G[i][1],t2=G[i][2];
			for(int j=1;j<=m-2;j++)G[i][j]=G[i][j+2];
			G[i][m-1]=t1,G[i][m]=t2;
		}
		for(int i=1;i<=m;i+=2){
			int t=G[1][i];
			for(int j=1;j<=n-1;j++)G[j][i]=G[j+1][i];
			G[n][i]=t;
		}
		return true;
	}else if(m>=2&&n>=4){
		for(int i=1;i<=m;i+=2){
			int t1=G[1][i],t2=G[2][i];
			for(int j=1;j<=n-2;j++)G[j][i]=G[j+2][i];
			G[n-1][i]=t1,G[n][i]=t2;
		}
		for(int i=1;i<=n;i+=2){
			int t=G[i][1];
			for(int j=1;j<=m-1;j++)G[i][j]=G[i][j+1];
			G[i][m]=t;
		}
		return true;
	}else{
		if(n==3&&m==3){
			G[1][1]=4,G[1][2]=3,G[1][3]=5,
			G[2][1]=2,G[2][2]=7,G[2][3]=9,
			G[3][1]=8,G[3][2]=6,G[3][3]=1;
			return true;
		}
		for(int i=1;i<=6000;i++){
			random_shuffle(G[1]+1,G[n]+m+1);
			if(ck())return true;
		}
		return false;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	G[1]=pol;for(int i=2;i<=n;i++)G[i]=G[i-1]+m;
	if(sol()){
		ck();
		cout<<"YES"<<endl;
		for(int i=1;i<=n;cout<<endl,i++)
			for(int j=1;j<=m;j++)cout<<G[i][j]<<' ';
	}else cout<<"NO"<<endl;
	return 0;
}