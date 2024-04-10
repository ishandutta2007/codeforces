#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t,n,u[2005],v[2005],first[2005],nxt[2005];
int k1,c1[2005],k2,c2[2005];
int book1[2005],book2[2005],id[2005];
int ask(int opt,int pos){
	if (opt==0)cout<<"A "<<pos<<endl;
	else cout<<"B "<<pos<<endl;
	int x;
	cin>>x;
	return x;
}
void dfs(int now,int qwq){
	if (book1[now]!=0||id[now]!=0)return;
	id[now]=qwq;
	for (int i=first[now];i;i=nxt[i])dfs(v[i],qwq);
	return;
}
int main(){
	cin>>t;
	while(t--){
		memset(first,0,sizeof(first));
		memset(nxt,0,sizeof(nxt));
		cin>>n;
		for (int i=1;i<n;i++){
			cin>>u[i]>>v[i];
			nxt[i]=first[u[i]],first[u[i]]=i;
			u[i+n]=v[i],v[i+n]=u[i];
			nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
		}
		memset(book1,0,sizeof(book1));
		memset(book2,0,sizeof(book2));
		memset(id,0,sizeof(id));
		cin>>k1;
		for (int i=1;i<=k1;i++)cin>>c1[i],book1[c1[i]]=1;
		cin>>k2;
		for (int i=1;i<=k2;i++)cin>>c2[i],book2[c2[i]]=1;
		for (int i=1;i<=k1;i++){
			int now=c1[i];
			id[now]=i;
			for (int j=first[now];j;j=nxt[j])dfs(v[j],i);
		}
		int pos=ask(1,c2[1]);
		int qwq=ask(0,c1[id[pos]]);
		if (book2[qwq]==0)cout<<"C "<<-1<<endl;
		else cout<<"C "<<c1[id[pos]]<<endl;
	}
	return 0;
}