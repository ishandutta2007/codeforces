#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#define maxn 1000000
#define int long long
using namespace std;
struct BIT{
	int tree[1000005];
	BIT(){
		memset(tree,0,sizeof(tree));
		return;
	}
	inline int lowbit(int x){
		return x&(-x);
	}
	inline void add(int pos,int val){
		while(pos<=maxn)tree[pos]+=val,pos+=lowbit(pos);
		return;
	}
	inline int tree_ask(int pos){
		if (pos<1)return 0;
		int ans=0;
		while(pos)ans+=tree[pos],pos-=lowbit(pos);
		return ans;
	}
	inline int ask(int l,int r){
		return tree_ask(r)-tree_ask(l-1);
	}
}bit;
struct node{
	int a,l,r;
}a[100005],b[100005];
int n,m,num=1,ans;
vector <int>ins[1000005],del[1000005];
vector <int>l[1000005],r[1000005];
signed main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a[i].a,&a[i].l,&a[i].r);
		if (a[i].l==0&&a[i].r==maxn)num++,bit.add(a[i].a,1);
		else if (a[i].l==0)del[a[i].r+1].push_back(a[i].a),bit.add(a[i].a,1);
		else if (a[i].r==maxn)ins[a[i].l].push_back(a[i].a);
	}
	ans=num;
	for (int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&b[i].a,&b[i].l,&b[i].r);
		if (b[i].l==0&&b[i].r==maxn)ans++;
		l[b[i].a].push_back(b[i].l),r[b[i].a].push_back(b[i].r);
	}
	for (int i=1;i<=maxn;i++){
		for (int j=0,len=ins[i].size();j<len;j++)
			bit.add(ins[i][j],1);
		for (int j=0,len=del[i].size();j<len;j++)
			bit.add(del[i][j],-1);
		for (int j=0,len=l[i].size();j<len;j++)
			ans+=bit.ask(l[i][j],r[i][j]);
	}
	cout<<ans<<endl;
	return 0;
}