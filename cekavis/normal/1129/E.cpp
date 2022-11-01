#include<iostream>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<vector>

using namespace std;
#define ll long long

const int N = 505;
int n, now, siz[N], f[N];
bool vis[N];
vector<int> g, ans[N];
inline bool cmp(int x, int y){ return siz[x]<siz[y];}
void divide(int l, int r){
	if(l>r) return;
	cout<<1<<endl<<1<<endl<<r-l+1<<endl;
	for(int i=l; i<=r; ++i) cout<<g[i]<<' ';
	cout<<endl<<now<<endl;
	int x, mid=(l+r)>>1;
	cin>>x;
	if(!x) return;
	if(l==r) return vis[g[l]]=1, ans[now].push_back(g[l]);
	divide(l, mid), divide(mid+1, r);
}
int main() {
	cin>>n, siz[1]=n;
	for(int i=2; i<=n; ++i){
		cout<<1<<endl<<1<<endl<<n-1<<endl;
		for(int j=2; j<=n; ++j) cout<<j<<' ';
		cout<<endl<<i<<endl;
		cin>>siz[i];
	}
	for(int i=1; i<=n; ++i) f[i]=i;
	sort(f+1, f+n+1, cmp);
	for(int i=1; i<=n; ++i){
		now=f[i];
		divide(0, g.size()-1);
		for(unsigned i=0; i<g.size(); ++i) if(vis[g[i]]) g.erase(g.begin()+i--);
		g.push_back(now);
	}
	cout<<"ANSWER"<<endl;
	for(int i=1; i<=n; ++i) for(int j:ans[i]) cout<<i<<' '<<j<<endl;
	return 0;
}