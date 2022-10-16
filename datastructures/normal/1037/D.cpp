#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
int n,u[500005],v[500005],first[500005],nxt[500005];
int a[500005],book[500005];
map<int,int> c[500005];
int deg[500005];
int q[500005],head,tail;
int main(){
	cin>>n;
	for (int i=1;i<n;i++){
		scanf("%d%d",&u[i],&v[i]);
		deg[u[i]]++,deg[v[i]]++;
		c[u[i]][v[i]]=c[v[i]][u[i]]=1;
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+n]=v[i],v[i+n]=u[i];
		nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
	}
	for (int i=2;i<=n;i++)deg[i]--;
	scanf("%d",&a[1]);
	if (a[1]!=1){
		cout<<"No"<<endl;
		return 0;
	}
	head=tail=1;
	q[1]=1;
	for (int i=2;i<=n;i++){
		scanf("%d",&a[i]);
		if (book[a[i]]==1){
			cout<<"No"<<endl;
			return 0;
		}
		while(head<=tail&&deg[q[head]]==0)head++;
		int now=q[head];
		if (c[now][a[i]]==0){
			cout<<"No"<<endl;
			return 0;
		}
		q[++tail]=a[i];
		deg[now]--;
		book[a[i]]=1;
	}
	cout<<"Yes"<<endl;
	return 0;
}