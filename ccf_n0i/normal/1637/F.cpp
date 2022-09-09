#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define rep0(i,n) for ((i)=0;(i)<(n);(i)++)
using namespace std;
int a[233333],mx[233333];
long long ans;
int rt;
vector<int> v[233333];
void dfs(int x,int p){
	int son=0;
	for(int y:v[x]){
		if(y==p)continue;
		dfs(y,x);
		if(mx[y]>mx[x]){
			son=y;
			mx[x]=mx[y];
		}
	}
	mx[x]=max(mx[x],a[x]);
	int tmx=0;
	for(int y:v[x]){
		if(y==p)continue;
		if(son!=y){
			ans+=mx[y];
			tmx=max(tmx,mx[y]);
		}
	}
	if(x==rt) ans-=tmx;
}
void solve(){
	int n,i;
	scanf("%d",&n);
	rep(i,n) scanf("%d",a+i);
	rep(i,n-1){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	rt=1;
	rep(i,n){
		if(a[i]>a[rt]) rt=i;
	}
	dfs(rt,-1);
	printf("%lld\n",ans+a[rt]*2);
}
int main(){
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}