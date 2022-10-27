#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 505;
 ll n, m, t, v[N][N], b[N][N], a[N][N];
void dfs(ll x, ll y, ll k) {
	if(b[k][k]<=1)return ;
	if(y-1>=1&&!a[x][y-1]) {
		a[x][y-1]=a[k][k];
		b[k][k]--;
		dfs(x,y-1,k);
	}else if(x+1<=n&&!a[x+1][y]) { 
		a[x+1][y]=a[k][k];
		b[k][k]--;	
		dfs(x+1,y,k);
	}else {
		b[k][k]--;	
		a[x][y+1]=a[k][k];
		dfs(x,y+1,k);
	}
}
int main(){	
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>b[i][i];
		a[i][i]=b[i][i];
	}
	for(int i=1; i<=n; i++) dfs(i, i, i);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=i; j++) {
			cout<<a[i][j]<<" \n"[j==i];
		}
	}  
    return 0;
}