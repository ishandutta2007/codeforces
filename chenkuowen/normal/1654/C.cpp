#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5+1e6;
multiset<ll> s;
bool dfs(ll x){
	if(s.find(x)!=s.end()){
		s.erase(s.find(x));
		return true;
	}
	if(x==1) return false;
	if(!dfs(x>>1)) return false;
	if(!dfs(x+1>>1)) return false;
	return true;
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		s.clear(); ll sum=0;
		for(int i=1;i<=n;++i){
			ll x; scanf("%lld",&x);
			sum+=x; s.insert(x);
		}
		if(dfs(sum)) puts("YES");
		else puts("NO");
	}
	return 0;
}