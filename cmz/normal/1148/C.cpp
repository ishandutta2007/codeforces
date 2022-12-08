#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;
long long n,k;
long long a[maxn];
long long id[maxn];
long long vis[maxn];
vector<int> v;
void dfs(int x){
	vis[x]=1; v.push_back(x);
	if (!vis[id[x]]){
		dfs(id[x]);
	}
	return;
}
vector <pair<int,int> > ans;
void solve(int x,int y){
	if (x>y) swap(x,y);
	if (n<=2*abs(x-y)){
		ans.push_back(make_pair(x,y));
		return;
	}
	if (n<=2*(x-1)){
		ans.push_back(make_pair(1,x));
		ans.push_back(make_pair(1,y));
		ans.push_back(make_pair(1,x));
	} else 
	if (n<=2*(n-y)){
		ans.push_back(make_pair(y,n));
		ans.push_back(make_pair(x,n));
		ans.push_back(make_pair(y,n));
	} else{
		ans.push_back(make_pair(1,y));
		ans.push_back(make_pair(1,n));
		ans.push_back(make_pair(x,n));
		ans.push_back(make_pair(1,n));
		ans.push_back(make_pair(1,y));
	}
}
int main(){
	scanf("%d",&n);
	int x;
	for (int i=1;i<=n;++i){
		scanf("%d",&x);
		id[x]=i;
	}
	int l=1,r=1+n;
	for (int i=1;i<=n;++i){
		if (!vis[i]){
			v.clear();
			dfs(i);
			if (v.size()==1) continue;
			else {
				for (int j=0;j<v.size()-1;++j) solve(v[j],v[j+1]);
			}
		}
	}
	printf("%d\n",ans.size());
	for (int i=0;i<ans.size();++i)
	printf("%d %d\n",ans[i].first,ans[i].second);
}