#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int a[200010];
bool was[200010];
vector<int> v;
vector<int> vv;
int l;
set<int> ss,s;
void dfs(int x){
	if(mp[x]==x){
		was[x]=true;
		if(ss.find(x)==ss.end()){
			v.push_back(x);
			ss.insert(x);
		}
		return ;
	}
	if(s.find(mp[x])!=s.end()){
		v.push_back(x);
		was[mp[x]]=true;
		was[x]=true;
		l=x;
		return ;
	}
	if(was[x]){
		return ;
	}
	was[x]=true;
	s.insert(x);
	dfs(mp[x]);
	s.erase(x);
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[i]=a[i];
	}
	set<int> t;
	vector<int> vv;
	for(int i=1;i<=n;i++){
		if(!was[i]){
			l=-1;
			dfs(i);
			if(l!=-1)vv.push_back(l);
		}
	}
	int res=0;
	int cnt=0;
	int r=-1;
	for(int i=1;i<=n;i++){
		if(i==a[i]&&v.size()-res>1){
			r=a[i];
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(i==a[i]&&v.size()-res>1){
			if(i!=r){
				a[i]=r;
				t.insert(i);
			}
		}
	}
	if(r==-1){
		r=v[0];
		a[r]=r;
	}
	for(int i=0;i<vv.size();i++){
		a[vv[i]]=r;
		t.insert(vv[i]);
	}
	cout<<t.size()<<endl;
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	puts("");
	return 0;
}