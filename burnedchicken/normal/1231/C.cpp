#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) loopii(i,0,a)
#define loopii(i,b,a) for(int i=b; i<(a); i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pow2(x) (1ll<<(x))
 
using namespace std;

const int Mod=1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int n,m,x,y;
	cin >> n >> m;
	int a[n][m];
	loop(n) loopi(j,m) cin >> a[i][j];
	bool ok;
	for(int i=n+m-3; i>=0; i--){
		if(i>=n-1) x=n-1,y=i-n+1;
		else x=i,y=0;
		while(1){
			if(x<0||y>=m) break;
			ok=true;
			if(a[x][y]==0) a[x][y]=min(a[x][y+1],a[x+1][y])-1;
			else{
				if(x==n-1){
					if(a[x][y]>=a[x][y+1]) ok=false;
				}
				else if(y==m-1){
					if(a[x][y]>=a[x+1][y]) ok=false;
				}
				else{
					if(a[x][y]>=min(a[x][y+1],a[x+1][y])) ok=false;
				}
				if(!ok){
					cout << "-1\n";
					return 0;
				}
			}
			x--;
			y++;
		}
	}
	ll ans=0;
	loop(n) loopi(j,m) ans+=a[i][j];
	cout << ans << "\n";
	return 0;
}