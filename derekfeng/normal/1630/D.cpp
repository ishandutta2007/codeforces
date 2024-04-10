#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[1000005],x;
vector<int>v[500005];
void sol(){
	ll ans=0;scanf("%d%d",&n,&m);int G=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),ans+=a[i];
	for(int i=0;i<m;i++){
		scanf("%d",&x);
		G=__gcd(G,x);
	}
	for(int i=0;i<G;i++)v[i].clear();
	for(int i=1;i<=n;i++)v[i%G].push_back(-2*a[i]);
	for(int i=0;i<G;i++)sort(v[i].begin(),v[i].end(),greater<int>());
	ll ret=ans;
	for(int i=0;i<G;i++){
		ll tmp=0,cur=0;
		for(int j=0;j+1<v[i].size();j+=2){
			cur+=v[i][j],cur+=v[i][j+1];
			tmp=max(tmp,cur);
		}
		ret+=tmp;
	}
	ll qwq=ans;
	for(int i=0;i<G;i++){
		ll tmp=v[i][0],cur=v[i][0];
		for(int j=1;j+1<v[i].size();j+=2){
			cur+=v[i][j],cur+=v[i][j+1];
			tmp=max(tmp,cur);
		}
		qwq+=tmp;
	}
	printf("%lld\n",max(qwq,ret));
}
int main(){
	int T;scanf("%d",&T);
	while(T--)sol();
}