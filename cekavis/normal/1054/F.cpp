#include<cstdio>
#include<algorithm>
#include<set>
#include<string.h>
#include<map>
#include<vector>

using namespace std;
#define ll long long

const int N = 1005;
int n, r, cnta, cntb, x[N], y[N], q[N], p[N];
bool vis[N], mat[N];
vector<int> c[N], d[N];
map<int,multiset<int>> f, g;
struct item{ int x, l, r;} a[N], b[N];
bool match(int x){
	for(int i:c[x]) if(!vis[i]){
		vis[i]=1;
		if(!p[i] || match(p[i])) return p[i]=x, mat[x]=1;
	}
	return 0;
}
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d%d", x+i, y+i), f[x[i]].insert(y[i]), g[y[i]].insert(x[i]);
	for(auto &i:f){
		auto j=i.second.begin();
		int x=*j;
		while(++j!=i.second.end()) a[++cnta]=(item){i.first, x, *j}, i.second.insert(x), x=*j;
		i.second.insert(x);
	}
	for(auto &i:g){
		auto j=i.second.begin();
		int x=*j;
		while(++j!=i.second.end()) b[++cntb]=(item){i.first, x, *j}, i.second.insert(x), x=*j;
		i.second.insert(x);
	}
	for(int i=1; i<=cnta; ++i) for(int j=1; j<=cntb; ++j)
		if(b[j].l<a[i].x && a[i].x<b[j].r && a[i].l<b[j].x && b[j].x<a[i].r)
			c[i].push_back(j), d[j].push_back(i);//, printf(" %d <--> %d \n", i, j);
	for(int i=1; i<=cnta; ++i) if(!mat[i]) match(i), memset(vis, 0, sizeof vis);
	for(int i=1; i<=cnta; ++i) if(!mat[i]) q[++r]=i;
	for(int l=1; l<=r; ++l){
		int x=q[l];
		for(int i:c[x]) if(!vis[i]){
			vis[i]=1;
			if(mat[p[i]]) mat[p[i]]=0, q[++r]=p[i];
		}
	}
	int h=n, v=n, o=1;
	for(int i=1; i<=cnta; ++i) if(!mat[i])
		f[a[i].x].erase(f[a[i].x].find(a[i].l)), f[a[i].x].erase(f[a[i].x].find(a[i].r)), --h;
	for(int i=1; i<=cntb; ++i) if(!vis[i])
		g[b[i].x].erase(g[b[i].x].find(b[i].l)), g[b[i].x].erase(g[b[i].x].find(b[i].r)), --v;
	printf("%d\n", v);
	for(auto &i:g) for(int j:i.second) printf("%d %d%c", j, i.first, " \n"[o^=1]);
	printf("%d\n", h);
	for(auto &i:f) for(int j:i.second) printf("%d %d%c", i.first, j, " \n"[o^=1]);
	return 0;
}