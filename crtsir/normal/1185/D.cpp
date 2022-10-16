#include<bits/stdc++.h>
using namespace std;
int n;
pair<int,int>a[200030];
map<int,int>mp;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i].first,a[i].second=i;
	sort(a,a+n);
	if(n<4){
		cout<<1;
		return 0;
	} 
	bool flag=1;
	for(int i=2;i<n-1;i++)
		if(a[i].first-a[i-1].first!=a[i+1].first-a[i].first)
			flag=0;
	if(flag){
		cout<<a[0].second+1;
		return 0;
	}
	flag=1;
	for(int i=1;i<n-2;i++)
		if(a[i].first-a[i-1].first!=a[i+1].first-a[i].first)
			flag=0;
	if(flag){
		cout<<a[n-1].second+1;
		return 0;
	}
	vector<int>V;
	for(int i=1;i<n;i++)mp[a[i].first-a[i-1].first]++,V.push_back(a[i].first-a[i-1].first);
	sort(V.begin(),V.end());
	V.erase(unique(V.begin(),V.end()),V.end()); 
	if(mp.size()>3){cout<<-1;return 0;}
	if(mp.size()==3)
		if(mp[V[0]]==1&&mp[V[1]]==1&&V[0]+V[1]==V[2]);
		else{cout<<-1;return 0;}
	if(mp.size()==2)
		if(mp[V[0]]==2&&V[0]*2==V[1]);
		else
			if(V[0]==0&&mp[V[0]]==1);
			else{cout<<-1;return 0;}
	for(int i=2;i<n;i++)
		if(a[i].first-a[i-2].first==V[V.size()-1]){
			cout<<a[i-1].second+1;
			return 0;
		}
	cout<<-1;
}