#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+1e5;
vector<int> ans;
struct SEG{
	vector<pair<int,int> > tree[2][MAX_N<<2];
	void change(int p,int l,int r,int x,int y,int t,pair<int,int> key){
	//	cerr<<p<<endl;
		if(l==x&&r==y){
			tree[t][p].push_back(key);
			return;
		}
		int mid=l+r>>1;
		if(y<=mid) change(p+p,l,mid,x,y,t,key);
		else if(x>mid) change(p+p+1,mid+1,r,x,y,t,key);
		else change(p+p,l,mid,x,mid,t,key)
			,change(p+p+1,mid+1,r,mid+1,y,t,key);
	}
	void dfs(int p,int l,int r,vector<int> a){
		for(auto t:tree[0][p]){
			for(int i=a.size()-1;i>=t.first;--i)
				a[i]=max(a[i],a[i-t.first]+t.second);
		}
		if(l==r){
			for(int i=1;i<a.size();++i) a[i]=max(a[i],a[i-1]);
			for(auto i:tree[1][p]){
//				if(i.second==1) printf("<%d>",i.first);
				ans[i.second]=a[i.first];
			}
			return;
		}
		int mid=l+r>>1;
		dfs(p+p,l,mid,a);
		dfs(p+p+1,mid+1,r,a);
	}
}seg;
int main(){
	int n,p; scanf("%d%d",&n,&p);
	for(int i=1;i<=n;++i){
		int c,h,t; scanf("%d%d%d",&c,&h,&t);
		seg.change(1,1,20000,t,t+p-1,0,make_pair(c,h));
//		printf("|%d %d %d %d|",t,t+p-1,c,h);
	}
	vector<int> a; a.resize(4005);
	int q; scanf("%d",&q); ans.resize(q);
	for(int i=0;i<q;++i){
		int a,b; scanf("%d%d",&a,&b);
		seg.change(1,1,20000,a,a,1,make_pair(b,i));
	}
	seg.dfs(1,1,20000,a);
	for(auto i:ans) printf("%d\n",i);
	return 0;
}