#include<bits/stdc++.h>
using namespace std;
const int MAX_N=2005;
void fail(){ puts("-1"); exit(0); }
list<int> a[MAX_N];
int n,deg[MAX_N];
vector<vector<int> > ans;
vector<pair<int,int> > s,s1;
multiset<pair<int,int> > q;
void link1(int x,int y){
//	if(deg[x]+deg[y]<2) fail();
	ans.push_back(vector<int>({a[x].back(),a[y].back()}));
	a[x].pop_back(); a[y].pop_back();
	a[x].splice(a[x].end(),a[y]);
	deg[x]+=deg[y]-2;
}
int link2(vector<int> x){
//	if(x.size()<3) fail();
	vector<int> y; y.resize(x.size());
	for(int i=0;i<x.size();++i){
		if(deg[x[i]]<2) fail();
		y[i]=a[x[i]].back();
		a[x[i]].pop_back(); 
		a[x[i]].pop_back();
	}
	y.push_back(y[0]);
	ans.push_back(y);
	deg[x[0]]-=2;
	for(int i=1;i<x.size();++i){
		a[x[0]].splice(a[x[0]].end(),a[x[i]]);
		deg[x[0]]+=deg[x[i]]-2;
	}
	return x[0];
}
namespace TREE{
	priority_queue<pair<int,int> > q;
	void dfs(int x){
		while(deg[x]>0){
			if(q.empty()) fail();
			int y=q.top().second; q.pop();
			deg[x]--; deg[y]--; 
			ans.push_back(vector<int>({x,y}));
			dfs(y);
		}
	}
	void solve(){
		for(int i=1;i<=n;++i) q.push(make_pair(deg[i],i));
		int x=q.top().second; q.pop();
		dfs(x);
		for(int i=1;i<=n;++i)
			if(deg[i]>0) fail();
		printf("%d\n",(int)ans.size());
		for(auto x:ans){
			printf("%d ",(int)x.size());
			for(auto y:x)
				printf("%d ",y);
			puts("");
		}
		exit(0);
	}
}
void check(int* deg,int n){
	vector<int> s;
	int sum=0,cnt1=0,cnt2=0;
	for(int i=1;i<=n;++i){
		sum+=deg[i];
		if(deg[i]&1){
			if(deg[i]==1) ++cnt1;
			else ++cnt2;
		}
	}
	if(sum%2==1) fail();
	sum/=2;
	if(sum==n-1) return;
	if(cnt1>cnt2){
		sum-=cnt1;
		n-=cnt1;
	}else{
		sum-=(cnt1+cnt2)/2;
		n-=(cnt1+cnt2)/2;
	}
	if(sum<n) fail();
	if(n&1){
		if(sum>3*(n-1)/2) fail();
	}else{
		if(sum>3*n/2-2) fail();
	}
}
int main(){
	scanf("%d",&n); int sum=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&deg[i]); sum+=deg[i];
	}
	check(deg,n);
	for(int i=1;i<=n;++i){
		for(int j=0;j<deg[i];++j) a[i].push_back(i);
		if(deg[i]&1) s.push_back(make_pair(deg[i],i));
		else q.insert(make_pair(deg[i],i));
	}
	if(sum==2*n-2) TREE::solve();
	sort(s.begin(),s.end());
	for(int i=0;i<s.size()/2;++i){
		int x=s[i].second,y=s[s.size()-i-1].second;
		if(deg[x]+deg[y]>2){
			link1(x,y); 
			q.insert(make_pair(deg[x],x));
		}else{
			s1.push_back(make_pair(deg[x],x));
			s1.push_back(make_pair(deg[y],y));
		}
	}
	for(int i=0;i<s1.size();i+=2){
		auto it=prev(q.end());
		int x=it->second; q.erase(it);
		link1(x,s1[i].second); link1(x,s1[i+1].second);
		q.insert(make_pair(deg[x],x));
	}
	while(!q.empty()){
		auto it=prev(q.end());
		int x=it->second;
		if(deg[x]==2){
			vector<int> s;
			for(auto y:q)
				s.push_back(y.second);
			link2(s);
			break;
		}else{
			int x=q.begin()->second; q.erase(q.begin());
			int y=q.begin()->second; q.erase(q.begin());
			int z=prev(q.end())->second; q.erase(prev(q.end()));
			int t=link2(vector<int>({x,y,z}));
			q.insert(make_pair(deg[t],t));
		}
	}
	printf("%d\n",(int)ans.size());
	for(auto x:ans){
		printf("%d ",(int)x.size());
		for(auto y:x) printf("%d ",y);
		puts("");
	}
	return 0;
}