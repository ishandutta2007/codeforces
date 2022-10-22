#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
int T,n,m,a[100005],ans[100005];
set<pii>st;
void upd(int k,int d){
	if(d==0)return;
	a[k]-=d;auto it=--st.lower_bound({k,n+n});
	auto [l,r]=*it;if(l!=k&&a[l]<=a[k])return;
	st.erase(it);if(l!=k)st.insert({l,k-1});
	int R=r;
	for(;;){
		it=st.lower_bound({k,0});
		if(it==st.end())break;
		auto [l,r]=*it;
		if(a[l]<a[k])break;
		st.erase(it),R=r;
	}
	st.insert({k,R});
}
void sol(){
	scanf("%d%d",&n,&m);st.clear();
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1,j;i<=n;i=j){
		for(j=i+1;j<=n&&a[j]>=a[i];j++);
		st.insert({i,j-1});
	}
	for(int i=0;i<m;i++){
		int k,d;scanf("%d%d",&k,&d);
		upd(k,d),ans[i]=st.size();
	}
	for(int i=0;i<m;i++)printf("%d ",ans[i]);puts("");
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}