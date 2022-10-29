#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 100005
#define ll long long 
using namespace std;

int n,i,j,k,a[maxn];
struct node{
	int s[2],fa;
	ll tagk,tagb,f,id,tagc;
} t[maxn];

int get(int x){return t[t[x].fa].s[1]==x;}
void comb(int x,int y){
	t[x].tagk+=t[y].tagk;
	t[x].tagb+=t[y].tagb+t[y].tagk*t[x].tagc;
	t[x].tagc+=t[y].tagc;
}

void downtag(int x){
	if (!t[x].tagk&&!t[x].tagb&&!t[x].tagc) return;
	t[x].f+=t[x].tagk*t[x].id+t[x].tagb;
	t[x].id+=t[x].tagc;
	if (t[x].s[0]) comb(t[x].s[0],x);
	if (t[x].s[1]) comb(t[x].s[1],x);
	t[x].tagk=t[x].tagb=t[x].tagc=0;
}

void remove(int x,int y){
	static int d[maxn];
	while (x!=y) d[++d[0]]=x,x=t[x].fa;d[++d[0]]=y;
	while (d[0]) downtag(d[d[0]--]);
}

void rotate(int x){
	int y=t[x].fa,c=get(x);
	t[y].s[c]=t[x].s[c^1];
	if (t[y].s[c]) t[t[y].s[c]].fa=y;
	if (y) t[t[y].fa].s[get(y)]=x;
	t[x].fa=t[y].fa,t[y].fa=x,t[x].s[c^1]=y;
}

void splay(int x,int y){
	remove(x,y);
	while (t[x].fa!=y){
		int z=t[x].fa;
		if (t[z].fa!=y){
			if (get(z)==get(x)) rotate(z);
			else rotate(x);
		}
		rotate(x);
	}
}

int find(int x,int i){
	downtag(x);
	if (t[x].id==i) return x;
	if (t[x].id<i) return find(t[x].s[1],i);
	else return find(t[x].s[0],i);
}

ll getv(int k){
	int x=find(0,k); splay(x,0);
	return t[x].f;
}

ll getans(int x){
	downtag(x);ll ans=0;
	if (x) ans=max(ans,t[x].f);
	if (t[x].s[0]) ans=max(ans,getans(t[x].s[0]));
//	if (x) printf("%lld ",t[x].f);
	if (t[x].s[1]) ans=max(ans,getans(t[x].s[1]));
	return ans;
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	t[1].id=0,t[1].fa=0,t[0].s[1]=1,t[0].id=-1;
	for(i=1;i<=n;i++){
		int l=0,r=i-2,mid,mi=i-1;
		while (l<=r){
			mid=(l+r)>>1;
			if (getv(mid)+1ll*(mid+1)*a[i]>=getv(mid+1))
				mi=mid,r=mid-1; 
			else l=mid+1;
		}
		if (mi==i-1){
			k=find(0,i-1),splay(k,0);
			t[k].s[1]=i+1,t[i+1].fa=k;
			t[i+1].f=t[k].f+(t[k].id+1)*a[i];
			t[i+1].id=i;
		} else {
			k=find(0,mi),splay(k,0);
			j=find(0,mi+1),splay(j,k);
			t[j].s[0]=i+1,t[i+1].fa=j;
			t[i+1].f=t[k].f+(t[k].id+1)*a[i],t[i+1].id=mi+1;
			splay(i+1,0),k=t[i+1].s[1];
			downtag(k);
			t[k].tagk=a[i],t[k].tagb=a[i],t[k].tagc=1;
		}
//		getans(0);printf("\n");
//		printf("%lld\n",getans(0));
	}
	printf("%lld",getans(0));
}