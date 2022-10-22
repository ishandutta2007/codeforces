#include<bits/stdc++.h>
#define inv(x) (po(x,mod-2))
using namespace std;
typedef long long ll;
const int N=200005;
const ll mod=998244353;
int n,m;
ll po(ll x,ll k){
	if(!k) return 1;
	ll s=po(x,k>>1);s=s*s%mod;
	if(k&1) return s*x%mod;
	return s;
}
ll p[N];
ll s[N];
ll p1[N],p2[N];
struct node{
	int l,r;
	ll val;
	bool operator <(const node &b)const{
		return l<b.l;
	}
	node(int l,int r,ll val):l(l),r(r),val(val){}
};
set<node> st;
bool use[N];
node mknode(int l,int r){
	ll p_2=(p2[r]-p2[l-1]+mod)%mod;
	ll p_1=(p1[r]-p1[l-1]+mod)%mod;
	ll p=((p_2-p_1*(l-1))%mod+mod)%mod;
	p=p*inv(s[l-1])%mod;
	p=p*(inv(s[r])*s[l-1]%mod)%mod;
	return node(l,r,((p+r-l+1)%mod+mod)%mod);
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	ll tmp=inv(100);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>p[i];p[i]=p[i]*tmp%mod;
	}
	s[0]=1;
	for(i=1;i<=n;i++){
		s[i]=s[i-1]*p[i]%mod;
		p1[i]=(p1[i-1]+s[i-1]*(1-p[i]+mod))%mod;
		p2[i]=(p2[i-1]+(s[i-1]*(1-p[i]+mod)%mod)*i)%mod;
	}
	st.insert(node(1,n,inv(s[n])*p2[n]%mod+n));
	st.insert(node(n+1,n+1,0));
	ll ans=inv(s[n])*p2[n]%mod+n;
	while(m--){
		int u;cin>>u;
		if(use[u]==1){
			auto it1=st.lower_bound(node(u,u,0));
			auto it2=it1;
			it1--;
			ans=(ans-(it1->val)+mod)%mod;
			ans=(ans-(it2->val)+mod)%mod;
			node p=mknode(it1->l,it2->r);
			ans=(ans+p.val)%mod;
			st.erase(it1);st.erase(it2);
			st.insert(p);
		}
		else{
			auto it=st.upper_bound(node(u,u,0));
			it--;
			ans=(ans-(it->val)+mod)%mod;
			node pl=mknode(it->l,u-1);
			ans=(ans+pl.val)%mod;
			node pr=mknode(u,it->r);
			ans=(ans+pr.val)%mod;
			st.erase(it);
			st.insert(pl);
			st.insert(pr);
		}
		use[u]^=1;
		cout<<ans<<endl;
	}
	return 0;
}