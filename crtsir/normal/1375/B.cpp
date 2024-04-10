#include<bits/stdc++.h>
using namespace std;
int T,n,m,a[303][303],ans[303][303];
int main(){cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d",&a[i][j]),ans[i][j]=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m-1;j++)
				ans[i][j]++;
		for(int i=0;i<n-1;i++)
			for(int j=0;j<m;j++)
				ans[i][j]++;
		for(int i=1;i<n;i++)
			for(int j=0;j<m;j++)
				ans[i][j]++;
		for(int i=0;i<n;i++)
			for(int j=1;j<m;j++)
				ans[i][j]++;bool can=1;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(a[i][j]>ans[i][j])can=0;
		if(can){
			cout<<"YES\n";
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++)printf("%d ",ans[i][j]);
				cout<<endl;
			}
		}else
			cout<<"NO\n";
	}
}