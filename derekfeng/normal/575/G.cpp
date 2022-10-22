#include <bits/stdc++.h>
using namespace std;
const int N=400010;
vector<pair<int,int> > g[N];
int dist[N],x[N];
bool was[N];
int pr[N];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++){
		g[i].clear();
	}
	for (int i=0;i<m;i++){
		int foo,bar,qwe;
		scanf("%d%d%d",&foo,&bar,&qwe);
		g[foo].push_back(make_pair(bar,qwe));
		g[bar].push_back(make_pair(foo,qwe));
	}
	for (int i=0;i<n;i++){
		dist[i]=-1;
	}
	int b=0,e=0;
	x[0]=0;
	dist[0]=0;
	while (b<=e){
		int sz=g[x[b]].size();
		for (int j=0;j<sz;j++){
			int u=g[x[b]][j].first;
			if (dist[u]==-1){
				e++;
				x[e]=u;
				dist[u]=dist[x[b]]+1;
			}
		}
		b++;
	}
	for (int i=0;i<n;i++){
		was[i]=false;
	}
	vector<int>can_be;
	can_be.push_back(n-1);
	b=0,e=0;
	was[n-1]=true;
	while (b<=e){
		int v=can_be[b];
		int sz=g[v].size();
		for (int j=0;j<sz;j++){
			int u=g[v][j].first;
			if (!was[u] && g[v][j].second==0){
				e++;
				can_be.push_back(u);
				pr[u]=v;
				was[u]=true;
			}
		}
		b++;
	}
	int ddd=dist[n-1];
	for (int i=1;i<n;i++){
		if (was[i]){
			ddd=min(ddd,dist[i]);
		}
	}
	bool zeros=true;
	for (int pos=ddd;pos>0;pos--){
		int ccnt=can_be.size();
		int best=42;
		for (int id=0;id<ccnt;id++){
			int v=can_be[id];
			int sz=g[v].size();
			for (int j=0;j<sz;j++){
				int u=g[v][j].first;
				int cost=g[v][j].second;
				if (dist[u]+1==pos && cost<best){
					best=cost;
				}
			}
		}
		if (best>0){
			zeros=false;
		}
		if (pos==1 || !zeros){
			printf("%d",best);
		}
		vector<int> new_can_be;
		for (int id=0;id<ccnt;id++){
			int v=can_be[id];
			int sz=g[v].size();
			for (int j=0;j<sz;j++){
				int u=g[v][j].first;
				int cost=g[v][j].second;
				if (dist[u]+1==pos && cost==best && !was[u]){
					was[u]=true;
					new_can_be.push_back(u);
					pr[u]=v;
				}
			}
		}
		can_be=new_can_be;
	}
	printf("\n");
	vector<int>ret;
	int cur=0;
	ret.push_back(cur);
	while (cur!=n-1){
		cur=pr[cur];
		ret.push_back(cur);
	}
	printf("%d\n",ret.size());
	for (int i=0;i<(int)ret.size();i++){
		if (i>0) putchar(' ');
		printf("%d",ret[i]);
	}
	printf("\n");
	return 0;
}