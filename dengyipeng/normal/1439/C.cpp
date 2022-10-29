#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
#define maxn 200005
using namespace std;

int n,q,i,j,k,a[maxn];

int t[maxn*4],mi[maxn*4];
void maketree(int x,int l,int r){
	if (l==r) {t[x]=mi[x]=a[l];return;}
	int mid=(l+r)>>1;
	maketree(x<<1,l,mid);
	maketree(x<<1^1,mid+1,r);
	if (t[x<<1]&&t[x<<1]==t[x<<1^1]) t[x]=t[x<<1];
	mi[x]=min(mi[x<<1],mi[x<<1^1]);
}

void change(int x,int l,int r,int L,int R,int v){
	if (l>R||r<L||mi[x]>=v) return;
	if (t[x]) {
		if (L<=l&&r<=R){
			t[x]=mi[x]=v;return;
		} else {
			t[x<<1]=t[x],t[x<<1^1]=t[x],t[x]=0;
			mi[x<<1]=mi[x],mi[x<<1^1]=mi[x];
		}
	}
	int mid=(l+r)>>1;
	change(x<<1,l,mid,L,R,v);
	change(x<<1^1,mid+1,r,L,R,v);
	if (t[x<<1]&&t[x<<1]==t[x<<1^1]) t[x]=t[x<<1];
	mi[x]=min(mi[x<<1],mi[x<<1^1]);
}

int ans,res;
void find(int x,int l,int r,int L,int R){
	if (l>R||r<L||mi[x]>res) return;
	if (t[x]) {
		int k=min(min(R,r)-max(L,l)+1,res/t[x]);
		ans+=k,res-=k*t[x];
		return;
	}
	int mid=(l+r)>>1;
	find(x<<1,l,mid,L,R),find(x<<1^1,mid+1,r,L,R);
}

int main(){
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	maketree(1,1,n);
	while (q--){
		int tp,x,y; scanf("%d%d%d",&tp,&x,&y);
		if (tp==1) change(1,1,n,1,x,y); 
		else {
			res=y;
			ans=0,find(1,1,n,x,n);
			printf("%d\n",ans);
		}
	}
}