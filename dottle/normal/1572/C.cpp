#include<bits/stdc++.h>
const int N=5005;
using namespace std;

int f[N][N],n,a[N],t;
vector<int> d[N];

int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<=n+5;i++)
			for(int j=0;j<=n+5;j++)
				f[i][j]=0;
		for(int i=1;i<=n;i++)
			d[i].clear();
		for(int i=1;i<=n;i++)
			cin>>a[i],d[a[i]].emplace_back(i);
		for(int l=2;l<=n;l++)
			for(int i=1;i<=n-l+1;i++){
				int j=i+l-1;
				f[i][j]=f[i+1][j];
				for(auto k:d[a[i]])
					if(k>i&&k<=j)
						f[i][j]=max(f[i][j],f[i+1][k-1]+1+f[k][j]);
			}
		cout<<n-1-f[1][n]<<endl;
	}
}