#include<cstdio>
#include<utility>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
using namespace std;
const int o=2e5+10;
int T,n,m,a[o],l1[o],r1[o],l2[o],r2[o],cnt,ans,mx,mn;pair<int,int> p[o];set<int> S[o];map<int,int> mp;vector<int> vec[o];
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",ans),mp.clear(),cnt=0){
		scanf("%d%d",&n,&m);ans=mn=o;
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			if(!mp[a[i]]) mp[a[i]]=++cnt;
			a[i]=mp[a[i]];
		}
		for(int i=1;i<=cnt;++i) S[i].clear();
		for(int i=1;i<=m;++i) scanf("%d%d",&p[i].first,&p[i].second);
		sort(p+1,p+m+1);cnt=mx=0;
		for(int r=p[1].first-1;r<p[1].second;){
			++r;S[a[r]].insert(r);
			if(S[a[r]].size()>1) l1[++cnt]=*S[a[r]].begin(),l2[cnt]=*++S[a[r]].begin(),r2[cnt]=*--S[a[r]].end(),r1[cnt]=*----S[a[r]].end();
		}
		for(int i=2,l=p[1].first,r=p[1].second;i<=m;++i){
			for(;l<p[i].first;++l) S[a[l]].erase(l);
			for(;r<p[i].second;){
				++r;S[a[r]].insert(r);
				if(S[a[r]].size()>1) l1[++cnt]=*S[a[r]].begin(),l2[cnt]=*++S[a[r]].begin(),r2[cnt]=*--S[a[r]].end(),r1[cnt]=*----S[a[r]].end();
			}
		}
		if(!cnt){ans=0;continue;}
		for(int i=1;i<=cnt;++i) mx=max(mx,r1[i]),mn=min(mn,l2[i]);
		for(int i=1;i<=n;++i) vec[i].clear();
		for(int i=1;i<=cnt;++i) vec[l1[i]].push_back(i);
		for(int i=1;i<=mn;ans=min(ans,mx-i+1),++i) for(int j=vec[i-1].size();j--;) mx=max(mx,r2[vec[i-1][j]]);
	}
	return 0;
}