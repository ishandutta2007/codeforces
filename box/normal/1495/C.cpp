#include <bits/stdc++.h>
using namespace std;
#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, (a))
#define rep1(i, a) iter(i, 1, (a)+1)
string x[505];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t,n,m,d;cin>>t;
	while(t--){
		cin>>n>>m;d=!(n%3);
		rep(i,n)cin>>x[i];
		rep(i,n)if(i%3==d)rep(j,m)x[i][j]='X';
		rep(i,n)if(i%3==d+1&&i!=n-1)rep(j,m)if(x[i][j]=='X'||x[i+1][j]=='X'||j==m-1){x[i][j]=x[i+1][j]='X';break;}
		rep(i,n)cout<<x[i]<<'\n';
	}
	return 0;
}