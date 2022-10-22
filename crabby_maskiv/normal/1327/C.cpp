#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n,m,k;

int main(){
	int i,j;
	cin>>n>>m>>k;
	for(i=1;i<=k;i++){
		int x,y;cin>>x>>y;
	}
	cout<<n-1+m-1+n*m-1<<endl;
	for(i=1;i<n;i++) cout<<"U";
	for(i=1;i<m;i++) cout<<"L";
	for(i=1;i<=n;i++){
		for(j=1;j<m;j++){
			if(i&1) cout<<"R";
			else cout<<"L";
		}
		if(i!=n) cout<<"D";
	}
	return 0;
}