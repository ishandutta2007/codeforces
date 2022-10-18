#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int MX=100111;
int n,a[MX];
struct Node{
	Node *lt,*rt;int s;
}*null,pool[MX*70],*rot[MX<<1],*cnt=pool;
int lst[MX];
inline Node* New(Node *f){Node* t=cnt++;*t=*f;return t;}
Node* add(Node *f,int l,int r,int x,int d){
	Node *t=New(f);
	if(l==r)t->s+=d;
	else{
		int mid=(l+r)>>1;
		if(x<=mid)t->lt=add(f->lt,l,mid,x,d);
		else t->rt=add(f->rt,mid+1,r,x,d);
		t->s=t->lt->s+t->rt->s;
	}
	return t;
}
int fnd(Node*t,int l,int r,int k){
	if(l==r)return l;
	else{
		int mid=(l+r)>>1;
		if(t->rt->s>k)return fnd(t->rt,mid+1,r,k);
		else return fnd(t->lt,l,mid,k-t->rt->s);
	}
}
int main(){
	null=cnt++;null->lt=null->rt=null;null->s=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	rot[0]=null;
	for(int i=1;i<=n;i++)rot[i]=add((lst[a[i]]?add(rot[i-1],1,n,lst[a[i]],-1):rot[i-1]),1,n,i,1),lst[a[i]]=i;
	for(int i=1;i<=n;i++){
		int ans=0,rt=n;
		while(rt){
			ans++;
			rt=(rot[rt]->s<=i?0:fnd(rot[rt],1,n,i));
		}
		printf("%d ",ans);
	}
	return 0;
}