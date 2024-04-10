#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct BIT{
	int tree[500005],maxn;
	void mem(){
		memset(tree,0,sizeof(tree));
		maxn=500000;
		return;
	}
	int lowbit(int x){
		return x&(-x);
	}
	void add(int pos,int val){
		while(pos<=maxn)tree[pos]+=val,pos+=lowbit(pos);
		return;
	}
	int ask(int pos){
		int ans=0;
		while(pos)ans+=tree[pos],pos-=lowbit(pos);
		return ans;
	}
}bit;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
struct node{
	int l,r,id;
}c[100005];
bool cmp1(node a,node b){
	return a.r<b.r;
}
bool cmp2(node a,node b){
	return a.l<b.l;
}
int n,meiyongdebianliang,m,book[100005][10],f[100005][10],val[100005];
int q,l,r;
int ans[100005];
int main(){
	cin>>n>>meiyongdebianliang>>m;
	for (int i=1;i<=m;i++){
		int u,v;
		u=read(),v=read();
		if (u>v)swap(u,v);
		book[v][v-u]=1;
	}
	memset(f,0x3f,sizeof(f));
	memset(val,0x3f,sizeof(val));
	for (int i=n;i>=1;i--){
		for (int j=1;j<=5;j++)
			if (book[i][j])f[i][j]=i;
		for (int j=1;j<=5;j++)
			for (int k=1;j+k<=5;k++)
				f[i][j]=min(f[i][j],max(f[i+k][k],f[i+k][j+k]));
		for (int j=1;j<=5;j++)val[i]=min(val[i],f[i][j]);
	}
	cin>>q;
	for (int i=1;i<=q;i++){
		int l,r;
		l=read(),r=read();
		ans[i]=r-l+1;
		for (int j=l;j<=l+4&&j<=r;j++){
			int tmp=1e9;
			for (int k=1;j-k>=l;k++)tmp=min(tmp,f[j][k]);
			if (tmp<=r)ans[i]--;
		}
		l+=5;
		c[i].l=l,c[i].r=r,c[i].id=i;
	}
	bit.mem();
	sort(c+1,c+1+q,cmp1);
	int j=1;
	for (int i=1;i<=q;i++){
		if (c[i].l>c[i].r)continue;
		while(j<=c[i].r){
			if (val[j]<=n)bit.add(val[j],1);
			j++;
		}
		ans[c[i].id]-=bit.ask(c[i].r);
	}
	bit.mem();
	sort(c+1,c+1+q,cmp2);
	j=1;
	for (int i=1;i<=q;i++){
		if (c[i].l>c[i].r)continue;
		while(j<c[i].l){
			if (val[j]<=n)bit.add(val[j],1);
			j++;
		}
		ans[c[i].id]+=bit.ask(c[i].r);
	}
	for (int i=1;i<=q;i++)printf("%d\n",ans[i]);
	return 0;
}