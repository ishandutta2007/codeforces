#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
vector<pii>f,ga,gb;
int n,m,k,bt1[200005],bt2[200005];
vector<pii>all;
int ba[200005],bb[200005];
int res=2e9+5,ans1,ans2,ans3;
void upd(int i,int x,int y){
	for(;i<=n;i+=i&-i)bt1[i]+=x,bt2[i]+=y;
}
int bs(int w){
	int ans=0;
	int cur=0;
	for(int i=20;~i;i--){
		int tmp=cur+(1<<i);
		if(tmp>n)continue;
		if(w<bt1[tmp])continue;
		w-=bt1[tmp],ans+=bt2[tmp],cur=tmp;
	}
	return ans;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	all.push_back({0,0});
	for(int i=1;i<=n;i++){
		int t;scanf("%d%d%d",&t,&ba[i],&bb[i]);
		all.push_back({t,i});
	}
	sort(all.begin(),all.end());
	for(int i=1;i<=n;i++){
		upd(i,1,all[i].fi);
		int f0=ba[all[i].se],f1=bb[all[i].se];
		if(f0>0&&f1>0)f.push_back({all[i].fi,i});
		else if(f0>0)ga.push_back({all[i].fi,i});
		else if(f1>0)gb.push_back({all[i].fi,i});
	}
	int cur=0;
	int s0=0,s1=0;
	while(s0<k&&s0<ga.size()){
		upd(ga[s0].se,-1,-ga[s0].fi);
		cur+=ga[s0].fi;
		s0++;
	}
	while(s1<k&&s1<gb.size()){
		upd(gb[s1].se,-1,-gb[s1].fi);
		cur+=gb[s1].fi;
		s1++;
	}
	for(int i=0;i<=min((int)f.size(),k);i++){
		if(i>0){
			cur+=f[i-1].fi;
			upd(f[i-1].se,-1,-f[i-1].fi);
			while(i+s0>k){
				s0--;
				upd(ga[s0].se,1,ga[s0].fi);
				cur-=ga[s0].fi;
			}
			while(i+s1>k){
				s1--;
				upd(gb[s1].se,1,gb[s1].fi);
				cur-=gb[s1].fi;
			}
		}
		if(i+s0==k&&i+s1==k&&i+s0+s1<=m){
			int tmp=cur+bs(m-i-s0-s1);
			if(tmp<res)res=tmp,ans1=i,ans2=s0,ans3=s1;
		}
	}
	if(res>2e9)return puts("-1"),0;
	printf("%d\n",res);
	set<pii>s;
	vector<int>ans;
	for(int i=1;i<=n;i++)s.insert({all[i].fi,i});
	m-=ans1+ans2+ans3;
	while(ans1>0)ans1--,ans.push_back(all[f[ans1].se].se),s.erase(f[ans1]);
	while(ans2>0)ans2--,ans.push_back(all[ga[ans2].se].se),s.erase(ga[ans2]);
	while(ans3>0)ans3--,ans.push_back(all[gb[ans3].se].se),s.erase(gb[ans3]);
	while(m){
		m--;
		ans.push_back(all[(*s.begin()).se].se);
		s.erase(s.begin());
	}
	sort(ans.begin(),ans.end());
	for(auto x:ans)printf("%d ",x);
}