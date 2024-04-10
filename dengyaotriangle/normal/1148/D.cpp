#include<bits/stdc++.h>
using namespace std;

const int maxn=300005;

int n;
pair<int,int> p[maxn];
vector<pair<int,pair<int,int> > > vl,vr,cl;

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i].first>>p[i].second;
	for(int i=1;i<=n;i++){
		if(p[i].first<p[i].second)vl.push_back(make_pair(i,p[i]));
		if(p[i].first>p[i].second)vr.push_back(make_pair(i,p[i]));
	}
	sort(vl.begin(),vl.end(),[](pair<int,pair<int,int> > a,pair<int,pair<int,int> > b){return a.second.second>b.second.second;});
	sort(vr.begin(),vr.end(),[](pair<int,pair<int,int> > a,pair<int,pair<int,int> > b){return a.second.second<b.second.second;});
	if(vl.size()>vr.size())cl=vl;
	else cl=vr;
	cout<<cl.size()<<'\n';
	for(int i=0;i<cl.size();i++) cout<<cl[i].first<<' ';
    return 0;
}