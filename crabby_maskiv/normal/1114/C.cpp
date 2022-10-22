#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1000005;
const ll inf=0x3f3f3f3f3f3f3f3f;
const int mod=998244353;
template<typename T>inline void read(T &x) {
    int f=1;x=0;char c=getchar();
    while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    x*=f;return;
}
template<typename T,typename...Args>
	inline void read(T &x,Args &...args){
	read(x);read(args...);
}
ll n,m;
vector<ll> p;
bool np[maxn];
ll cnt[maxn];
ll cnt2[maxn];
int main()
{
	ll i,j;
	read(n,m);
	ll tmp=m;
	for(i=2;tmp>1;i++){
		if(i>tmp) break;
		if(i*i>m) break;
		if(tmp%i==0){
			p.push_back(i);
			while(tmp%i==0) tmp/=i;
		}
	}
	if(i*i==m) i--;
	for(;i>0;i--){
		if(i>tmp) break;
		ll k=m/i;
		if(k==1) continue;
		if(tmp%k==0){
			p.push_back(k);
			while(tmp%k==0) tmp/=k;
		}
	}
	for(i=0;i<p.size();i++){
		tmp=p[i];
		while(1){
			cnt[i]+=n/tmp;
			if(n/tmp<p[i]) break;
			tmp*=p[i];
		}
	}
	tmp=m;
	for(i=0;tmp>1;i++){
		while(tmp%p[i]==0){
			cnt2[i]++;
			tmp/=p[i];
		}
	}
	ll ans=inf;
	for(i=0;i<maxn;i++){
		if(!cnt2[i]) continue;
		ans=min(ans,cnt[i]/cnt2[i]);
	}
	cout<<ans;
	//not the same
	return 0;
}