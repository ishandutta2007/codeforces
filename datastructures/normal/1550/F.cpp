#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#define inf 1000000000
using namespace std;
int n,q,s,d,a[200005],id[1000005];
int fa[200005],num;
int ans[200005],x,y;
vector<int> c[200005];
set<int> qwq;
set<int>::iterator it;
int totm,u[400005],v[400005],w[400005],first[200005],nxt[400005];
int find(int x){
	if (x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void add(int a,int b,int c){
	int i=++totm;
	u[i]=a,v[i]=b,w[i]=c;
	nxt[i]=first[u[i]],first[u[i]]=i;
	return;
}
void dfs(int now,int fa){
	for (int i=first[now];i;i=nxt[i]){
		if (v[i]==fa)continue;
		ans[v[i]]=max(ans[now],w[i]);
		dfs(v[i],now);
	}
	return;
}
int main(){
	cin>>n>>q>>s>>d;
	qwq.insert(-inf),qwq.insert(inf);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		id[a[i]]=i;
		qwq.insert(a[i]);
	}
	for (int i=1;i<=n;i++)fa[i]=i;
	num=n;
	while(num>1){
		for (int i=1;i<=n;i++)c[find(i)].push_back(a[i]);
		for (int i=1;i<=n;i++){
			if (c[i].size()==0)continue;
			for (int j=0;j<c[i].size();j++)qwq.erase(c[i][j]);
			int mn=inf,nowid=-1;
			for (int j=0;j<c[i].size();j++){
				int v1=-1,v2=-1,v3=-1,v4=-1;
				it=qwq.lower_bound(c[i][j]-d);
				v1=*it;
				it--;
				v2=*it;
				it=qwq.lower_bound(c[i][j]+d);
				v3=*it;
				it--;
				v4=*it;
				if (v1!=inf){
					if (v1-(c[i][j]-d)<mn)
						mn=v1-(c[i][j]-d),nowid=id[v1];
				}
				if (v2!=-inf){
					if ((c[i][j]-d)-v2<mn)
						mn=(c[i][j]-d)-v2,nowid=id[v2];
				}
				if (v3!=inf){
					if (v3-(c[i][j]+d)<mn)
						mn=v3-(c[i][j]+d),nowid=id[v3];
				}
				if (v4!=inf){
					if ((c[i][j]+d)-v4<mn)
						mn=(c[i][j]+d)-v4,nowid=id[v4];
				}
			}
			if (nowid!=-1){
				int x=find(i),y=find(nowid);
				if (x!=y){
					fa[x]=y;
					add(x,y,mn);
					add(y,x,mn);
					num--;
				}
			}
			for (int j=0;j<c[i].size();j++)qwq.insert(c[i][j]);
		}
		for (int i=1;i<=n;i++)c[i].clear();
	}
	dfs(s,0);
	while(q--){
		scanf("%d%d",&x,&y);
		if (ans[x]<=y)puts("Yes");
		else puts("No");
	}
	return 0;
}