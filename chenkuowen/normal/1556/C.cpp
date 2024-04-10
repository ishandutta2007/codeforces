#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pop_back(stack<pair<ll,int> >& stk,ll c){
	ll ans=0;
	while(c>0){
		pair<ll,int> x=stk.top(); stk.pop();
		ll d=min(c,x.first);
		x.first-=d;
		c-=d;
		if(x.first>0) stk.push(x);
		ans+=d*x.second;
	}
	return ans;
}
int main(){
	int n; scanf("%d",&n);
	vector<int> c(n);
	for(int i=0;i<n;++i) scanf("%d",&c[i]);
	stack<pair<ll,int> > stk;
	stk.push(make_pair((ll)1e18,0));
	stk.push(make_pair(1,1));
	ll ans=0;
	for(int i=0;i<n;++i){
		if(~i&1){
			stk.push(make_pair(c[i],1));
		}else{
			pop_back(stk,1);
			ans+=pop_back(stk,c[i]-1);
			int t=stk.top().second;
			ans+=pop_back(stk,1);
			stk.push(make_pair(1,t+1));
//			printf("<%lld>",ans);
		}
	}
	printf("%lld\n",ans);
	return 0;
}