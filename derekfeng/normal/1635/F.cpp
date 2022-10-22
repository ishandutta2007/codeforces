#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q,x[300005],w[300005],l[300005];
stack<int>st;
vector<int>add[300005],ask[300005];
ll bit[300005],ans[300005];
void ud(int i,ll x){
	for(;i;i-=i&-i)bit[i]=min(bit[i],x);
}
ll qr(int i){
	ll ret=1ll<<62;
	for(;i<=n;i+=i&-i)ret=min(ret,bit[i]);
	return ret;
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&w[i]),bit[i]=1ll<<62;
	for(int i=1;i<=n;i++){
		while(!st.empty()&&w[st.top()]>w[i])st.pop();
		if(!st.empty())add[i].push_back(st.top());
		st.push(i);
	}
	while(!st.empty())st.pop();
	for(int i=n;i;i--){
		while(!st.empty()&&w[st.top()]>w[i])st.pop();
		if(!st.empty())add[st.top()].push_back(i);
		st.push(i);
	}
	for(int i=1,r;i<=q;i++)scanf("%d%d",&l[i],&r),ask[r].push_back(i);
	for(int i=1;i<=n;i++){
		for(auto z:add[i])ud(z,(ll)(x[i]-x[z])*(w[i]+w[z]));
		for(auto z:ask[i])ans[z]=qr(l[z]);
	}
	for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
}