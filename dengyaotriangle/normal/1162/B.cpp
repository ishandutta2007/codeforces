#include<bits/stdc++.h>

using namespace std;

const int maxn=55;

int n,m;
int a[maxn][maxn],b[maxn][maxn];
int main(){
	memset(a,0xc0,sizeof(a));
	memset(b,0xc0,sizeof(b));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cin>>a[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cin>>b[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]<b[i][j]) swap(a[i][j],b[i][j]);
		}
	}
	bool ok=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!(a[i-1][j]<a[i][j]))ok=1;
			if(!(a[i][j-1]<a[i][j]))ok=1;
			if(!(b[i-1][j]<b[i][j]))ok=1;
			if(!(b[i][j-1]<b[i][j]))ok=1;
		}
	}
	if(ok)cout<<"Impossible";
	else cout<<"Possible";
	return 0;
}