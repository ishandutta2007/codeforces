#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; 
#define mkp make_pair
#define fi first
#define se second
int n,a[200004],b[200004];
ll ans;
int MX;
vector<pii>v1,v2;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		if(a[i]<=b[i])v1.push_back(mkp(a[i],b[i]));
		else v2.push_back(mkp(b[i],a[i]));
		ans+=abs(a[i]-b[i]);
	}
	sort(v1.begin(),v1.end()),sort(v2.begin(),v2.end());
	int j=0,now=0;
	for(auto x:v1){
		while(j<v2.size()&&v2[j].fi<=x.fi)now=max(now,v2[j].se),j++;
		int R=min(now,x.se);
		MX=max(MX,R-x.fi);
	}
	j=now=0;
	for(auto x:v2){
		while(j<v1.size()&&v1[j].fi<=x.fi)now=max(now,v1[j].se),j++;
		int R=min(now,x.se);
		MX=max(MX,R-x.fi);
	}
	printf("%lld",ans-MX*2);
}