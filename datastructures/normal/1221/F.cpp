#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
int n,x[1000005],y[1000005],c[1000005],_s[1000005];
vector <int>pos[1000005],val[1000005];
inline int lower(int x){
	int l=1,r=2*n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (_s[mid]<=x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
struct SGT{
	int tree[5000005],tag[5000005],maxn;
	SGT(){
		maxn=1000000;
		for (register int i=0;i<=1000000;i++)tag[i]=0,tree[i]=-2e9;
		return;
	}
	inline void pushup(int now){
		tree[now]=max(tree[now*2],tree[now*2+1]);
		return;
	}
	inline void pushdown(int now){
		tree[now*2]+=tag[now],tree[now*2+1]+=tag[now];
		tag[now*2]+=tag[now],tag[now*2+1]+=tag[now];
		tag[now]=0;
		return; 
	}
	inline void tree_update(int now,int nowl,int nowr,int lt,int rt,int val){
		if (nowl!=nowr)pushdown(now);
		if (nowl>=lt&&nowr<=rt){
			tree[now]+=val;
			tag[now]+=val;
			return;
		}
		int mid=(nowl+nowr)/2;
		if (mid>=lt)tree_update(now*2,nowl,mid,lt,rt,val);
		if (mid+1<=rt)tree_update(now*2+1,mid+1,nowr,lt,rt,val);
		pushup(now);
		return; 
	}
	inline void update(int l,int r,int val){
		tree_update(1,1,maxn,l,r,val);
		return;
	}
	inline int tree_query(int now,int nowl,int nowr,int lt,int rt){
		if (nowl!=nowr)pushdown(now);
		if (nowl>=lt&&nowr<=rt)return tree[now];
		int mid=(nowl+nowr)/2,s=0;
		if (mid>=lt)s=max(s,tree_query(now*2,nowl,mid,lt,rt));
		if (mid+1<=rt)s=max(s,tree_query(now*2+1,mid+1,nowr,lt,rt));
		return s; 
	}
	inline int query(int l,int r){
		return tree_query(1,1,maxn,l,r);
	}
	inline int tree_find(int now,int nowl,int nowr){
		if (nowl!=nowr)pushdown(now);
		if (nowl==nowr)return nowl;
		int mid=(nowl+nowr)/2;
		if (tree[now*2]>=tree[now*2+1])return tree_find(now*2,nowl,mid);
		return tree_find(now*2+1,mid+1,nowr);
	}
	inline int find(){
		return tree_find(1,1,maxn);
	}
}sgt;
int ans,ansx=2e9,ansy=2e9;
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&x[i],&y[i],&c[i]);
		_s[i*2-1]=x[i],_s[i*2]=y[i];
	}
	sort(_s+1,_s+1+2*n);
	for (int i=1;i<=n;i++)x[i]=lower(x[i]),y[i]=lower(y[i]);
	for (int i=1;i<=n;i++)pos[max(x[i],y[i])].push_back(min(x[i],y[i])),val[max(x[i],y[i])].push_back(c[i]);
	n*=2;
	for (int i=1;i<=n;i++){
		for (int j=0,len=pos[i].size();j<len;j++)
			sgt.update(1,pos[i][j],val[i][j]);
		if (sgt.query(1,i)-_s[i]>ans){
			ans=sgt.query(1,i)-_s[i];
			ansx=_s[sgt.find()],ansy=_s[i];
		}
		sgt.update(i,i,_s[i]);
	}
	cout<<ans<<endl<<ansx<<' '<<ansx<<' '<<ansy<<' '<<ansy<<endl;
	return 0;
}