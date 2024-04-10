#include <iostream>
#include <cstdio>
using namespace std;
int n,a[100005];
struct node{
	int l,r;
}tree[5000005];
int cnt,ans;
inline int newnode(){
	cnt++;
	tree[cnt].l=tree[cnt].r=0;
	return cnt;
}
inline void build(int x){
	int now=0;
	for (int i=30;i>=0;i--){
		if ((x&(1<<i))==0){
			if (tree[now].l==0)tree[now].l=newnode(),now=tree[now].l;
			else now=tree[now].l;
		}
		else{
			if (tree[now].r==0)tree[now].r=newnode(),now=tree[now].r;
			else now=tree[now].r;
		}
	}
	return;
}
inline int dfs(int dep,int now){
	if (dep<0)return 0;
	int s=2e9;
	if (tree[now].l==0)s=dfs(dep-1,tree[now].r);
	else if (tree[now].r==0)s=dfs(dep-1,tree[now].l);
	else s=min(dfs(dep-1,tree[now].l)+(1<<dep),dfs(dep-1,tree[now].r)+(1<<dep));
	return s;
}
int main(){
//	freopen("1285D.in","r",stdin);
//	freopen("1285D.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	tree[0].l=tree[0].r=0;
	for (int i=1;i<=n;i++)build(a[i]);
	cout<<dfs(30,0)<<endl;
	return 0;
}