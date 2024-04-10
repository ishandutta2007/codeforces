#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int add(int a,int b){
	a=(a+b)%mod;
	return a;
}
int main(){
	int n,m,st,en;
	scanf("%d%d",&n,&m);
	vector<pair<int,int> >evs;
	vector<int>pts;
	for(int i=0;i<m;i++){
		cin>>st>>en;
		evs.push_back(make_pair(en,(en+1)));
		evs.push_back(make_pair(st,-(en+1)));
		pts.push_back(st);
		pts.push_back(en);
	}
	sort(evs.begin(),evs.end());
	sort(pts.begin(),pts.end());
	pts.resize(unique(pts.begin(),pts.end())-pts.begin());
	vector<int>cnt;
	for(int i=0;i<pts.size();i++)cnt.push_back(0);
	int nt=0,ans=0,p=evs.size()-1;
	for(int i=pts.size()-1;i>=0;i--){
		if(pts[i]==n)cnt[i]++;
		cnt[i]=add(cnt[i],nt);
		if(pts[i]==0)ans=add(ans,cnt[i]);
		while(p>=0&&evs[p].first==pts[i]){
			int x=lower_bound(pts.begin(),pts.end(),abs(evs[p].second)-1)-pts.begin();
			assert(x>=i);
			if(evs[p].second>0)nt=add(nt,cnt[x]);else nt=add(nt,mod-cnt[x]);
    		p--;
		}
	}
	cout<<ans; 
}