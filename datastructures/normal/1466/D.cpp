#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;
struct node{
	int val,cnt;
	bool operator <(const node &x)const{
		return val>x.val;
	}
}a[200005];
int t,n,w[200005],u[200005],v[200005],first[200005],nxt[200005];
int sum;
void dfs(int now,int fa){
	int du=0;
	for (int i=first[now];i;i=nxt[i]){
		du++;
		if (v[i]==fa)continue;
		dfs(v[i],now);
	}
	sum+=w[now];
	a[now].val=w[now],a[now].cnt=du-1;
	return;
}
signed main(){
	cin>>t;
	while(t--){
		scanf("%lld",&n);
		for (int i=1;i<=n;i++)scanf("%lld",&w[i]);
		for (int i=1;i<n;i++){
			scanf("%lld%lld",&u[i],&v[i]);
			nxt[i]=first[u[i]],first[u[i]]=i;
			u[i+n]=v[i],v[i+n]=u[i];
			nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
		}
		sum=0;
		dfs(1,0);
		sort(a+1,a+1+n);
		int p=1;
		printf("%lld ",sum);
		for (int i=2;i<n;i++){
			while(p<=n&&a[p].cnt==0)p++;
			if (p<=n){
				sum+=a[p].val;
				a[p].cnt--;
			}
			printf("%lld ",sum);
		}
		printf("\n");
		for (int i=1;i<=2*n;i++)u[i]=v[i]=first[i]=nxt[i]=0;
	}
	return 0;
}