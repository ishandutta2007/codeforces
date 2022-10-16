#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=60,INF=2e9;
int n,f[MAXN][MAXN][MAXN][MAXN],s[MAXN][MAXN];
char tmp;
int dp(int x1,int y1,int x2,int y2){
	if(f[x1][y1][x2][y2]!=-1)return f[x1][y1][x2][y2];
	f[x1][y1][x2][y2]=max(x2-x1+1,y2-y1+1);
	for(int i=x1;i<x2;i++){
		f[x1][y1][x2][y2]=min(f[x1][y1][x2][y2],dp(x1,y1,i,y2)+dp(i+1,y1,x2,y2));
	}
	for(int i=y1;i<y2;i++){
		f[x1][y1][x2][y2]=min(f[x1][y1][x2][y2],dp(x1,y1,x2,i)+dp(x1,i+1,x2,y2));
	}
	return f[x1][y1][x2][y2];
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>tmp;
			if(tmp=='#')s[i][j]=1;
		}
	}
	for(int x1=1;x1<=n;x1++){
		for(int y1=1;y1<=n;y1++){
			for(int x2=x1;x2<=n;x2++){
				for(int y2=y1;y2<=n;y2++){
					f[x1][y1][x2][y2]=-1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j][i][j]=s[i][j];
		}
	}
	printf("%d",dp(1,1,n,n));
	return 0;
}