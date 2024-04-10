#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define ll long long
#define inf 1000000000
#define maxn 200000
using namespace std;
int n,m;
ll l,r;
int x1[200005],y1[200005],x2[200005],y2[200005];
int tree[1000005];
void upd(int now,int nowl,int nowr,int pos,int val){
	if (nowl==nowr){
		tree[now]=val;
		return;
	}
	int mid=(nowl+nowr)/2;
	if (pos<=mid)upd(now*2,nowl,mid,pos,val);
	else upd(now*2+1,mid+1,nowr,pos,val);
	tree[now]=min(tree[now*2],tree[now*2+1]);
	return;
}
int ask(int now,int nowl,int nowr,int lt,int rt){
	if (nowl>=lt&&nowr<=rt)return tree[now];
	int mid=(nowl+nowr)/2,s=inf;
	if (mid>=lt)s=min(s,ask(now*2,nowl,mid,lt,rt));
	if (mid+1<=rt)s=min(s,ask(now*2+1,mid+1,nowr,lt,rt));
	return s;
}
int main(){
	cin>>n>>m>>l>>r;
	memset(x1,-1,sizeof(x1));
	memset(y1,-1,sizeof(y1));
	memset(x2,-1,sizeof(x2));
	memset(y2,-1,sizeof(y2));
	memset(tree,0x7f,sizeof(tree));
	for (int p=n;p>=1;p--){
		for (int d=1;p*d<=n;d++){
			if (p>=n/d)continue;
			ll qwql=(l+p*d-1)/(p*d),qwqr=min(1ll*m,r/(p*d));
			if (qwql>qwqr)continue;
			int q=ask(1,1,m,qwql,qwqr);
			if (q>n/d)continue;
			int k=(qwql+q-1)/q;
			int ovo=p*d;
			x1[ovo]=p*d;
			y1[ovo]=q*k;
			x2[ovo]=q*d;
			y2[ovo]=p*k;
		}
		for (int i=p;i<=m;i+=p)upd(1,1,m,i,p);
	}
	for (int i=1;i<=n;i++)
		if (x1[i]!=-1)printf("%d %d %d %d\n",x1[i],y1[i],x2[i],y2[i]);
		else printf("-1\n");
	return 0;
}