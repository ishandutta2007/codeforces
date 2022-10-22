#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=500+5;
int n,m;
int c[N][N];
int main(){
	int i,j;
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _;cin>>_;
	while(_--){
		cin>>n;
		ll ans=0;
		for(i=1;i<=2*n;i++){
			for(j=1;j<=2*n;j++){
				cin>>c[i][j];
				if(i>n&&j>n) ans+=c[i][j];
			}
		}
		cout<<ans+min(c[1][n+1],min(c[1][n*2],min(c[n][n+1],min(c[n][n*2],
		min(c[n+1][1],min(c[n+1][n],min(c[n*2][1],c[n*2][n])))))))<<endl;
	}
	return 0;
}