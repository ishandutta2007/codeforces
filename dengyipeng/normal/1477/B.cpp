#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define maxn 200005
using namespace std;

int T,n,q,i,j,k,ss[maxn],tt[maxn],l[maxn],r[maxn];
int t[maxn*4],tag[maxn*4];

void maketree(int x,int l,int r){
	tag[x]=-1; if (l==r){t[x]=tt[l];return;}
	int mid=(l+r)>>1;
	maketree(x<<1,l,mid),maketree(x<<1^1,mid+1,r);
	t[x]=t[x<<1]+t[x<<1^1];
}

void downtag(int x,int l,int r){
	t[x]=tag[x]*(r-l+1);
	if (l<r) tag[x<<1]=tag[x],tag[x<<1^1]=tag[x];
	tag[x]=-1;
}

int find(int x,int l,int r,int L,int R){
	if (tag[x]!=-1) downtag(x,l,r);
	if (l>R||r<L) return 0;
	if (L<=l&&r<=R) return t[x];
	int mid=(l+r)>>1;
	return find(x<<1,l,mid,L,R)+find(x<<1^1,mid+1,r,L,R);
}

void change(int x,int l,int r,int L,int R,int v){
	if (tag[x]!=-1) downtag(x,l,r);
	if (l>R||r<L) return;
	if (L<=l&&r<=R) {tag[x]=v,downtag(x,l,r);return;}
	int mid=(l+r)>>1;
	change(x<<1,l,mid,L,R,v),change(x<<1^1,mid+1,r,L,R,v);
	t[x]=t[x<<1]+t[x<<1^1];
}

int check(int x,int l,int r){
	if (tag[x]!=-1) downtag(x,l,r);
	if (l==r) return t[x]==ss[l];
	int mid=(l+r)>>1;
	return check(x<<1,l,mid)&check(x<<1^1,mid+1,r);
}

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&q); char ch=getchar();
		while (ch!='0'&&ch!='1') ch=getchar();
		for(i=1;i<=n;i++) ss[i]=ch-'0',ch=getchar();
		while (ch!='0'&&ch!='1') ch=getchar();
		for(i=1;i<=n;i++) tt[i]=ch-'0',ch=getchar();
		for(i=1;i<=q;i++) scanf("%d%d",&l[i],&r[i]);
		maketree(1,1,n);
		int tp=1;
		for(i=q;i>=1;i--){
			int cnt=find(1,1,n,l[i],r[i]);
			if (cnt*2==r[i]-l[i]+1) {tp=0;break;}
			if (cnt>r[i]-l[i]+1-cnt) change(1,1,n,l[i],r[i],1);
			else change(1,1,n,l[i],r[i],0);
		}
		tp&=check(1,1,n);
		if (tp) printf("YES\n"); else printf("NO\n");
	}
}