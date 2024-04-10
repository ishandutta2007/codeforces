#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int T,n,m,a[200004];
vector<int>g[200004];
ll s[200004];
set<int>st;
queue<pii>que;
void lv(int x){
	s[x]=0;
	for(auto y:g[x])if(s[y]==0)
		que.push({x,y});
}
void calc(int l,int r){
	for(;;){
		auto it=st.lower_bound(l);
		if(it==st.end()||(*it)>r)break;
		lv(*it);st.erase(it);
	}
}
void sol(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1,x;i<=n;i++)scanf("%d",&x),a[i]-=x,s[i]=s[i-1]+a[i];
	st.clear();for(int i=1;i<=n;i++)if(s[i]!=0)st.insert(i);
	for(int i=1;i<=m;i++){
		int l,r;scanf("%d%d",&l,&r);
		g[l-1].push_back(r),g[r].push_back(l-1);
	}
	for(int i=1;i<=n;i++)if(s[i]==0)
		for(auto x:g[i])if(s[x]==0)que.push({x,i});
	while(!que.empty()){
		auto [u,v]=que.front();que.pop();
		if(u>v)swap(u,v);calc(u,v);
	}
	puts(st.size()?"NO":"YES");
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}