#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[2005][2005],_a[2005][2005],b[2005][2005],d[2005],_d[2005];
int n,m,k,ans[2005];
int du[2005],c[2005][2005];
int q[2005],head,tail;
inline void ins(int now){
	ans[++k]=now;
	for (int i=1;i<=n;i++)_d[i]=d[i];
	_d[0]=-1;
	for (int i=1;i<=n;i++){
		if (_d[i]>_d[i-1]||b[i][now]>b[i-1][now]){
			d[i]=d[i-1]+1;
			if (_d[i]>_d[i-1])continue;
			for (int j=1;j<=m;j++){
				if (c[i][j]==1){
					du[j]--;
					if (du[j]==0)q[++tail]=j;
				}
			}
		}
		else d[i]=d[i-1];
	}
	return;
}
inline void out(){
	cout<<k<<endl;
	for (int i=k;i>=1;i--)cout<<ans[i]<<' ';
	cout<<endl;
	return;
}
struct node{
	int ID,val,id;
}s[1505];
inline bool cmp(node a,node b){
	if (a.val==b.val)return a.id<b.id;
	return a.val<b.val;
}
inline void Sort(int now){
	for (register int i=1;i<=n;i++)s[i].val=a[s[i].ID][now],s[i].id=i;
	sort(s+1,s+1+n,cmp);
	return;
}
inline bool check(){
	for (int i=1;i<=n;i++)s[i].ID=i;
	for (int i=k;i>=1;i--)Sort(ans[i]);
	for (register int i=1;i<=n;i++)
		for (register int j=1;j<=m;j++)
			_a[i][j]=a[i][j];
	for (register int i=1;i<=n;i++)
		for (register int j=1;j<=m;j++)
			a[i][j]=_a[s[i].ID][j];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (a[i][j]!=b[i][j])return 0;
	return 1;
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&b[i][j]);
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			if (b[j][i]<b[j-1][i])du[i]++,c[j][i]=1;
	head=1,tail=0;
	for (int i=1;i<=m;i++)
		if (du[i]==0)q[++tail]=i;
	while(head<=tail){
		ins(q[head]);
		++head;
	}
	if (check())out();
	else cout<<-1<<endl;
}