#include <iostream>
#include <cstdio>
using namespace std;
struct node{
	int cnt,id[2005],num[2005];
}a[2005];
int n,root,f,u[2005],v[2005],first[2005],nxt[2005];
int c[2005],size[2005];
int flag,ans[2005];
inline void dfs(int now){
	int tag=0;
	for (int i=first[now];i;i=nxt[i]){
		dfs(v[i]);
		for (int j=1;j<=a[v[i]].cnt;j++){
			++a[now].cnt;
			int tmp=a[v[i]].num[j]+tag;
			if (tmp>c[now])++tmp;
			a[now].id[a[now].cnt]=a[v[i]].id[j];
			a[now].num[a[now].cnt]=tmp;
		}
		tag+=a[v[i]].cnt;
	}
	++a[now].cnt;
	a[now].id[a[now].cnt]=now,a[now].num[a[now].cnt]=c[now]+1;
	return;
}
inline void check(int now){
	size[now]=1;
	for (int i=first[now];i;i=nxt[i]){
		check(v[i]);
		size[now]+=size[v[i]];
	}
	if (c[now]>=size[now])flag=1;
	return;
}
int main(){
//	freopen("1286D.in","r",stdin);
//	freopen("1286D.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>u[i]>>c[i];
		if (u[i]==0){
			root=i;
			continue;
		}
		v[i]=i;
		nxt[i]=first[u[i]];
		first[u[i]]=i;
	}
	check(root);
	if (flag==1){
		cout<<"NO"<<endl;
		return 0;
	}
	dfs(root);
	cout<<"YES"<<endl;
	for (int i=1;i<=a[root].cnt;i++)ans[a[root].id[i]]=a[root].num[i];
	for (int i=1;i<=n;i++)cout<<ans[i]<<' ';
	return 0;
}