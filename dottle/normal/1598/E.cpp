#include<bits/stdc++.h>
#define int long long
const int N=1005;
using namespace std;

int f[2][N][N],n,m,q,a[N][N],ans;

void updt(int x,int y){
	if(x<1||y<1)return;
	if(a[x][y]){
		ans-=(f[0][x][y]+f[1][x][y]-1);
		int newa=f[1][x][y+1]+1,newb=f[0][x+1][y]+1;
		f[0][x][y]=newa,f[1][x][y]=newb;
		ans+=(f[0][x][y]+f[1][x][y]-1);
	}else{
		ans-=(f[0][x][y]+f[1][x][y]-1);
	}
}

main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>q;
	ans=-n*m;
	for(int i=n;i;i--)
		for(int j=m;j;j--)
			a[i][j]=1,updt(i,j);
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		if(a[x][y]){
			a[x][y]=0,updt(x,y),f[0][x][y]=f[1][x][y]=0;
			int i=x,j=y;
			while(i>0&j>0){
				--i;if(!a[i][j])break;updt(i,j);
				--j;if(!a[i][j])break;updt(i,j);
			}
			i=x,j=y;while(i>0&j>0){
				--j;if(!a[i][j])break;updt(i,j);
				--i;if(!a[i][j])break;updt(i,j);
			}
		}
		else{
			ans--;
			a[x][y]=1,updt(x,y);
			int i=x,j=y;
			while(i>0&j>0){
				--i;if(!a[i][j])break;updt(i,j);
				--j;if(!a[i][j])break;updt(i,j);
			}
			i=x,j=y;while(i>0&j>0){
				--j;if(!a[i][j])break;updt(i,j);
				--i;if(!a[i][j])break;updt(i,j);
			}
		}
		cout<<ans<<endl;
	}
}