#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mkp make_pair
#define fi first
#define se second
typedef pair<pii,int> piii;
int n,p,k;
piii d[100004];
bool cmp(piii a1,piii a2){
	if(a1.fi.se!=a2.fi.se)return a1.fi.se<a2.fi.se;
	return a1.fi.fi>a2.fi.fi;
}
ll s[100004];
map<piii,bool>mp;
set<piii>st;
int main(){
	scanf("%d%d%d",&n,&p,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&d[i].fi.fi,&d[i].fi.se);
		d[i].se=i;
	}
	sort(d+1,d+1+n,cmp);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+d[i].fi.se;
		piii e=d[i];e.se=i,e.fi.fi*=-1;
		if(i>p-k)st.insert(e);
	}
	ll ans1=s[p-k],ans2=0;
	int pos=p-k;
	for(int i=1;i<=k;i++){
		piii pr=(*st.begin());st.erase(st.begin());
		ans2+=(-pr.fi.fi);
		mp[pr]=1;
	}
	ll ret1,ret2=ans2;
	for(int i=p-k+1,j=1;i+k<=n;i++,j++){
		ret1=s[i]-s[j];
		piii e=d[i];e.se=i,e.fi.fi*=-1;
		if(mp[e]){
			mp[e]=0,ret2-=d[i].fi.fi;
			piii pr=(*st.begin());st.erase(st.begin());
			ret2+=(-pr.fi.fi);
			mp[pr]=1;
		}else st.erase(st.find(e));
		if(ans2<ret2||(ans2==ret2&&ans1<ret1))ans1=ret1,ans2=ret2,pos=i;
	}
	mp.clear();st.clear();
	for(int i=1;i<=n;i++){
		piii e=d[i];e.se=i,e.fi.fi*=-1;
		if(i>p-k)st.insert(e);
	}
	for(int i=1;i<=k;i++){
		piii pr=(*st.begin());st.erase(st.begin());
		ans2+=(-pr.fi.fi);
		mp[pr]=1;
	}
	if(pos==p-k){
		vector<int>res;
		for(int i=1;i<=pos;i++)res.push_back(d[i].se);
		for(map<piii,bool>::iterator it=mp.begin();it!=mp.end();it++)if(it->second==1)res.push_back(d[it->first.se].se);
		sort(res.begin(),res.end());
		for(int i=0;i<p;i++)printf("%d ",res[i]);
		return 0;
	}
	for(int i=p-k+1,j=1;i+k<=n;i++,j++){
		piii e=d[i];e.se=i,e.fi.fi*=-1;
		if(mp[e]){
			mp[e]=0,ret2-=d[i].fi.fi;
			piii pr=(*st.begin());st.erase(st.begin());
			ret2+=(-pr.fi.fi);
			mp[pr]=1;
		}else st.erase(st.find(e));
		if(pos==i){
			vector<int>res;
			for(int l=j+1;l<=i;l++)res.push_back(d[l].se);
			for(map<piii,bool>::iterator it=mp.begin();it!=mp.end();it++)if(it->second==1)res.push_back(d[it->first.se].se);
			sort(res.begin(),res.end());
			for(int i=0;i<p;i++)printf("%d ",res[i]);
			return 0;
		}
	}
}