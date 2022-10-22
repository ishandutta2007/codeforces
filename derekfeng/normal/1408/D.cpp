#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mkp make_pair
int n,m,d[2004];
pii a[2004],b[2004];
vector<int>A;
vector<pair<int,pii> >v;
int cur[2003];
multiset<int>mst;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].fi,&a[i].se);
	for(int i=1;i<=m;i++)scanf("%d%d",&b[i].fi,&b[i].se);
	sort(b+1,b+1+m);
	for(int j=1;j<=m;j++)d[j]=max(d[j+1],b[j].se);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)if(a[i].fi<=b[j].fi)
			v.push_back(mkp(b[j].fi-a[i].fi,mkp(i,max((int)0,d[j]-a[i].se+1)))); 
	}
	int ans=1e9,ret=0;
	sort(v.begin(),v.end());
//	for(int i=0;i<v.size();i++)cout<<v[i].fi<<" "<<v[i].se.fi<<" "<<v[i].se.se<<"\n";
	int now=v.size();
	for(int i=1;i<=n;i++)mst.insert(0);
	for(int i=1e6+1;i>=0;i--){
		while(now>0&&v[now-1].fi==i){
			mst.erase(mst.find(cur[v[now-1].se.fi])); 
			cur[v[now-1].se.fi]=v[now-1].se.se;
			mst.insert(v[now-1].se.se); 
			now--;
		}
		ans=min(ans,(*mst.rbegin())+i);
	}
	printf("%d",ans);
}