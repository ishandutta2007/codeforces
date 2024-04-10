#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define inf 1000000000
using namespace std;
int t,n,a[105],f[105][105];
int book[105];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)cin>>a[i];
		int ans=0;
		for (int i=1;i<=n;i++){
			f[i][i-1]=0;
			for (int j=i;j<=n;j++){
				f[i][j]=0;
				memset(book,0,sizeof(book));
				int mex=0;
				for (int k=j;k>=i;k--){
					if (a[k]<=101)book[a[k]]++;
					while(book[mex]!=0)mex++;
					f[i][j]=max(f[i][j],f[i][k-1]+mex+1);
				}
				ans+=f[i][j];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}