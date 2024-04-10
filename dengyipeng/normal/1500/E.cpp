#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 400005
#define ll long long 
using namespace std;

int n,q,i,j,k,tp[maxn],s0[maxn],a0[maxn],tot,cnt;
ll s[maxn],a[maxn],v[maxn];

struct arr{int i,t; ll x;} A[maxn];
int cmp(arr a,arr b){return a.x<b.x;}

ll read(){
	ll x=0; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int t[maxn*4]; ll ts[maxn*4],tf[maxn*4],tg[maxn*4];
void change(int x,int l,int r,int p){
	if (l==r) {t[x]^=1,ts[x]=v[l]*t[x],tf[x]=tg[x]=ts[x];return;}
	int mid=(l+r)>>1;
	if (p<=mid) change(x<<1,l,mid,p);
	else change(x<<1^1,mid+1,r,p);
	t[x]=t[x<<1]+t[x<<1^1],ts[x]=ts[x<<1]+ts[x<<1^1];
	tf[x]=tf[x<<1]+tf[x<<1^1]+ts[x<<1]*t[x<<1^1];
	tg[x]=tg[x<<1]+tg[x<<1^1]+ts[x<<1^1]*t[x<<1];
}
ll fsum(int x,int l,int r,int c){
	if (!c) return 0;
	if (t[x]==c) return ts[x];
	int mid=(l+r)>>1;
	if (t[x<<1]>=c) return fsum(x<<1,l,mid,c);
	else return ts[x<<1]+fsum(x<<1^1,mid+1,r,c-t[x<<1]);
}
ll gsum(int x,int l,int r,int c){
	if (!c) return 0;
	if (t[x]==c) return ts[x];
	int mid=(l+r)>>1;
	if (t[x<<1^1]>=c) return gsum(x<<1^1,mid+1,r,c);
	else return ts[x<<1^1]+gsum(x<<1,l,mid,c-t[x<<1^1]);
}
ll Fsum(int x,int l,int r,int c){
	if (!c) return 0;
	if (t[x]==c) return tf[x];
	int mid=(l+r)>>1;
	if (t[x<<1]>=c) return Fsum(x<<1,l,mid,c);
	else return tf[x<<1]+ts[x<<1]*(c-t[x<<1])+Fsum(x<<1^1,mid+1,r,c-t[x<<1]);
}
ll Fsum0(int l,int r){return Fsum(1,1,cnt,r)-Fsum(1,1,cnt,l-1);}
ll Gsum(int x,int l,int r,int c){
	if (!c) return 0;
	if (t[x]==c) return tg[x];
	int mid=(l+r)>>1;
	if (t[x<<1^1]>=c) return Gsum(x<<1^1,mid+1,r,c);
	else return tg[x<<1^1]+ts[x<<1^1]*(c-t[x<<1^1])+Gsum(x<<1,l,mid,c-t[x<<1^1]);
}
ll Gsum0(int l,int r){return Gsum(1,1,cnt,r)-Gsum(1,1,cnt,l-1);}
void doit(){
	int n=t[1],m=(n+1)/2;
	if (!n) {printf("0\n");return;}
	int l=1,r=m,mid,k=m+1;
	while (l<=r){
		mid=(l+r)>>1;
		if (fsum(1,1,cnt,mid)<gsum(1,1,cnt,mid-1))
			r=mid-1,k=mid;
		else l=mid+1;
	}
	ll ans=0;
	if (k==m+1)
		ans=Gsum0(1,n)-Fsum0(1,n);
	else {
		if (k-2){
			ans+=Gsum0(1,k-2)-Fsum0(1,k-2);
			ans+=Gsum0(n-k+2,n)-Fsum0(n-k+2,n);
		}
		ans+=gsum(1,1,cnt,n-k+1)-fsum(1,1,cnt,k-1);
	}
	printf("%lld\n",ans);
}

int main(){
	n=read(),q=read();
	for(i=1;i<=n;i++) s[i]=read(),tot++,A[tot].x=s[i],A[tot].i=i,A[tot].t=1;
	for(i=1;i<=q;i++) tp[i]=read(),a[i]=read(),tot++,A[tot].x=a[i],A[tot].i=i,A[tot].t=2;
	sort(A+1,A+1+tot,cmp);
	for(i=1;i<=tot;i++){
		if (i==1||A[i].x!=A[i-1].x) cnt++,v[cnt]=A[i].x;
		if (A[i].t==1) s0[A[i].i]=cnt;
		else a0[A[i].i]=cnt;
	}
	for(i=1;i<=n;i++) 
		change(1,1,cnt,s0[i]);
	doit();
	for(i=1;i<=q;i++) change(1,1,cnt,a0[i]),doit();
}