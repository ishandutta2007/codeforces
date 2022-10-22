#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,m,ans[100004];
pair<int,int>h[100004];
ll H[100004],X;
set<pair<ll,int> >st;
void sol(){
	cin>>n>>m>>X;
	st.clear();
	for(int i=1;i<=m;i++)st.insert(make_pair(0,i)),H[i]=0;
	for(int i=1;i<=n;i++)cin>>h[i].first,h[i].second=i;
	if(m==1){
		puts("YES");
		for(int i=1;i<=n;i++)cout<<"1 ";puts("");
		return;
	}
	sort(h+1,h+n+1);
	for(int i=n;i;i--){
		pair<ll,int> it=*st.begin();st.erase(it);
		int p=it.second;
		ans[h[i].second]=p; 
		H[p]+=h[i].first;
		st.insert(make_pair(H[p],p));
	}
	ll MINN=1e18,MAXN=0;
	for(int i=1;i<=m;i++)MINN=min(MINN,H[i]),MAXN=max(MAXN,H[i]);
	if(MAXN-MINN>X)puts("NO");
	else{
		puts("YES");
		for(int i=1;i<=n;i++)cout<<ans[i]<<" ";puts("");
	}
}
int main(){
	cin>>t;
	while(t--)sol();
}