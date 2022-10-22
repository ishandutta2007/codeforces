#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+2e5;
int a[MAX_N];
struct SEG{
	int t[MAX_N<<2];
	void build(int p,int l,int r){
		t[p]=r-l+1;
		if(l==r) return;
//		printf("(%d %d %d %d)",p,l,r,t[p]);
		int m=l+r>>1;
		build(p+p,l,m);
		build(p+p+1,m+1,r);
	}
	void change(int p,int l,int r,int x){
		if(l==r){
			t[p]=0;
			return;
		}
		int m=l+r>>1;
		if(x<=m) change(p+p,l,m,x);
		else change(p+p+1,m+1,r,x);
		t[p]=t[p+p]+t[p+p+1];
	}
	int query(int p,int l,int r,int x){
		if(l==r) return l;
		int m=l+r>>1;
		if(x<=t[p+p]) return query(p+p,l,m,x);
		else return query(p+p+1,m+1,r,x-t[p+p]);
	}
}seg;
priority_queue<pair<int,int> > s;
struct Q{ int k,pos,id; };
vector<Q> q[MAX_N];
int ans[MAX_N];
int main(){
	int n; scanf("%d",&n);
	seg.build(1,1,n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		s.push(make_pair(-a[i],i));
	}
//	for(int i=1;i<=n;++i) printf("(%d)",seg.query(1,1,n,i)); puts("");
	int m; scanf("%d",&m);
	for(int i=1;i<=m;++i){
		int k,pos; scanf("%d%d",&k,&pos);
		q[k].push_back((Q){k,pos,i});
	}
	for(int i=n;i>=1;--i){
		for(auto x:q[i])
			ans[x.id]=seg.query(1,1,n,x.pos);
		seg.change(1,1,n,s.top().second);
//		printf("|%d|",s.top().second);
		s.pop();
	}
	for(int i=1;i<=m;++i) printf("%d\n",a[ans[i]]);
	return 0;
}