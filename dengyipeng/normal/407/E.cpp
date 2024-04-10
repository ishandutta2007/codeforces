#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#define maxn 200005
#define LL long long 
using namespace std;

int n,K,i,j,k,ansl,ansr,nex[maxn],las[maxn],d0[maxn],d1[maxn];
LL a[maxn],mx,mi,d,t[maxn*4],tag[maxn*4];
map<LL,LL> s;

void Doit0(){
	k=1,ansr=ansl=1;
	for(i=1;i<=n;i++){
		if (a[i]!=a[i-1]){
			if (i-k-1>ansr-ansl)
				ansl=k,ansr=i-1;
			k=i;
		}
	}
	if (n-k>ansr-ansl) ansl=k,ansr=n;
	printf("%d %d\n",ansl,ansr);
	exit(0);
}

void Prepare(){
	las[n+1]=n+1;
	for(i=n;i>=1;i--){
		if (s[a[i]]) nex[i]=s[a[i]]; else nex[i]=n+1;
		s[a[i]]=i,las[i]=min(las[i+1],nex[i]-1);
		if (i<n&&(a[i]%d+d)%d!=(a[i+1]%d+d)%d) las[i]=i;
	}
}

void downtag(int x,int l,int r){
	t[x]+=tag[x];
	if (l<r) tag[x<<1]+=tag[x],tag[x<<1^1]+=tag[x];
	tag[x]=0;
}

void cover(int x,int l,int r,int ll,int rr){
	if (tag[x]) downtag(x,l,r);
	if (r<ll||l>rr) return;
	if (ll<=l&&r<=rr) t[x]=tag[x]=0;
	if (l==r) return;
	int mid=(l+r)>>1;
	cover(x<<1,l,mid,ll,rr),cover(x<<1^1,mid+1,r,ll,rr);
	t[x]=max(t[x<<1],t[x<<1^1]);
}

void change(int x,int l,int r,int ll,int rr,LL d){
	if (ll>rr) return;
	if (tag[x]) downtag(x,l,r);
	if (r<ll||l>rr) return;
	if (ll<=l&&r<=rr) {tag[x]+=d,downtag(x,l,r);return;}
	int mid=(l+r)>>1;
	change(x<<1,l,mid,ll,rr,d);
	change(x<<1^1,mid+1,r,ll,rr,d);
	t[x]=max(t[x<<1],t[x<<1^1]);
}

int find(int x,int l,int r,int lim){
	if (tag[x]) downtag(x,l,r);
	if (l==r) return l;
	int mid=(l+r)>>1;
	if (t[x<<1^1]+tag[x<<1^1]>=lim) 
		return find(x<<1^1,mid+1,r,lim);
	else 
		return find(x<<1,l,mid,lim);
}

int main(){
	scanf("%d%d%lld",&n,&K,&d);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	if (d==0) Doit0();
	Prepare();
	for(i=n;i>=1;i--){
		if (las[i]<las[i+1])
			cover(1,1,n,las[i]+1,las[i+1]);
		while (d0[0]&&a[i]<=a[d0[d0[0]]]){
			change(1,1,n,d0[d0[0]],min(las[i],(d0[0]==1)?las[i]:d0[d0[0]-1]-1),
				(a[i]-a[d0[d0[0]]])/d);
			d0[0]--;
		}
		d0[++d0[0]]=i;
		while (d1[0]&&a[i]>=a[d1[d1[0]]]){
			change(1,1,n,d1[d1[0]],min(las[i],(d1[0]==1)?las[i]:d1[d1[0]-1]-1),
				(a[d1[d1[0]]]-a[i])/d);
			d1[0]--;
		}
		d1[++d1[0]]=i;
		change(1,1,n,i,i,i+K);
		k=find(1,1,n,i);
		if (k-i>=ansr-ansl) ansl=i,ansr=k;
	}
	printf("%d %d\n",ansl,ansr);
}