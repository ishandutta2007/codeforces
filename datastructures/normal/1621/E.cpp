#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#define int long long
using namespace std;
int read(){
	int x=0,fg=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if (ch=='-')fg=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int tree[1200005],tag[1200005];
void pushup(int now){
	tree[now]=min(tree[now*2],tree[now*2+1]);
	return;
}
void pushdown(int now){
	tree[now*2]+=tag[now],tree[now*2+1]+=tag[now];
	tag[now*2]+=tag[now],tag[now*2+1]+=tag[now];
	tag[now]=0;
	return;
}
void update(int now,int nowl,int nowr,int lt,int rt,int val){
	if (nowl!=nowr)pushdown(now);
	if (nowl>=lt&&nowr<=rt){
		tree[now]+=val;
		tag[now]+=val;
		return;
	}
	int mid=(nowl+nowr)/2;
	if (mid>=lt)update(now*2,nowl,mid,lt,rt,val);
	if (mid+1<=rt)update(now*2+1,mid+1,nowr,lt,rt,val);
	pushup(now);
	return;
}
int t,n,m,a[200005];
int tot,k[200005],c[200005],sum[200005];
int getpos(int id){
	int x=(sum[id]+k[id]-1)/k[id];
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (a[mid]>=x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
int ovo;
void upd(int i,int val){
	int pos=getpos(i);
	if (pos==0)ovo+=val;
	else update(1,1,n,pos,n,val);
	return;
}
signed main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		for (int i=1;i<=n;i++)a[i]=read();
		tot=0;
		for (int i=1;i<=m;i++){
			k[i]=read();
			for (int j=tot+1;j<=tot+k[i];j++){
				c[j]=read();
				sum[i]+=c[j];
			}
			tot+=k[i];
		}
		sort(a+1,a+1+n);
		reverse(a+1,a+1+n);
		for (int i=1;i<=n;i++)update(1,1,n,i,i,i);
		for (int i=1;i<=m;i++)upd(i,-1);
		int awa=0;
		for (int i=1;i<=m;i++){
			for (int j=awa+1;j<=awa+k[i];j++){
				upd(i,1);
				k[i]--;
				sum[i]-=c[j];
				upd(i,-1);
				if (min(tree[1],ovo)<0)putchar('0');
				else putchar('1');
				upd(i,1);
				sum[i]+=c[j];
				k[i]++;
				upd(i,-1);
			}
			awa+=k[i];
		}
		puts("");
		for (int i=1;i<=m;i++)k[i]=sum[i]=0;
		for (int i=0;i<=4*n;i++)tree[i]=tag[i]=0;
		ovo=0;
	}
	return 0;
}