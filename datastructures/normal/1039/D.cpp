#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int B=1000;
int n,tot,u[100005],v[100005],first[100005],nxt[100005];
int cnt;
int ans[100005];
vector<int> e[100005];
void qwq_dfs(int now,int fa){
	for (int i=0,len=e[now].size();i<len;i++){
		if (e[now][i]==fa)continue;
		qwq_dfs(e[now][i],now);
		++tot;
		u[tot]=now,v[tot]=e[now][i];
		nxt[tot]=first[u[tot]],first[u[tot]]=tot;
	}
	return;
}
int dfs(int now,int fa,int k){
	int fi=0,se=0;
	for (int i=first[now];i;i=nxt[i]){
		if (v[i]==fa)continue;
		int qwq=dfs(v[i],now,k);
		if (qwq>=fi)se=fi,fi=qwq;
		else if (qwq>se)se=qwq;
	}
	if (fi+se+1>=k){
		cnt++;
		return 0;
	}
	return fi+1;
}
int main(){
	cin>>n;
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	qwq_dfs(1,0);
	for (int i=1;i<=B;i++){
		cnt=0;
		dfs(1,0,i);
		ans[i]=cnt;
	}
	for (int i=B+1;i<=n;){
		cnt=0;
		dfs(1,0,i);
		ans[i]=cnt;
		int l=i+1,r=n,qwq=n+1;
		while(l<=r){
			int mid=(l+r)/2;
			cnt=0;
			dfs(1,0,mid);
			if (cnt<ans[i])qwq=mid,r=mid-1;
			else l=mid+1;
		}
		for (int j=i+1;j<qwq;j++)ans[j]=ans[i];
		i=qwq;
	}
	for (int i=1;i<=n;i++)printf("%d\n",ans[i]);
	return 0;
}