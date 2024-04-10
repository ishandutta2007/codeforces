#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
int n,q,opt[200005],l[200005],r[200005],x[200005];
int a[200005],cnt[200005];
set<int> c;
set<int>::iterator it,_it;
int gs(int l,int r){
	return cnt[r]-cnt[l-1];
}
int tree[1000005];
void build(int now,int nowl,int nowr){
	if (nowl==nowr){
		tree[now]=a[nowl];
		return;
	}
	int mid=(nowl+nowr)/2;
	build(now*2,nowl,mid);
	build(now*2+1,mid+1,nowr);
	tree[now]=max(tree[now*2],tree[now*2+1]);
	return;
}
int ask(int now,int nowl,int nowr,int lt,int rt){
	if (nowl>=lt&&nowr<=rt)return tree[now];
	int mid=(nowl+nowr)/2,s=0;
	if (mid>=lt)s=max(s,ask(now*2,nowl,mid,lt,rt));
	if (mid+1<=rt)s=max(s,ask(now*2+1,mid+1,nowr,lt,rt));
	return s;
}
int qwq[200005];
int main(){
	cin>>n>>q;
	for (int i=1;i<=n;i++)c.insert(i);
	for (int i=1;i<=q;i++){
		scanf("%d",&opt[i]);
		if (opt[i]==0){
			scanf("%d%d%d",&l[i],&r[i],&x[i]);
			if (x[i]==0){
				it=c.lower_bound(l[i]);
				while(it!=c.end()){
					if ((*it)>r[i])break;
					a[*it]=i;
					_it=it;
					it++;
					c.erase(_it);
				}
			}
		}
		if (opt[i]==1)scanf("%d",&x[i]);
	}
	build(1,1,n);
	for (int i=1;i<=n;i++){
		cnt[i]=cnt[i-1];
		if (a[i]==0)cnt[i]++;
	}
	memset(qwq,0x7f,sizeof(qwq));
	for (int i=1;i<=q;i++){
		if (opt[i]==0){
			if (x[i]==1){
				if (gs(l[i],r[i])==1){
					int pos=(*c.lower_bound(l[i]));
					qwq[pos]=min(qwq[pos],ask(1,1,n,l[i],r[i]));
				}
			}
		}
		if (opt[i]==1){
			if (a[x[i]]==0){
				if (qwq[x[i]]<=i)puts("YES");
				else puts("N/A");
			}
			else{
				if (a[x[i]]<=i)puts("NO");
				else puts("N/A");
			}
		}
	}
	return 0;
}