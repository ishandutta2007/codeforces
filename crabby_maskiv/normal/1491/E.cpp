#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=2e5+5;
int n,m;
int sz[N],lft[N],rgt[N],cnt;
bool vis[N];
int fa[N];
vector<int> g[N];
void dfs0(int u){
	lft[u]=++cnt;
	for(auto v:g[u]){
		if(v==fa[u]) continue;
		fa[v]=u;
		dfs0(v);
	}
	rgt[u]=cnt;
}
void dfs1(int u){
	sz[u]=1;
	for(auto v:g[u]){
		if(v==fa[u]||!vis[v]) continue;
		fa[v]=u;
		dfs1(v);
		sz[u]+=sz[v];
	}
}
int fib[N];
int a[N],b[N];
bool judge(int l,int r){
	int k=lower_bound(fib,fib+m+1,r-l+1)-fib;
	if(k<=1) return 1;
//	for(auto x:a) cout<<x<<",";cout<<endl;
	int i;
	for(i=l;i<=r;i++) vis[a[i]]=1,fa[a[i]]=0;
	int mn=a[l];
	for(i=l;i<=r;i++)
		if(lft[a[i]]<lft[mn]) mn=a[i];
	dfs1(mn);
	int x=0;
	for(i=l;i<=r;i++){
		if(sz[a[i]]==fib[k-2]||sz[a[i]]==fib[k-1]){
			x=a[i];
			break;
		}
	}
	for(i=l;i<=r;i++) vis[a[i]]=0;
	if(!x) return 0;
	int tl=l-1,tr=r+1;
	for(i=l;i<=r;i++){
		if(lft[x]<=lft[a[i]]&&rgt[x]>=rgt[a[i]]) b[++tl]=a[i];
		else b[--tr]=a[i];
	}
	for(i=l;i<=r;i++) a[i]=b[i];
	if(judge(l,tl)&&judge(tr,r)) return 1;
	return 0;
}
int main(){
//	freopen("test.in","r",stdin);
	srand((unsigned)time(NULL));
	int i,j;
	cin>>n;
	if(n==1){
		cout<<"YES";
		return 0;
	}
	fib[0]=fib[1]=1;
	for(i=2;;i++){
		fib[i]=fib[i-1]+fib[i-2];
		if(fib[i]>n){
			cout<<"NO";
			return 0;
		}
		if(fib[i]==n){
			m=i;
			break;
		}
	}
	for(i=1;i<n;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs0(1);
	for(i=1;i<=n;i++) a[i]=i;
	cout<<(judge(1,n)?"YES":"NO");
	return 0;
}