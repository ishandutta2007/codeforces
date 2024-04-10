#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring> 
#include <algorithm>
#define int long long
using namespace std; 
struct BIT{
	int tree[1000005],maxn;
	BIT(){
		memset(tree,0,sizeof(tree));
		maxn=1000000;
		return;
	}
	inline int lowbit(int x){
		return x&(-x);
	}
	inline void add(int pos,int val){
		while(pos<=maxn)tree[pos]+=val,pos+=lowbit(pos);
		return;
	}
	inline int ask(int pos){
		int ans=0;
		while(pos)ans+=tree[pos],pos-=lowbit(pos);
		return ans;
	}
}bit;
struct node{
	int id,t;
}a[100005];
bool cmp(node a,node b){
	if (a.t!=b.t)return a.t<b.t;
	return a.id<b.id;
}
int n,p;
priority_queue <int>h;
int now=1,nowt,head=1,tail=0,q[100005];
int tot=0,ans[100005];
signed main(){
	cin>>n>>p;
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i].t);
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	while(tot<n){
		if (!h.empty()){
			int nowid=-h.top();
			if (bit.ask(nowid)==0){
				q[++tail]=nowid;
				bit.add(nowid,1);
				h.pop();
			}
		}
		if (head>tail){
			nowt=a[now].t;
			q[++tail]=a[now].id;
			now++;
			bit.add(q[tail],1);
		} 
		while(a[now].t<=nowt+p&&now<=n){
			if (bit.ask(a[now].id)==0){
				q[++tail]=a[now].id;
				bit.add(a[now].id,1);
			}
			else h.push(-a[now].id);
			++now;
		}
		nowt+=p;
		ans[q[head]]=nowt;
		++tot;
		bit.add(q[head],-1);
		head++;
	}
	for (int i=1;i<=n;i++)
		printf("%lld ",ans[i]);
	cout<<endl;
	return 0;
}