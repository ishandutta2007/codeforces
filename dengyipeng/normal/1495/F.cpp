#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<set>
#define maxn 200005
#define ll long long
using namespace std;

int n,q,i,j,k,p[maxn],que[maxn],tot,d[maxn];
ll a[maxn],b[maxn];
set<int> S;
set<int> ::iterator it,it1;


struct arr{int x,y,i;} A[maxn*3];
int cmp(arr a,arr b){return a.x>b.x;}
ll ans[maxn*3],t[maxn*4],tag[maxn*4];

void downtag(int x,int l,int r){
	t[x]+=tag[x];
	if (l<r) tag[x<<1]+=tag[x],tag[x<<1^1]+=tag[x];
	tag[x]=0;
}
void add(int x,int l,int r,int L,int R,ll d){
	if (tag[x]) downtag(x,l,r);
	if (l>R||r<L) return;
	if (L<=l&&r<=R){tag[x]+=d,downtag(x,l,r);return;}
	int mid=(l+r)>>1;
	add(x<<1,l,mid,L,R,d),add(x<<1^1,mid+1,r,L,R,d);
	t[x]=min(t[x<<1],t[x<<1^1]);
}
ll find(int x,int l,int r,int p){
	if (tag[x]) downtag(x,l,r);
	if (l==r) return t[x];
	int mid=(l+r)>>1;
	if (p<=mid) return find(x<<1,l,mid,p); 
	else return find(x<<1^1,mid+1,r,p);
}

int main(){
	scanf("%d%d",&n,&q),p[n+1]=n+1;
	for(i=1;i<=n;i++) scanf("%d",&p[i]);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(i=1;i<=n;i++) scanf("%lld",&b[i]);
	S.insert(1),S.insert(n+1);
	for(i=1;i<=q;i++){
		scanf("%d",&que[i]); int x=que[i];
		if (x!=1){
			it=S.lower_bound(x);
			if ((*it)!=x){
				it1=it,it1--;
				tot++,A[tot].x=x,A[tot].y=*it,A[tot].i=tot;
				tot++,A[tot].x=*it1,A[tot].y=x,A[tot].i=tot;
				tot++,A[tot].x=*it1,A[tot].y=*it,A[tot].i=tot;
				S.insert(x);
			} else {
				S.erase(x),it=S.lower_bound(x);
				it1=it,it1--;
				tot++,A[tot].x=x,A[tot].y=*it,A[tot].i=tot;
				tot++,A[tot].x=*it1,A[tot].y=x,A[tot].i=tot;
				tot++,A[tot].x=*it1,A[tot].y=*it,A[tot].i=tot;
			}
		}
	}
	sort(A+1,A+1+tot,cmp);
	d[1]=n+1; int w=1,now=1;
	for(i=n;i>=1;i--){
		while (p[d[w]]<p[i]) w--;
		ll v=find(1,1,n+1,d[w]);
		add(1,1,n+1,i+1,n+1,a[i]);
		if (b[i]<v+a[i])
			add(1,1,n+1,d[w],n+1,b[i]-v-a[i]);
		while (now<=tot&&A[now].x==i){
			ans[A[now].i]=find(1,1,n+1,A[now].y);
			now++;
		}
		d[++w]=i;
	}
	S.clear(),S.insert(1),S.insert(n+1);
	ll sum=find(1,1,n+1,n+1); now=0;
	for(i=1;i<=q;i++){
		int x=que[i];
		if (x!=1){
			ll v1=ans[++now],v2=ans[++now],v3=ans[++now];
			it=S.lower_bound(x);
			if ((*it)!=x) {
				S.insert(x); 
				sum+=v1+v2-v3;
			} else {
				S.erase(x);
				sum+=v3-v1-v2;
			}
		}
		printf("%lld\n",sum);
	}

}