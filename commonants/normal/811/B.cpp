#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;
typedef long long LL;
const int MX=20011;
int n,m;
int a[MX],L[MX],R[MX];
struct Node{
	int s;Node *lt,*rt;
}pool[2001111],*nn=pool,*rot[MX];

Node *add(Node *f,int l,int r,int x){
	Node *t=nn++;*t=*f;
	if(l==r)t->s++;
	else{
		int mid=(l+r)>>1;
		if(x<=mid)t->lt=add(f->lt,l,mid,x);
		else t->rt=add(f->rt,mid+1,r,x);
		t->s=t->lt->s+t->rt->s;
	}
	return t;
}
int que(Node *t,int l,int r,int ll,int rr){
	if(ll<=l&&rr>=r)return t->s;
	else{
		int mid=(l+r)>>1,ans=0;
		if(ll<=mid)ans+=que(t->lt,l,mid,ll,rr);
		if(rr>mid)ans+=que(t->rt,mid+1,r,ll,rr);
		return ans;
	}
}
#define Q(l,r,ll,rr) (que(rot[r],1,n,ll,rr)-que(rot[l-1],1,n,ll,rr))
int main(){
	rot[0]=nn++;rot[0]->lt=rot[0]->rt=rot[0];rot[0]->s=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)rot[i]=add(rot[i-1],1,n,a[i]);
	for(int i=1;i<=m;i++){
		int l,r,x;scanf("%d%d%d",&l,&r,&x);
		//printf("%d %d\n",Q(l,r,1,a[x]),x-l+1);
		puts(Q(l,r,1,a[x])==x-l+1?"Yes":"No");
	}
	return 0;
}