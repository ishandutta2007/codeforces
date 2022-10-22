#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n,x; scanf("%d%d",&n,&x);
		multiset<ll> s;
		for(int i=1;i<=n;++i){
			ll x; scanf("%lld",&x);
			s.insert(x);
		}
		int ans=0;
		while(!s.empty()){
			ll k=*s.begin();
			s.erase(s.begin());
			if(s.find(x*k)!=s.end()){
				s.erase(s.find(x*k));
			}else ++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}