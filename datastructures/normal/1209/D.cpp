#include <iostream>
#include <cstdio>
using namespace std;
int n,m,u[200005],v[200005],first[100005],nxt[200005];
int book[100005];
int ans;
void add(int i,int a,int b){
	u[i]=a,v[i]=b;
	nxt[i]=first[u[i]];
	first[u[i]]=i;
	return;
}
int dfs(int now){
	int s=1;
	book[now]=1;
	for (int i=first[now];i;i=nxt[i])
		if (!book[v[i]])s+=dfs(v[i]);
	return s;
}
int main(){
//	freopen("d.in","r",stdin);
//	freopen("d.out","w",stdout);
	cin>>n>>m; 
	for (int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		add(i,a,b);
		add(i+m,b,a);
	}
	for (int i=1;i<=n;i++)
		if (!book[i]){
			int s=dfs(i);
			ans+=s-1;
		}
	cout<<m-ans<<endl;
	return 0;
}