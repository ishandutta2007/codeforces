#include<bits/stdc++.h>
using namespace std;
const int N=1005;
struct DSF{
	int fa[N];
	void init(int n){ for(int i=0;i<=n;++i) fa[i]=i; }
	int fs(int x){ 
		if(fa[x]!=x) return fs(fa[x]);
		return fa[x];
	}
	void merge(int x,int y){
		fa[fs(y)]=fs(x);
	}
}dsf;
struct E{ int x,y,w; };
bool cmp(E x,E y){ 
	if(x.w!=y.w) return x.w<y.w; 
	if(x.x!=y.x) return x.x<y.x;
	return x.y<y.y;
}
int a[N];
vector<pair<int,int> > ans;
int main(){
	int n; scanf("%d",&n);
	vector<E> e;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			int x; scanf("%d",&x);
			if(i==j){
				a[i]=x;
			}else if(i<j){
				e.push_back((E){i,j,x});
			}
		}
	}
	sort(e.begin(),e.end(),cmp);
	dsf.init(n+n);
	int top=n;
	for(auto d:e)
		if(dsf.fs(d.x)!=dsf.fs(d.y)){
			int x=dsf.fs(d.x),y=dsf.fs(d.y);
			if(a[x]==d.w){
				ans.push_back(make_pair(x,y));
				dsf.fa[y]=x;
			}else if(a[y]==d.w){
				ans.push_back(make_pair(y,x));
				dsf.fa[x]=y;
			}else{
				++top; a[top]=d.w;
				dsf.fa[x]=dsf.fa[y]=top;
				ans.push_back(make_pair(top,x));
				ans.push_back(make_pair(top,y));
			}
		}
	printf("%d\n",top);
	for(int i=1;i<=top;++i) printf("%d ",a[i]); puts("");
	printf("%d\n",top);
	for(auto d:ans) printf("%d %d\n",d.second,d.first);
	return 0;
}