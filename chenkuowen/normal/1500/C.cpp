#include<bits/stdc++.h>
using namespace std;
typedef bitset<1505> B;
map<vector<int>,vector<int> > mp;
int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<vector<int> > a(n),b(n);
	vector<pair<B,B> > s(m);
	vector<int> id(n);
	
	for(int i=0;i<n;++i){
		a[i].resize(m);
		for(int j=0;j<m;++j)
			scanf("%d",&a[i][j]);
		mp[a[i]].push_back(i);
	}
	for(int i=0;i<n;++i){
		b[i].resize(m);
		for(int j=0;j<m;++j) scanf("%d",&b[i][j]);
	}
	for(int i=n-1;i>=0;--i){
		if(mp[b[i]].empty()){
			puts("-1");
			exit(0);
		}
		id[i]=mp[b[i]].back(); mp[b[i]].pop_back();
	}
//	for(int i=0;i<n;++i) printf("(%d)",id[i]);  puts("");
	B g;
	for(int i=0;i+1<n;++i) g[i]=id[i]<id[i+1];
//	printf("[%d]",int(g[0]));
	for(int j=0;j<m;++j){
		for(int i=0;i+1<n;++i){
			if(a[id[i]][j]==a[id[i+1]][j]) s[j].second[i]=0;
			else if(a[id[i]][j]<a[id[i+1]][j]) s[j].second[i]=1;
			else s[j].first[i]=1;
		}
	//	printf("[%d %d]",int(s[j].first[0]),int(s[j].second[0]));
	}
	vector<int> ans;
	B now; 
	int last_count=0;
	while(1){
		for(int j=0;j<m;++j){
			if(((now&s[j].first)==s[j].first)&&((now|s[j].second)^now).any()){
				now|=s[j].second;
				ans.push_back(j);
			}
		}
		if(now.count()==last_count) break;
		last_count=now.count();
	}
	if((now|g).count()!=n-1){
		puts("-1");
		exit(0);
	}
	reverse(ans.begin(),ans.end());
	printf("%d\n",int(ans.size()));
	for(auto x:ans) printf("%d ",x+1);
	return 0;
}