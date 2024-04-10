#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+1e6;
struct SEG{
	int t[MAX_N<<2];
	void build(int p,int l,int r){
		t[p]=2e9;
		if(l==r) return;
		int m=l+r>>1;
		build(p+p,l,m);
		build(p+p+1,m+1,r);
	}
	void change(int p,int l,int r,int x,int y,int tag){
		if(l==x&&r==y){
			t[p]=min(t[p],tag);
			return;
		}
		int m=l+r>>1;
		if(y<=m) change(p+p,l,m,x,y,tag);
		else if(x>m) change(p+p+1,m+1,r,x,y,tag);
		else change(p+p,l,m,x,m,tag),change(p+p+1,m+1,r,m+1,y,tag);
	}
	void dfs(int p,int l,int r,int key,vector<int>& g){
		key=min(key,t[p]);
		if(l==r) return void(g[l]=key);
		int m=l+r>>1; 
		dfs(p+p,l,m,key,g);
		dfs(p+p+1,m+1,r,key,g);
	}
}seg;
vector<int> a;
set<int> s;
int ans=0;
inline int get_key(int x,int std){ return x>std; }
bool check(set<int>::iterator it0,set<int>::iterator it1,int std){
	int pos0=(*it0),pos1=(*it1);
	if(pos1>=a.size()) return false;
	if(get_key(a[pos1-1],std)!=get_key(a[pos1],std)){
		s.erase(it1);
		return true;
	}else
		return false;
}
void opera(int l,int r,int std){
//	cerr<<"["<<l<<","<<r<<"]"<<endl;
	int cnt1=(r-l+1+1)/2;
	ans=max(ans,(r-l)/2);
	if(get_key(a[l],std)==get_key(a[r],std)){
		if(get_key(a[l],std)==0){
//			printf("[%d %d %d]",l,r,std);
			seg.change(1,0,a.size()-1,l,r,std);
		}
	}else if(get_key(a[l],std)==0){
		if(l<=l+cnt1-1){
//			printf("[%d %d %d]",l,l+cnt1-1,std);
			seg.change(1,0,a.size()-1,l,l+cnt1-1,std);
		}
	}else{
		if(l+cnt1<=r){
//			printf("[%d %d %d]",l+cnt1,r,std);
			seg.change(1,0,a.size()-1,l+cnt1,r,std);

		}
	}
}
int gk(set<int>::iterator it){
	return it==s.end()?(int)a.size():*it;
}
void solve(int std,vector<int> pos){
	for(auto x:pos){
		s.insert(x);
		if(x+1<a.size()) s.insert(x+1);
	}
	for(auto x:pos){
		while(1){
			auto it=s.lower_bound(x);
			if(it==s.end()) break;
			auto it1=next(it);
			if(it1==s.end()) break;
			if(!check(it,it1,std)) break;
		}
		while(1){
			auto it=s.lower_bound(x);
			if(it==s.begin()||it==s.end()) break;
			auto it1=prev(it);
			if(!check(it1,it,std)) break;
		}
	}
	for(auto x:pos){
		auto it=s.lower_bound(x);
		if(it!=s.end()){
			auto it1=next(it);
			opera((*it),gk(it1)-1,std);
			if(it1!=s.end()){
				auto it2=next(it1);
				opera(*it1,gk(it2)-1,std);
			}
		}
		if(it!=s.begin()){
			auto it1=prev(it);
			opera((*it1),gk(it)-1,std);
			if(it1!=s.begin()){
				auto it2=prev(it1);
				opera(*it2,gk(it1)-1,std);
			}
		}
	}
//	for(auto x:s) printf("[%d]",x); puts("");
//	for(auto x:a) printf("%d",get_key(x,std)); puts("");
}
map<int,vector<int> > k;
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	int n; scanf("%d",&n); a.resize(n);
	for(int i=0;i<n;++i) s.insert(i);
	seg.build(1,0,n-1);
	for(int i=0;i<n;++i) scanf("%d",&a[i]),k[a[i]].push_back(i);
	for(auto x:k)
		solve(x.first,x.second);
	vector<int> ret; ret.resize(n); seg.dfs(1,0,a.size()-1,2e9,ret);
	printf("%d\n",ans);
	for(auto x:ret) printf("%d ",x); puts("");
	return 0;
}