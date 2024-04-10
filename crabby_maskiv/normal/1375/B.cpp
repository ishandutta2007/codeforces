#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=305;
int a[N][N];
int n,m;
queue<pair<int,int> > q;
int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n>>m;
		bool flag=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				cin>>a[i][j];
				int cnt=0;
				if(i==1||i==n) cnt++;
				if(j==1||j==m) cnt++;
				if(a[i][j]>4-cnt) flag=1;
				a[i][j]=4-cnt;
			}
		}
		if(flag) cout<<"NO"<<endl;
		else{
			cout<<"YES"<<endl;
			for(i=1;i<=n;i++){
				for(j=1;j<=m;j++) cout<<a[i][j]<<" ";
				cout<<endl;
			}
		}
	}
	return 0;
}