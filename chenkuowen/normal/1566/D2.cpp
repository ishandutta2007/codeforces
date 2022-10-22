#include<bits/stdc++.h>
using namespace std;
const int N=5+1e5;
int d[305][305],a[N],rk[N],n,m;
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
bool cmp(int x,int y){
	return make_pair((x-1)/m,-(x-1)%m)>make_pair((y-1)/m,-(y-1)%m);
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;++i)
		scanf("%d",&a[i]),key[i]=make_pair(a[i],i);
	sort(key+1,key+(n*m)+1);
	map<int,vector<int> > mp,mp2;
	for(int i=1;i<=n*m;++i)
		mp[key[i].first].push_back(i);
	for(auto& x:mp){
		vector<int> z=x.second;
		sort(z.begin(),z.end(),cmp);
		mp2[x.first]=z;
	}
	long long ans=0;
	for(int i=1;i<=n;++i) bit[i]=BIT(m);
	for(int i=1;i<=n*m;++i){
		int t=mp2[a[i]].back(); mp2[a[i]].pop_back();
//		printf("<%d>",t);
		int x=(t-1)/m+1,y=(t-1)%m+1;
		ans+=bit[x].query(y);
		bit[x].add(y,1);
	}
	printf("%lld\n",ans);
	}
	return 0;
}