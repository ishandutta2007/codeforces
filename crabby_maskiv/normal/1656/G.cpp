#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e5+5;
int n,m,k;
int a[N],b[N],t[N];
int fa[N],deg[N];
int rt(int u){
	if(fa[u]==u) return u;
	return fa[u]=rt(fa[u]);
}
inline void merge(int u,int v){
	u=rt(u);v=rt(v);
	fa[u]=v;
}
vector<int> g[N];
vector<int> ans;
bool vis[N];
void euler(int u){
	while(!g[u].empty()){
		int v=g[u].back();
		g[u].pop_back();
		euler(v);
		ans.push_back(u);
	}
}
int answ[N];
int p1[N],p2[N];
void solve(){
	int i,j;
	k=(n+1>>1);
	for(i=1;i<=n/2;i++) t[i]=t[n-i+1]=i;
	if(n&1) t[k]=k;
	
	for(i=1;i<=n;i++) b[i]=a[i];
	sort(b+1,b+n+1);
	m=unique(b+1,b+n+1)-(b+1);
	for(i=1;i<=n;i++) a[i]=lower_bound(b+1,b+m+1,a[i])-b+k;
	for(i=1;i<=k+m;i++) fa[i]=i;
	for(i=1;i<=k;i++){
		deg[i]++;
		deg[a[i]]++;
		merge(i,a[i]);
		g[a[i]].push_back(i);
		if(i!=n-i+1){
			deg[i]++;
			deg[a[n-i+1]]++;
			merge(i,a[n-i+1]);
			g[a[n-i+1]].push_back(i);
		}
	}
	int c1=0,c2=0;
	for(i=1;i<=k;i++) c1+=(deg[i]&1);
	for(i=k+1;i<=k+m;i++) c2+=(deg[i]&1);
	if(c1!=c2){
		cout<<"NO"<<endl;
		return;
	}
	if((n&1)&&c1>1){
		cout<<"NO"<<endl;
		return;
	}
	if(!(n&1)&&c1){
		cout<<"NO"<<endl;
		return;
	}
	if(c1){
		for(i=1;i<=k;i++) if(deg[i]&1) break;
		for(j=k+1;j<=k+m;j++) if(deg[j]&1) break;
		g[i].push_back(j);
		deg[i]--;deg[j]--;
	}
	for(i=1;i<=k;i++)
		if(deg[i]) p1[rt(i)]=i;
	for(i=k+1;i<=k+m;i++)
		if(deg[i]) p2[rt(i)]=i;
	for(i=1;i<=k+m;i++){
		if(p1[i]){
			for(j=i+1;j<=k+m;j++) if(p2[j]) break;
			if(j>k+m) continue;
			g[p1[i]].push_back(p2[j]);
			g[p1[i]].push_back(p2[j]);
			deg[p1[i]]-=2;deg[p2[j]]-=2;
			merge(p1[i],p2[j]);
		}
	}
	set<int> s;
	for(i=k+1;i<=k+m;i++)
		if(deg[i]) s.insert(i);
	for(i=1;i<=k;i++){
		if(deg[i]){
			int x=*s.begin();
			g[i].push_back(x);
			g[i].push_back(x);
			deg[i]-=2;deg[x]-=2;
			merge(i,x);
			if(!deg[x]) s.erase(x);
		}
	}
	for(i=2;i<=k+m;i++){
		if(rt(i)!=rt(i-1)){
			cout<<"NO"<<endl;
			return;
		}
	}
	euler(1);
	int f=ans.size();
	for(i=0;i<f;i++){
		if(ans[i]<=k){
			if(a[ans[i]]!=ans[(i+1)%f]) ans[i]=n-ans[i]+1;
			else if(a[n-ans[i]+1]!=ans[(i+1)%f]);
			else{
				if(vis[ans[i]]) ans[i]=n-ans[i]+1;
				else vis[ans[i]]=1;
			}
			if(i>1) answ[ans[i]]=ans[i-2];
		}
	}
	answ[ans[1]]=ans.back();
	cout<<"YES"<<endl;
	for(i=1;i<=n;i++) cout<<answ[i]<<" ";
	cout<<endl;
	//for(i=1;i<=n;i++) cerr<<a[answ[i]]<<" ";
	//cerr<<endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n;
		for(i=1;i<=n;i++) cin>>a[i];
		solve();
		for(i=1;i<=2*n;i++){
			a[i]=b[i]=t[i]=vis[i]=fa[i]=deg[i]=answ[i]=p1[i]=p2[i]=0;
			g[i].clear();
		}
		ans.clear();
	}
	return 0;
}