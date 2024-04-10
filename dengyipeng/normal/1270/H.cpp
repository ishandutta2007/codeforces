#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 1000005
#define min(a,b) ((a<b)?a:b)
#define max(a,b) ((a>b)?a:b)
using namespace std;

int n,q,i,j,k,m,a[maxn],que[maxn][2];
int t[maxn*4],tm[maxn*4],tag[maxn*4];
struct arr{int x,tp,i;} A[maxn];
int cmp(arr a,arr b){return a.x<b.x;}

void read(int &x){
	x=0; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
}

void init(){
	read(n),read(q),m=n+q;
	for(i=1;i<=n;i++) read(a[i]),A[i].x=a[i],A[i].tp=1;
	for(i=1;i<=q;i++) read(que[i][0]),read(que[i][1]),A[n+i].x=que[i][1],A[n+i].tp=2;
	for(i=1;i<=m;i++) A[i].i=i;
	sort(A+1,A+1+m,cmp);
	for(i=1;i<=m;i++){
		if (A[i].tp==1) a[A[i].i]=i;
		else que[A[i].i-n][1]=i;
	}	
}

void upd(int x){
	int l=x<<1,r=x<<1^1;
	if (!tm[l]) {t[x]=t[r],tm[x]=tm[r];return;}
	if (!tm[r]) {t[x]=t[l],tm[x]=tm[l];return;}
	t[x]=min(t[l],t[r]),tm[x]=0;
	if (t[x]==t[l]) tm[x]+=tm[l];
	if (t[x]==t[r]) tm[x]+=tm[r];
}

void downtag(int x,int l,int r){
	t[x]+=tag[x];
	if (l<r) tag[x<<1]+=tag[x],tag[x<<1^1]+=tag[x];
	tag[x]=0;
}

void add(int x,int l,int r,int ll,int rr,int d){
	if (tag[x]) downtag(x,l,r);
	if (l>rr||r<ll) return;
	if (ll<=l&&r<=rr) {tag[x]+=d,downtag(x,l,r);return;}
	int mid=(l+r)>>1;
	add(x<<1,l,mid,ll,rr,d);
	add(x<<1^1,mid+1,r,ll,rr,d);
	upd(x);
}

void change(int x,int l,int r,int p){
	if (tag[x]) downtag(x,l,r);
	if (l==r) {tm[x]^=1;return;}
	int mid=(l+r)>>1;
	if (p<=mid) change(x<<1,l,mid,p); 
	else change(x<<1^1,mid+1,r,p);
	downtag(x<<1,l,mid),downtag(x<<1^1,mid+1,r);
	upd(x);
}

void prepare(){
	for(i=1;i<=n;i++) 
		change(1,1,m,a[i]);
	a[0]=m+1,a[n+1]=0;
	for(i=1;i<=n+1;i++)
		add(1,1,m,min(a[i],a[i-1])+1,max(a[i],a[i-1]),1);
}

void Consider(int a,int b,int c){
	if (max(a,b)+1<=c) add(1,1,m,max(a,b)+1,c,1);
	if (c+1<=min(a,b)) add(1,1,m,c+1,min(a,b),1);
	if (max(a,c)+1<=b) add(1,1,m,max(a,c)+1,b,-1);
	if (b+1<=min(a,c)) add(1,1,m,b+1,min(a,c),-1);
}

void Doit(){
	for(int now=1;now<=q;now++){
		int pos=que[now][0];
		change(1,1,m,a[pos]);
		change(1,1,m,que[now][1]);
		Consider(a[pos-1],a[pos],que[now][1]);
		Consider(a[pos+1],a[pos],que[now][1]);
		printf("%d\n",(t[1]==1)?tm[1]:0),a[pos]=que[now][1];
	}
}

int main(){
	init();
	prepare();
	Doit();
}