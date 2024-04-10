#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 50005
#define ll long long 
using namespace std;

int n,m,i,j,k,mo;
ll s[maxn],K,now,nows;
struct arr{ll v,i;} a[maxn];
int cmp(arr a,arr b){return a.i<b.i;}
struct mat{
	ll a[2][2];
	mat(ll s1=0,ll s2=0){a[0][0]=s1,a[0][1]=1,a[1][0]=s2,a[1][1]=0;}
	void clear(){memset(a,0,sizeof(a));}
} t[maxn*4],f;
mat operator*(mat a,mat b){
	mat c; c.clear();
	for(int i=0;i<2;i++) for(int j=0;j<2;j++) for(int k=0;k<2;k++)
		(c.a[i][k]+=a.a[i][j]*b.a[j][k])%=mo;
	return c;
}

void maketree(int x,int l,int r){
	if (l==r) {
		t[x].clear(),t[x].a[0][0]=t[x].a[1][1]=1;return;
	}
	int mid=(l+r)>>1;
	maketree(x<<1,l,mid),maketree(x<<1^1,mid+1,r);
	t[x]=t[x<<1]*mat(s[mid+1],s[mid])*t[x<<1^1];
}

void find(int x,int l,int r,int L,int R){
	if (l>R||r<L) return;
	if (L<=l&&r<=R){
		f=f*mat(s[l],nows),f=f*t[x];
		now+=r-l+1,nows=s[r];
		return;
	}
	int mid=(l+r)>>1;
	find(x<<1,l,mid,L,R),find(x<<1^1,mid+1,r,L,R);
}

mat ksm(ll x){
	now+=x*n; mat g=t[1];
	for(;x;x/=2,g=g*mat(s[0],s[n-1])*g) if (x&1)
	 	f=f*mat(s[0],nows)*g,nows=s[n-1];
	return f;
}

int main(){
	scanf("%lld%d%d",&K,&mo,&n);
	for(i=0;i<n;i++) scanf("%lld",&s[i]);
	maketree(1,0,n-1);
	scanf("%d",&m);
	for(i=1;i<=m;i++) scanf("%lld%lld",&a[i].i,&a[i].v); 
	if (K==0) {printf("0");return 0;}
	m++,a[m].i=K,a[m].v=0;
	sort(a+1,a+1+m,cmp);
	f.clear(),f.a[0][0]=f.a[1][1]=1,now=0,nows=s[now];
	for(i=1;i<=m&&a[i].i<=K;i++){
		if (now/n==a[i].i/n){
			find(1,0,n-1,(now+1)%n,(a[i].i-1)%n);
			if (a[i].i<K) 
				f=f*mat(a[i].v,nows),now=a[i].i,nows=a[i].v;
			else break;
		} else {
			if (now%n<n-1) find(1,0,n-1,(now+1)%n,n-1);
			if (a[i].i/n-now/n-1) ksm(a[i].i/n-now/n-1);
			if (now+1<a[i].i) find(1,0,n-1,0,(a[i].i-1)%n);
			if (a[i].i<K){
				f=f*mat(a[i].v,nows);
				now=a[i].i,nows=a[i].v;
			} else break;
		}
	}
	printf("%lld",f.a[0][0]%mo);
}