#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <set>
#define int long long
#define mod 998244353
using namespace std;
int Qpow(int a,int p){
	if (p==0)return 1;
	int t=Qpow(a,p/2);
	t=t*t%mod;
	if (p&1)t=t*a%mod;
	return t;
}
int inv(int x){
	return Qpow(x,mod-2);
}
struct BIT{
	int tree[1000005],maxn;
	BIT(){
		memset(tree,0,sizeof(tree));
		maxn=1000000;
		return;
	}
	int lowbit(int x){
		return x&(-x);
	}
	void add(int pos,int val){
		while(pos<=maxn)tree[pos]=(tree[pos]+val)%mod,pos+=lowbit(pos);
		return;
	}
	int ask(int pos){
		int ans=0;
		while(pos)ans=(ans+tree[pos])%mod,pos-=lowbit(pos);
		return ans;
	}
}bit;
int n,m,a[200005],b[200005];
int fac[200005],cnt[200005];
int ans;
signed main(){
	fac[0]=1;
	for (int i=1;i<=200000;i++)fac[i]=fac[i-1]*i%mod;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cnt[a[i]]++;
	}
	for (int i=1;i<=m;i++)scanf("%lld",&b[i]);
	int nowval=1;
	for (int i=1;i<=200000;i++)nowval=nowval*fac[cnt[i]]%mod,bit.add(i,cnt[i]);
	for (int i=1;i<=n+1&&i<=m;i++){
		if (i>n)ans=(ans+1)%mod;
		ans=(ans+bit.ask(b[i]-1)*inv(nowval)%mod*fac[n-i])%mod;
		nowval=nowval*inv(fac[cnt[b[i]]])%mod;
		cnt[b[i]]--;
		if (cnt[b[i]]<0)break;
		nowval=nowval*fac[cnt[b[i]]]%mod;
		bit.add(b[i],-1);
	}
	cout<<ans<<endl;
	return 0;
}