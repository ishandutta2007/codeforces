#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
int T,n;
int a[200005],b[200005],m[200005];
vector<pii>all;
vector<int>v;
int L[200005],R[200005];
int res[200005];
int got(){
	set<pii>sl,sr;
	for(auto x:v){
		int A,B;
		if(a[x]<=m[x])A=0;
		else A=a[x]-m[x];
		if(b[x]<=m[x])B=a[x]-(m[x]-b[x]);
		else B=a[x];
		L[x]=A,R[x]=B;
		sl.insert({A,x}),sr.insert({B,x});
	}
	int ans=0;
	while(!sr.empty()){
		ans++;
		pii z=*sr.begin();
		int Rd=z.fi;
		while(!sl.empty()){
			auto it=sl.begin();
			if((*it).fi<=Rd){
				int id=(*it).se;
				res[id]=Rd;
				sl.erase({L[id],id});
				sr.erase({R[id],id});
			}else break;
		}
	}
	return ans;
}
void sol(){
	all.clear();
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i],&b[i],&m[i]);
		all.push_back({a[i]+b[i]-m[i],i});
	}
	sort(all.begin(),all.end());
	int ans=0;
	for(int i=0,j;i<n;i=j){
		v.clear();
		for(j=i;j<n&&all[j].fi==all[i].fi;j++)v.push_back(all[j].se);
		ans+=got();
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)printf("%d %d\n",a[i]-res[i],m[i]-(a[i]-res[i]));
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}