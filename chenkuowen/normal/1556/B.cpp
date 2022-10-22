#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e18;
ll solve(vector<int> a){
	int p0=0,p1=1;
	ll ans=0;
	for(int i=0;i<a.size();++i){
		if(a[i]==0){
			if(p0>=a.size()) return INF;
			ans+=abs(i-p0),p0+=2;
		}else{
			if(p1>=a.size()) return INF;
			ans+=abs(i-p1),p1+=2;
		}
	}
	return ans/2;
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		vector<int> a(n),b(n);
		for(int i=0;i<n;++i){
			int x; scanf("%d",&x);
			a[i]=x&1,b[i]=~x&1;
		}
		ll ans=min(solve(a),solve(b));
		if(ans==INF) puts("-1");
		else printf("%lld\n",ans);
	}
	return 0;
}