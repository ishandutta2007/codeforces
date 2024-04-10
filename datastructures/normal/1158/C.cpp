#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <ctime>
#include <random>
#define inf 1000000000
using namespace std;
int t,n,a[500005];
vector<int> c[500005];
int tree[2000005],tag[2000005];
int q[500005],head,tail,ans[500005],cnt;
void pushdown(int now){
	tree[now*2]+=tag[now],tree[now*2+1]+=tag[now];
	tag[now*2]+=tag[now],tag[now*2+1]+=tag[now];
	tag[now]=0;
	return;
}
void pushup(int now){
	tree[now]=min(tree[now*2],tree[now*2+1]);
	return;
}
void add(int now,int nowl,int nowr,int lt,int rt,int val){
	if (nowl!=nowr)pushdown(now);
	if (nowl>=lt&&nowr<=rt){
		tree[now]+=val;
		tag[now]+=val;
		return;
	}
	int mid=(nowl+nowr)/2;
	if (mid>=lt)add(now*2,nowl,mid,lt,rt,val);
	if (mid+1<=rt)add(now*2+1,mid+1,nowr,lt,rt,val);
	pushup(now);
	return;
}
int ask(int now,int nowl,int nowr){
	if (nowl!=nowr)pushdown(now);
	if (tree[now]>0)return -1;
	if (nowl==nowr)return nowl;
	int mid=(nowl+nowr)/2;
	if (tree[now*2]==0)return ask(now*2,nowl,mid);
	return ask(now*2+1,mid+1,nowr);
}
void mem(int now,int nowl,int nowr){
	tree[now]=tag[now]=0;
	if (nowl==nowr)return;
	int mid=(nowl+nowr)/2;
	mem(now*2,nowl,mid);
	mem(now*2+1,mid+1,nowr);
	return;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		for (int i=1;i<=n;i++){
			if (a[i]!=-1&&a[i]>i+1)add(1,1,n,i+1,a[i]-1,1);
			if (a[i]!=-1&&a[i]<=n)c[a[i]].push_back(i),add(1,1,n,i,i,1);
		}
		int qwq=ask(1,1,n);
		head=1,tail=0,cnt=0;
		if (qwq!=-1)q[++tail]=qwq;
		while(head<=tail){
			int now=q[head];
			head++;
			++cnt;
			ans[now]=n-cnt+1;
			add(1,1,n,now,now,inf);
			if (a[now]!=-1&&a[now]>now+1)add(1,1,n,now+1,a[now]-1,-1);
			for (int i=0,len=c[now].size();i<len;i++)
				add(1,1,n,c[now][i],c[now][i],-1);
			qwq=ask(1,1,n);
			if (qwq!=-1)q[++tail]=qwq;
		}
		if (cnt<n)puts("-1");
		else{
			for (int i=1;i<=n;i++)
				printf("%d ",ans[i]);
			puts("");
		}
		for (int i=1;i<=n;i++)c[i].clear();
		mem(1,1,n);
	}
	return 0;
}