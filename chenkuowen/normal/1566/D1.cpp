#include<bits/stdc++.h>
using namespace std;
const int N=5+1e5;
int d[305][305],a[N],rk[N];
pair<int,int> key[N];
struct BIT{
	vector<int> c;
	BIT(int n=0){ c=vector<int>(n+1,0); }
	inline void add(int x,int k){
		for(;x<c.size();x+=x&-x) c[x]+=k;
	}
	inline int query(int x){
		int ret=0;
		for(;x;x-=x&-x) ret+=c[x];
		return ret;
	}
}bit[305];
int main(){
	int T; scanf("%d",&T);
	while(T--){
	int n,m; scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;++i)
		scanf("%d",&a[i]),key[i]=make_pair(a[i],-i);
	sort(key+1,key+(n*m)+1);
	for(int i=1;i<=n*m;++i)
		rk[-key[i].second]=i;
	long long ans=0;
	for(int i=1;i<=n;++i) bit[i]=BIT(m);
	for(int i=1;i<=n*m;++i){
		int x=(rk[i]-1)/m+1,y=(rk[i]-1)%m+1;
		ans+=bit[x].query(y);
		bit[x].add(y,1);
	}
	printf("%lld\n",ans);
	}
	return 0;
}