#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1005;
int n,m;
ll p[N];
int len;
int a[N][N];
int main(){
	int i,j;
	cin>>n>>m;
	if(n==1&&m==1){
		cout<<0;
		return 0;
	}
	if(m==1){
		for(i=1;i<=n;i++) cout<<i+1<<endl;
		return 0;
	}
	for(i=1;i<=m;i++) a[1][i]=i+1;
	for(i=2;i<=n;i++){
		for(j=1;j<=m;j++)
			a[i][j]=a[1][j]*(m+i);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}