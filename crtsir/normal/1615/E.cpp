#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int>v[200003];
multiset<int>s[200003];
int sz[200003],bg[200003];
void dfs(int x,int p){
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=p)
			dfs(v[x][i],x);
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=p)
			if(bg[v[x][i]]!=bg[x]){
				while(s[bg[v[x][i]]].size()){
					s[bg[x]].insert(*s[bg[v[x][i]]].begin());
					s[bg[v[x][i]]].erase(s[bg[v[x][i]]].begin());
				}
			}
	if(bg[x]==x)s[bg[x]].insert(0);
	int qaq=(*s[bg[x]].begin());
	s[bg[x]].erase(s[bg[x]].begin());
	s[bg[x]].insert(qaq-1);
}
void init(int x,int p){
	bg[x]=-1;
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=p){
			init(v[x][i],x),
			sz[x]+=sz[v[x][i]];
			if(bg[x]==-1||sz[bg[x]]<sz[v[x][i]])
				bg[x]=v[x][i];
		}
	if(bg[x]==-1)
		bg[x]=x,sz[x]=1;
}
void qaq(int x,int p){
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=p)
			qaq(v[x][i],x);
	bg[x]=bg[bg[x]];
}
int ans[200003];
int main(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		x--;y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	init(0,-1);
	qaq(0,-1);
	dfs(0,-1);
	int N=0;
	while(s[bg[0]].size()){
		ans[++N]=-(*s[bg[0]].begin());
		s[bg[0]].erase(s[bg[0]].begin());
	}
	for(int i=1;i<=n;i++)
		ans[i]+=ans[i-1];
	long long res=-11415141919801;
	for(int i=0;i<=k;i++){
		int b=min(n-ans[i],n/2);
//		cout<<n-i-b<<' '<<i<<' '<<b<<endl;
		res=max(res,1ll*(n-i-b)*(i-b));
	}cout<<res;
}