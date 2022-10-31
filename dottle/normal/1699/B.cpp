#include<bits/stdc++.h>
#define int long long
const int N=1050;
using namespace std;

int a[N][N];
void solve(){
	int n,m;cin>>n>>m;
	for(int x=0;x<n/2;x++)
		for(int y=0;y<m/2;y++){
			int i=x*2,j=y*2;
			if((x+y)&1){
				a[i][j]=1;
				a[i+1][j+1]=1;
				a[i][j+1]=0;
				a[i+1][j]=0;
			}else{
				a[i][j]=0;
				a[i+1][j+1]=0;
				a[i][j+1]=1;
				a[i+1][j]=1;
			}
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cout<<a[i][j]<<" \n"[j==m-1];
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}