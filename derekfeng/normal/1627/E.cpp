#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
int t,n,m,k;
int x[100004],a[100004],b[100004],c[100004],d[100004],h[100004];
vector<pair<int,pii> >v[100004];
bool cmp1(pair<int,pii>A,pair<int,pii>B){
	if(A.fi!=B.fi)return A.fi<B.fi;
	return A.se.fi<B.se.fi;
}
bool cmp2(pair<int,pii>A,pair<int,pii>B){
	if(A.fi!=B.fi)return A.fi>B.fi;
	return A.se.fi<B.se.fi;
}
ll dp[100004];
void sol(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%d",&x[i]),v[i].clear();
	for(int i=1;i<=k;i++){
		scanf("%d%d%d%d%d",&a[i],&b[i],&c[i],&d[i],&h[i]);
		v[a[i]].push_back({b[i],{1,i}});
		v[c[i]].push_back({d[i],{0,i}});
		dp[i]=-1e18;
	}
	dp[k+1]=-1e18,h[k+1]=0;
	v[1].push_back({1,{0,0}});
	v[n].push_back({m,{1,k+1}});
	for(int i=1;i<=n;i++)if(!v[i].empty()){
		sort(v[i].begin(),v[i].end(),cmp1);
		ll f=-1e18;
		int lst=0;
		for(auto w:v[i]){
			f-=(ll)(w.fi-lst)*x[i],lst=w.fi;
			if(w.se.fi==0)f=max(f,dp[w.se.se]);
			else dp[w.se.se]=f+h[w.se.se];
		}
		sort(v[i].begin(),v[i].end(),cmp2);
		f=-1e18;
		lst=m+1;
		for(auto w:v[i]){
			f-=(ll)(lst-w.fi)*x[i],lst=w.fi;
			if(w.se.fi==0)f=max(f,dp[w.se.se]);
			else dp[w.se.se]=max(dp[w.se.se],f+h[w.se.se]);
		}
	}
	if(dp[k+1]<-1e17)puts("NO ESCAPE");
	else printf("%lld\n",-dp[k+1]);
}
int main(){
	scanf("%d",&t);
	while(t--)sol();
}