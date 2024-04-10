#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#define int long long
using namespace std;
int n,m,k,a[300005],b[300005],c[300005];
int df[300005],mn[300005];
vector <int>s[10005];
int f[5005][5005];
bool cmp(int a,int b){
	return a>b;
}
inline int dfs(int now,int nowk){
	if (f[now][nowk]!=-1)return f[now][nowk];
	if (now>n)return 0;
	if (nowk+b[now]<a[now+1])return -1e10;
	int sss=dfs(now+1,nowk+b[now]);
	for (int i=0;i<s[now].size()&&(nowk-i-1+b[now]>=a[now+1]);i++){
		sss=max(sss,dfs(now+1,nowk-i-1+b[now])+s[now][i]);
	}
	return f[now][nowk]=sss;
}
signed main(){
//	freopen("d.in","r",stdin);
//	freopen("d.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
	for (int i=1;i<=n;i++)df[i]=i;
	for (int i=1;i<=m;i++){
		int u,v;
		scanf("%I64d%I64d",&u,&v);
		df[v]=max(df[v],u);
	}
	for (int i=1;i<=n;i++){
		s[df[i]].push_back(c[i]);
	}
	for (int i=1;i<=n;i++)sort(s[i].begin(),s[i].end(),cmp);
	for (int i=1;i<=n;i++){
		for (int j=1;j<s[i].size();j++)s[i][j]+=s[i][j-1];
	}
	int flag=1,now=k;
	for (int i=1;i<=n;i++){
		if (a[i]>now)flag=0;
		now+=b[i];
	} 
	if (flag==0){
		cout<<-1<<endl;
		return 0;
	}
	memset(f,-1,sizeof(f));
	cout<<dfs(1,k)<<endl;
}