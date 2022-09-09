#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define rep0(i,n) for ((i)=0;(i)<(n);(i)++)
using namespace std;
int a[333333];
map<int,int> c;
vector<int> v[333333],hv;
set<int> vis;
set<pair<int,int> > ban;
struct node{
	int a,b,x,y;
	long long val;
	bool flg;
};
bool operator <(const node &x,const node &y){
	return x.val<y.val;
}
priority_queue<node> pq;
void solve(){
	int n,i,j;
	c.clear();
	vis.clear();
	ban.clear();
	hv.clear();
	while(!pq.empty()) pq.pop();
	scanf("%d",&n);
	int m;
	scanf("%d",&m);
	rep(i,n) v[i].clear();
	rep(i,n) scanf("%d",a+i);
	rep(i,n) c[a[i]]++;
	rep(i,n){
		if(vis.count(a[i])) continue;
		vis.insert(a[i]);
		v[c[a[i]]].push_back(a[i]);
	}
	rep(i,n) if(!v[i].empty()){
		hv.push_back(i);
		sort(v[i].begin(),v[i].end(),greater<int>());
	}
	rep0(i,hv.size())for(j=i;j<hv.size();j++){
		pq.push((node){hv[i],hv[j],0,0,1ll*(hv[i]+hv[j])*(v[hv[i]][0]+v[hv[j]][0]),0});
	}
	while(m--){
		int a,b;
		scanf("%d%d",&a,&b);
		ban.insert(make_pair(a,b));
		ban.insert(make_pair(b,a));
	}
	while(!pq.empty()){
		node t=pq.top();
		pq.pop();
		int x=v[t.a][t.x];
		int y=v[t.b][t.y];
		if(x!=y&&!ban.count(make_pair(x,y))){
			printf("%lld\n",t.val);
			return;
		}
		if(t.x+1<v[t.a].size()&&!t.flg){
			pq.push((node){t.a,t.b,t.x+1,t.y,1ll*(t.a+t.b)*(v[t.a][t.x+1]+v[t.b][t.y]),0});
		}
		if(t.y+1<v[t.b].size()){
			pq.push((node){t.a,t.b,t.x,t.y+1,1ll*(t.a+t.b)*(v[t.a][t.x]+v[t.b][t.y+1]),1});
		}
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}