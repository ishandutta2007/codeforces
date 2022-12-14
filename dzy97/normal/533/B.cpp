#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mo=1e9+7;
int pow(int a,int b,int c){int ret=1;for(;b;b>>=1,a=1LL*a*a%c)if(b&1)ret=1LL*ret*a%c;return ret;}
const int N=2e5+10;
int h[N],p[N],n1[N],ee,a[N],n;
ll f[N][2],ans;
void ae(int x,int y){
	p[ee]=y;n1[ee]=h[x];h[x]=ee++;
}
void dp(int x){
	int cnt=0;
	ll mn=1e18;
	f[x][1]=-1e18;
	f[x][0]=0;
	for(int i=h[x];~i;i=n1[i]){
		dp(p[i]);
		ll f1=f[x][1],f0=f[x][0];
		f[x][1]=max(f[x][1],max(f1+f[p[i]][0],f0+f[p[i]][1]));
		f[x][0]=max(f[x][0],max(f1+f[p[i]][1],f0+f[p[i]][0]));
	}
	f[x][1]=max(f[x][1],f[x][0]+a[x]);
}
int main(){
	scanf("%d",&n);
	memset(h,-1,sizeof(h));
	int x,rt=1;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x,&a[i]);
		if(x==-1)rt=i;else ae(x,i);
	}
	dp(rt);
	for(int i=1;i<=n;i++)
		ans=max(ans,f[i][0]),ans=max(ans,f[i][1]);
	cout << ans << endl;
	return 0;
}