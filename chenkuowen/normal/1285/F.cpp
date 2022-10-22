#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5+1e5;
vector<int> factor[N];
bool is_pr[N];
int mu[N],pr[N],top_pr;
void sieve(int n){
	for(int i=2;i<=n;++i) is_pr[i]=1;
	is_pr[1]=0; top_pr=0; mu[1]=1;
	for(int i=2;i<=n;++i){
		if(is_pr[i]){
			pr[++top_pr]=i;
			mu[i]=-1;
		}
		for(int j=1;j<=top_pr&&i*pr[j]<=n;++j){
			is_pr[i*pr[j]]=0;
			if(i%pr[j]==0){
				mu[i*pr[j]]=0;
				break;
			}else mu[i*pr[j]]=mu[i]*mu[pr[j]];
		}
	}
}
struct DS{
	int cnt[N];
	void add(int x,int k){
		for(auto d:factor[x]) cnt[d]+=k;
	}
	int query(int x){
		int ret=0;
		for(auto d:factor[x]) ret+=mu[d]*cnt[d];
		return ret;
	}
	void check(){
		for(int i=0;i<N;++i)
			assert(cnt[i]==0);
	}
}op;
ll solve(vector<int> a){
	for(int i=0;i<a.size();++i) op.add(a[i],1);
	int p=0;
	ll ans=0;
	for(int i=(int)a.size()-1;i>=0;--i){
		op.add(a[i],-1);
		if(i==p) break;
		if(op.query(a[i])==0) continue;
		for(;op.query(a[i])>0;++p) op.add(a[p],-1);
		ans=max(ans,1ll*a[p-1]*a[i]);
		if(i==p) break;
	}
	return ans;
}
vector<int> b[N];
int main(){
	int n; scanf("%d",&n);
	sieve(N-1);
	for(int i=1;i<=N-1;++i)
		for(int j=1;i*j<=N-1;++j)
			factor[i*j].push_back(i);
	vector<int> a(n);
	ll ans=1;
	for(int i=0;i<a.size();++i){
		scanf("%d",&a[i]);
		ans=max(ans,ll(a[i]));
	}
	sort(a.begin(),a.end());
	a.erase(unique(a.begin(),a.end()),a.end());
	for(auto x:a)
		for(auto d:factor[x])
			b[d].push_back(x/d);
	for(int i=1;i<N;++i)
		ans=max(ans,solve(b[i])*i);
	printf("%lld\n",ans);
	return 0;
}