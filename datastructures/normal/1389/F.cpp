#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define maxn 1000000
using namespace std;
struct SGT{
	int tree[4000005],tag[4000005];
	SGT(){
		memset(tree,0,sizeof(tree));
		memset(tag,0,sizeof(tag));
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
	inline int tree_query(int now,int nowl,int nowr,int lt,int rt){
		if (nowl!=nowr)pushdown(now);
		if (nowl>=lt&&nowr<=rt)return tree[now];
		int mid=(nowl+nowr)/2,s=0;
		if (mid>=lt)s=max(s,tree_query(now*2,nowl,mid,lt,rt));
		if (mid+1<=rt)s=max(s,tree_query(now*2+1,mid+1,nowr,lt,rt));
		return s;
	}
	inline void add(int l,int r,int val){
		tree_update(1,1,maxn,l+1,r+1,val);
		return;
	}
	inline int ask(int l,int r){
		return tree_query(1,1,maxn,l+1,r+1);
	}
}sgt0,sgt1;
int n,l[1000005],r[1000005],t[1000005],s[1000005],f[1000005][2],tot;
vector <int>c[2][1000005];
inline int lower(int x){
	int l=1,r=tot,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (s[mid]<=x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		scanf("%d%d%d",&l[i],&r[i],&t[i]);
		s[++tot]=l[i],s[++tot]=r[i];
	}
	sort(s+1,s+1+tot);
	for (int i=1;i<=n;i++){
		l[i]=lower(l[i]);
		r[i]=lower(r[i]);
		c[t[i]-1][r[i]].push_back(l[i]);
	}
	for (int i=1;i<=tot;i++){
		for (int j=0,len=c[0][i].size();j<len;j++)sgt0.add(0,c[0][i][j]-1,1);
		for (int j=0,len=c[1][i].size();j<len;j++)sgt1.add(0,c[1][i][j]-1,1);
		f[i][0]=sgt0.ask(0,i-1);
		f[i][1]=sgt1.ask(0,i-1);
		sgt0.add(i,i,f[i][1]);
		sgt1.add(i,i,f[i][0]);
	}
	cout<<max(f[tot][0],f[tot][1])<<endl;
}