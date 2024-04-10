#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+1e6;
struct DSF{
	int fa[MAX_N];
	void ms(int x){ fa[x]=x; }
	int find_set(int x){
		if(fa[x]!=x) fa[x]=find_set(fa[x]);
		return fa[x];
	}
	void merge(int x,int y){
		if(find_set(x)!=find_set(y))
			fa[find_set(y)]=find_set(x);
	}
}dsf;
vector<int> e[MAX_N];
int tag[MAX_N],id[MAX_N];
void build(int p,int l,int r){
	tag[p]=0;
	if(l==r){
		id[l]=p;
		return;
	}
	int m=l+r>>1;
	build(p+p,l,m);
	build(p+p+1,m+1,r);
}
void change(int p,int l,int r,int x,int y,int o){
	if(l==x&&r==y){
		tag[p]=1;
		dsf.merge(o,p);
		return;
	}
	int m=l+r>>1;
	if(y<=m) change(p+p,l,m,x,y,o);
	else if(x>m) change(p+p+1,m+1,r,x,y,o);
	else change(p+p,l,m,x,m,o),change(p+p+1,m+1,r,m+1,y,o);
}
void down(int p,int l,int r){
	if(l==r) return;
	int m=l+r>>1;
	if(tag[p]){
		tag[p+p]=1;
		tag[p+p+1]=1;
		dsf.merge(p,p+p);
		dsf.merge(p,p+p+1);
	}
	down(p+p,l,m);
	down(p+p+1,m+1,r);
}
int main(){
	int n,m; scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		int x,y; scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	build(1,1,n);
	for(int i=1;i<=n*4;++i) dsf.ms(i);
	for(int i=1;i<=n;++i){
		e[i].push_back(n+1);
		sort(e[i].begin(),e[i].end());
		int last=0;
		for(int j=0;j<e[i].size();++j){
			if(last+1<=e[i][j]-1)
				change(1,1,n,last+1,e[i][j]-1,id[i]);
			last=e[i][j];
		}
	}
	down(1,1,n);
	vector<int> ans;
	for(int i=1;i<=n;++i) 
		ans.push_back(dsf.find_set(id[i]));
	sort(ans.begin(),ans.end());
	ans.erase(unique(ans.begin(),ans.end()),ans.end());
	printf("%d\n",(int)ans.size()-1);
	return 0;
}