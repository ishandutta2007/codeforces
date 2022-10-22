#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > a;
vector<int> c,diff;
void change(int x,int k){
	for(int i=0;i<a.size();++i)
		diff[i]+=int(k!=a[i][x])-int(c[x]!=a[i][x]);
	c[x]=k;
}
void check(){
	for(int i=0;i<a.size();++i)
		if(diff[i]>2) return;
	puts("Yes");
	for(auto x:c) printf("%d ",x);
	exit(0);
}
void merge(set<vector<pair<int,int> > >& s,vector<pair<int,int> > a,vector<pair<int,int> > b){
//	for(auto x:a) printf("[%d %d]",x.first,x.second); puts("");
//	for(auto x:b) printf("[%d %d]",x.first,x.second); puts("");
	map<int,int> mp;
	for(auto x:a) mp[x.first]=x.second;
	for(auto x:b){
		if(mp[x.first]==-1){
			if(x.second==-1){
				mp[x.first]=-2;
			}else mp[x.first]=x.second;
		}else{
			if(x.second!=-1&&mp[x.first]!=x.second) return;
		}
	}
	vector<pair<int,int> > d;
	int cnt=0;
	for(auto x:mp){
		if(x.second>0){
			d.push_back(x);
			++cnt;
		}else if(x.second==-2){
			d.push_back(make_pair(x.first,-1));
		}
	}
//	for(auto x:d) printf("<%d %d>",x.first,x.second); puts("");
	if(cnt<=2) s.insert(d);
}
int main(){
	int n,m; scanf("%d%d",&n,&m);
	a.resize(n,vector<int>(m)); c.resize(m); diff.resize(n);
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			scanf("%d",&a[i][j]);
	c=a[0];
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j)
			diff[i]+=int(a[i][j]!=c[j]);
		if(diff[i]>4){
			puts("No");
			return 0;
		}
	}
	check();
	set<vector<pair<int,int> > > s1;
	vector<pair<int,int> > k;
	for(int i=0;i<m;++i) k.push_back(make_pair(i,-1));
	s1.insert(k);
	int cnt=0;
	for(int i=0;i<n;++i){
		vector<int> g;
		for(int j=0;j<m;++j)
			if(a[i][j]!=a[0][j])
				g.push_back(j);
		if(g.size()<=2) continue;
		++cnt;
		set<vector<pair<int,int> > > s2;
		for(int sta=0;sta<1<<g.size();++sta){
			int popcnt=__builtin_popcount(sta);
			if(g.size()-popcnt==2){
				vector<pair<int,int> > g1;
				for(int j=0;j<g.size();++j){
					if((sta>>j)&1) g1.push_back(make_pair(g[j],a[i][g[j]]));
					else g1.push_back(make_pair(g[j],-1));
				}
				for(auto x:s1) merge(s2,x,g1);
			}
		}
		s1=s2;
/*		for(auto x:s1){
			for(auto y:x) printf("[%d %d]",y.first,y.second); puts("");
		}
		puts("----------------");
*/	}
	for(auto d:s1){
		for(auto x:d){
			if(x.second!=-1)
				change(x.first,x.second);
		}
		check();
		for(auto x:d){
			if(x.second!=-1)
				change(x.first,a[0][x.first]);
		}
	}
	puts("No");
	return 0;
}