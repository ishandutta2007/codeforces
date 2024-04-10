#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
struct node{
	int id,val;
}c[1000005],d[1000005];
int l1,l2;
int n,m,deg[100005];
int tot,sta[1000005][3];
signed main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		int x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		deg[x]+=z,deg[y]-=z;
	}
	for (int i=1;i<=n;i++){
		if (deg[i]>0){
			++l1;
			c[l1].id=i;
			c[l1].val=deg[i];
		}
		if (deg[i]<0){
			++l2;
			d[l2].id=i;
			d[l2].val=-deg[i];
		}
	}
	int j=1;
	for (int i=1;i<=l1;i++){
		int val=c[i].val;
		while(j<=l2&&val>0){
			int qwq=min(val,d[j].val);
			val-=qwq,d[j].val-=qwq;
			++tot;
			sta[tot][0]=c[i].id,sta[tot][1]=d[j].id,sta[tot][2]=qwq;
			if (d[j].val==0)j++;
		}
	}
	cout<<tot<<endl;
	for (int i=1;i<=tot;i++)printf("%lld %lld %lld\n",sta[i][0],sta[i][1],sta[i][2]);
	return 0;
}