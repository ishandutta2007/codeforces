#include <set>
#include <queue>
#include <cstdio>
#include <vector>
namespace HyjMh{
	typedef long long ll;
	const int maxn = 2e5+5;
	int T,n,m,a[maxn],b[maxn];ll s[maxn];
	std :: queue <int> q;std :: set<int> S;std :: vector <int> G[maxn];
	void Del(int l,int r){
		if(l>r)l ^= r ^= l ^= r;
		auto it = S.lower_bound(l);
		while(it != S.end() && *it <= r)
			q.push(*it),S.erase(it),it = S.lower_bound(l);
	}
	int main(){
		scanf("%d",&T);
		while(T--){
			scanf("%d %d",&n,&m);
			for(int i=1;i<=n;++i)scanf("%d",&a[i]);
			for(int i=1;i<=n;++i)scanf("%d",&b[i]);
			for(int i=1;i<=n;++i)s[i] = s[i-1]+a[i]-b[i];
			while(!q.empty())q.pop();
			S.clear();for(int i=0;i<=n;++i)if(s[i])S.insert(i);else q.push(i);
			for(int i=0;i<=n;++i)G[i].clear();
			for(int i=1,l,r;i<=m;++i)
				scanf("%d %d",&l,&r),--l,G[l].push_back(r),G[r].push_back(l);
			if(s[n]){puts("NO");continue;}
			while(!q.empty()){
				int u = q.front();q.pop();
				for(int v:G[u])if(S.find(v) == S.end())Del(u,v);
			}
			puts(S.empty()?"YES":"NO");
		}
		return 0;
	}
}
int main(){return HyjMh::main();}