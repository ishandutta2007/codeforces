#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
int f[105][105][105][2];
int p[105];
int main(){
	int n; scanf("%d",&n);
	int cnt0=n>>1,cnt1=n+1>>1;
	for(int i=1;i<=n;++i){
		scanf("%d",&p[i]);
		if(p[i]!=0){
			if(p[i]&1) --cnt1;
			else --cnt0;
		}
	}
	for(int i=0;i<=cnt0;++i)
		for(int j=0;j<=cnt1;++j)
			f[1][i][j][0]=f[1][i][j][1]=INF;
	if(p[1]!=0)
		f[1][0][0][p[1]&1]=0;
	else{
		f[1][1][0][0]=0;
		f[1][0][1][1]=0;
	}
//	printf("|%d %d|",cnt1,cnt2);
	for(int i=2;i<=n;++i){
		for(int x=0;x<=cnt0;++x)
			for(int y=0;y<=cnt1;++y)
				if(p[i]!=0){
					f[i][x][y][p[i]&1]=min(min(f[i-1][x][y][0]+(p[i]&1)
						,f[i-1][x][y][1]+(~p[i]&1)),INF);
					f[i][x][y][~p[i]&1]=INF;
				}else{
					if(x>0)
						f[i][x][y][0]=min(min(f[i-1][x-1][y][0]
							,f[i-1][x-1][y][1]+1),INF);
					else f[i][x][y][0]=INF;
					if(y>0)
						f[i][x][y][1]=min(min(f[i-1][x][y-1][0]+1
							,f[i-1][x][y-1][1]),INF);
					else f[i][x][y][1]=INF;
				}
	}
	int ans=min(f[n][cnt0][cnt1][0],f[n][cnt0][cnt1][1]);
	printf("%d\n",ans);
	return 0;
}