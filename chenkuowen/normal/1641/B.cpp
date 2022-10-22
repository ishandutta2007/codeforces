#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > op;
vector<int> ans;
void insert(vector<int>& a,int p,int v){
	vector<int> b(a.begin(),a.begin()+p);
	for(int i=0;i<2;++i) b.push_back(v);
	for(int i=p;i<a.size();++i) b.push_back(a[i]);
	swap(a,b); op.push_back({p,v});
}
void solve(vector<int> a){
	op.clear(); ans.clear();
	int start_pos=0;
	while(!a.empty()){
		int y=1;
		for(;y<a.size();++y)
			if(a[y]==a[0]) break;
		if(y==a.size()){
			puts("-1");
			return;
		}
		ans.push_back(y+y);
		vector<int> b;
		for(int i=1;i<y;++i){
			op.push_back({start_pos+y+i,a[i]});
			b.push_back(a[y-i]);
		}
		for(int i=y+1;i<a.size();++i)
			b.push_back(a[i]);
		swap(a,b);
		start_pos+=y+y;
	}
/*
	for(int x=0;x<a.size();++x){
		int y=x+1;
		for(;y<a.size();++y)
			if(a[y]==a[x]) break;
		if(y==a.size()) {
			puts("-1");
			return;
		}
		ans.push_back(y-x);
		vector<int> b(a.size()+y-x-1);

		for(int i=1;i<y-x;++i){
			
			insert(a,y+i,a[i+x]);
		}
	}
*/	printf("%d\n",int(op.size()));
	for(auto x:op) printf("%d %d\n",x.first,x.second);
	printf("%d\n",int(ans.size()));
	for(auto x:ans) printf("%d\n",x);
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		vector<int> a(n);
		for(int i=0;i<n;++i) scanf("%d",&a[i]);
		solve(a);
	}
	return 0;
}