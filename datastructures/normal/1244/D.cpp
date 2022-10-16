#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int n,c[100005][3],x[100005],ans[100005],mn=1e18;
int u[100005],v[100005],du[100005],book[100005],nxt[100005][3];
int head,id[100005],tot;
signed main(){
	cin>>n;
	for (int j=0;j<3;j++)
		for (int i=1;i<=n;i++)
			scanf("%I64d",&c[i][j]);
	int flag=1;
	for (int i=1;i<n;i++){
		scanf("%I64d%I64d",&u[i],&v[i]);
		du[u[i]]++,du[v[i]]++;
		if (du[u[i]]>2||du[v[i]]>2)flag=0;
		nxt[u[i]][du[u[i]]]=v[i],nxt[v[i]][du[v[i]]]=u[i];
	}
	if (flag==0){
		cout<<-1<<endl;
		return 0;
	}
	for (head=1;head<=n;head++)
		if (du[head]==1)break;
	while(tot<n){
		++tot;
		id[tot]=head;
		book[head]=1;
		for (int i=1;i<=du[head];i++)
			if (!book[nxt[head][i]]){
				head=nxt[head][i];
				break; 
			} 
	}
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++){
			if (i==j)continue;
			x[id[1]]=i,x[id[2]]=j;
			for (int k=3;k<=n;k++)
				x[id[k]]=3-x[id[k-1]]-x[id[k-2]];
			int s=0;
			for (int k=1;k<=n;k++)
				s+=c[k][x[k]]; 
			if (s<mn){
				mn=s;
				for (int k=1;k<=n;k++)
					ans[k]=x[k];
			}
		}
	cout<<mn<<endl;
	for (int i=1;i<=n;i++)printf("%I64d ",ans[i]+1);
	return 0;
}