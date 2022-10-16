#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
int n,m,u[600005],v[600005],first[300005],nxt[600005];
int book[300005],ans[300005],tot[5];
signed main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		scanf("%I64d%I64d",&u[i],&v[i]);
		nxt[i]=first[u[i]];
		first[u[i]]=i;
		u[i+m]=v[i],v[i+m]=u[i];
		nxt[i+m]=first[u[i+m]];
		first[u[i+m]]=i+m;
	}
	int now=1;
	ans[now]=1;
	for (int i=first[now];i;i=nxt[i])book[v[i]]=1;
	for (int i=1;i<=n;i++)
		if (book[i]!=1)ans[i]=1;
	now=1;
	while(ans[now]==1&&now<=n)now++;
	memset(book,0,sizeof(book));
	for (int i=first[now];i;i=nxt[i])book[v[i]]=1;
	for (int i=1;i<=n;i++)
		if (ans[i]==0&&book[i]==0)ans[i]=2;
	for (int i=1;i<=n;i++)
		if (ans[i]==0)ans[i]=3;
	for (int i=1;i<=n;i++)tot[ans[i]]++;
	int flag=1;
	if (tot[1]==0||tot[2]==0||tot[3]==0)flag=0; 
	if (tot[1]*tot[2]+tot[2]*tot[3]+tot[3]*tot[1]!=m)flag=0;
	for (int i=1;i<=m;i++)
		if (ans[u[i]]==ans[v[i]])flag=0;
	if (flag==0){
		cout<<-1<<endl;
		return 0;
	}
	for (int i=1;i<=n;i++)printf("%I64d ",ans[i]);
}