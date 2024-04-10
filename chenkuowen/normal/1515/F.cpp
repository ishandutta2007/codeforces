#include<bits/stdc++.h>
using namespace std;
const int N=5+3e5;
typedef long long ll;
struct DSF{
	int fa[N];
	void init(int n){ for(int i=1;i<=n;++i) fa[i]=i; }
	int fs(int x){
		if(fa[x]!=x) fa[x]=fs(fa[x]);
		return fa[x];
	}
	void merge(int x,int y){ fa[fs(y)]=fs(x);  }
}dsf;
list<pair<int,int> > e[N];
priority_queue<pair<ll,int> > q;
ll a[N];
int main(){
	int n,m,val; scanf("%d%d%d",&n,&m,&val);
	dsf.init(n); 
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		q.push(make_pair(a[i],i));
	}
	for(int i=1;i<=m;++i){
		int x,y; scanf("%d%d",&x,&y);
		e[x].push_back(make_pair(y,i));
		e[y].push_back(make_pair(x,i));
	}
	vector<int> ans;
	while(!q.empty()){
		int x=q.top().second; ll k=q.top().first; q.pop();
		if(dsf.fs(x)!=x||k!=a[x]) continue;
		while(!e[x].empty()){
			auto it=e[x].begin();
			int y=dsf.fs(it->first);
			if(y==x){
				e[x].erase(it);
				continue;
			}
			if(a[x]+a[y]<val){
				puts("NO");
				exit(0);
			}
			ans.push_back(it->second);
			dsf.merge(y,x);
			e[y].splice(e[y].end(),e[x]);
			a[y]=a[y]+a[x]-val;
			q.push(make_pair(a[y],y));
			break;
		}
	}
	puts("YES");
	for(auto x:ans) printf("%d\n",x);
	return 0;
}