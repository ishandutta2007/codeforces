#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
int book[500005],cnt[500005],mx[500005];
int n,m,u[1000005],v[1000005],first[1000005],nxt[1000005],ok=1;
map <int,int>fg[500005];
struct node{
	int val,id; 
}a[500005];
inline bool cmp(node a,node b){
	return a.val<b.val;
}
inline void del(int now,int val){
	if (mx[now]!=cnt[now]||mx[now]!=val-1){
		ok=0;
		return;
	}
	for (register int i=first[now];i;i=nxt[i])
		if (book[v[i]]==0){
			if (fg[v[i]][val]==0){
				fg[v[i]][val]=1;
				mx[v[i]]=max(mx[v[i]],val);
				cnt[v[i]]++;
			}
		}
	return;
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&u[i],&v[i]);
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+m]=v[i],v[i+m]=u[i];
		nxt[i+m]=first[u[i+m]],first[u[i+m]]=i+m;
	}
	for (int i=1;i<=n;i++)scanf("%d",&a[i].val),a[i].id=i;
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=n;i++)
		del(a[i].id,a[i].val);
	if (ok==0){
		cout<<-1<<endl;
		return 0;
	}
	for (int i=1;i<=n;i++)printf("%d ",a[i].id);
	cout<<endl;
	return 0;
}