#include <iostream> 
#include <cstdio>
using namespace std;
int t,n,m,a[55][55];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				cin>>a[i][j];
		int aa=0,bb=0;
		for (int i=1;i<=n;i++){
			int fg=1;
			for (int j=1;j<=m;j++)
				if (a[i][j]==1)fg=0;
			aa+=fg;
		}
		for (int i=1;i<=m;i++){
			int fg=1;
			for (int j=1;j<=n;j++)
				if (a[j][i]==1)fg=0;
			bb+=fg;
		}
		if (min(aa,bb)%2==0)puts("Vivek");
		else puts("Ashish");
	}
	return 0;
}