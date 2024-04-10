#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 505;
 ll n, m, t, v[N][N], b[N][N], a[N][N], d[N][N][25], k;//(x, y)step
 bool in(int x, int y) {
    return 1<=x&&x<=n&&1<=y&&y<=m;
 }
ll dfs(ll x, ll y, ll step) {
    if(d[x][y][step]) return d[x][y][step];//
    if(step==0) return d[x][y][0];
    ll ans=1e18;
    if(in(x, y+1)) ans=min(dfs(x, y+1, step-1)+a[x][y], ans);
    if(in(x+1, y)) ans=min(dfs(x+1, y, step-1)+b[x][y], ans);
    if(in(x, y-1)) ans=min(dfs(x, y-1, step-1)+a[x][y-1], ans);
    if(in(x-1, y)) ans=min(dfs(x-1, y, step-1)+b[x-1][y], ans);
    d[x][y][step]=ans;//
    return ans;
}
int main(){
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++) {
        for(int j=1; j<m; j++) {
            cin>>a[i][j];
        }
	}
	for(int i=1; i<n; i++) {
        for(int j=1; j<=m; j++) {
            cin>>b[i][j];
        }
	}
	if(k%2==1) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                cout<<-1<<" \n"[j==m];
            }
        }
	}else {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                cout<<2*dfs(i, j, k/2)<<" \n"[j==m];//k/20  
            }
        }
	}
    return 0;
}