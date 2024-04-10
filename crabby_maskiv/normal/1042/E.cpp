#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1005;
const ll mod=998244353;
int n,m;
struct node{
	ll x,y,v;
	bool operator <(const node &b)const
	{
		return v<b.v;
	}
}s[N*N];
ll inv[N*N];
ll a[N][N];
ll dp[N][N];
int main(){
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cin>>a[i][j];a[i][j]++;
			node tmp;tmp.x=i;tmp.y=j;tmp.v=a[i][j];
			s[(i-1)*m+j]=tmp;
		}
	}
	sort(s+1,s+n*m+1);
	inv[1]=1;
	for(i=2;i<=n*m;i++) inv[i]=((-(mod/i)*inv[mod%i]%mod)+mod)%mod;
	ll x2=0,x1=0,y2=0,y1=0,ss=0;
	int p=1;
	while(s[p].v==s[1].v){
		int x=s[p].x;
		int y=s[p].y;
		x2+=x*x;x1+=x;
		y2+=y*y;y1+=y;
		x2%=mod;x1%=mod;y2%=mod;y1%=mod;
		ss+=dp[x][y];
		ss%=mod;
		p++;
	}
	for(i=p;i<=n*m;){
		int pos=i;
		while(s[i].v==s[pos].v){
			ll x=s[pos].x;
			ll y=s[pos].y;
			dp[x][y]=(ss+((x2-2*x*x1+(i-1)*x*x)%mod+mod)%mod+((y2-2*y*y1+(i-1)*y*y)%mod+mod)%mod)*inv[i-1]%mod;
			pos++;
		}
		for(j=i;j<pos;j++){
			ll x=s[j].x;
			ll y=s[j].y;
			x2+=x*x;x1+=x;
			y2+=y*y;y1+=y;
			x2%=mod;x1%=mod;y2%=mod;y1%=mod;
			ss+=dp[x][y];
			ss%=mod;
		}
		i=pos;
	}
	int x,y;cin>>x>>y;
	cout<<dp[x][y];
	return 0;
}