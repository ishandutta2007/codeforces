#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int d[120][110][20][20];
int main(){
	int n1,n2,k1,k2;
	scanf("%d%d%d%d",&n1,&n2,&k1,&k2);
	d[0][0][0][0]=1;
	for(int i=0; i<=n1; ++i){
		for(int j=0; j<=n2; ++j){
			for(int x=0; x<=k1; ++x){
				for(int y=0; y<=k2; ++y){
					if(d[i][j][x][y]==0) continue;
					if(i!=n1 && x!=k1){
						d[i+1][j][x+1][0]+=d[i][j][x][y];
						d[i+1][j][x+1][0]%=100000000;
					}
					if(j!=n2 && y!=k2){
						d[i][j+1][0][y+1]+=d[i][j][x][y];
						d[i][j+1][0][y+1]%=100000000;
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=1; i<=k1; ++i) ans+=d[n1][n2][i][0],ans%=100000000;
	for(int i=1; i<=k2; ++i) ans+=d[n1][n2][0][i],ans%=100000000;
	printf("%d",ans);
	return 0;
}