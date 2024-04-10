#include <iostream>
#include <cstdio>
using namespace std;
int n,a[305][305];
int main(){
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	cin>>n;
	int cnt=0; 
	for (int i=1;i<=n;i++){
		if (i%2){
			for (int j=1;j<=n;j++)a[j][i]=++cnt;
		}
		else for (int j=n;j>=1;j--)a[j][i]=++cnt;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)cout<<a[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}