#include<bits/stdc++.h>
#define getmx(p) (s[p].mx+s[p].tag)
using namespace std;
typedef long long ll;
const int N=500005;
const ll inf=0x3f3f3f3f3f3f3f3fll;
struct sgt{
	int ls,rs,l,r,mxp;
	ll tag,mx;
}s[3*N];
int rt,P;
void upd(int p){
	if(getmx(s[p].ls)>getmx(s[p].rs)){
		s[p].mxp=s[s[p].ls].mxp;
		s[p].mx=getmx(s[p].ls);
	}
	else{
		s[p].mxp=s[s[p].rs].mxp;
		s[p].mx=getmx(s[p].rs);
	}
}
int build(int l,int r){
	int p=++P;
	s[p].l=l;s[p].r=r;
	s[p].tag=s[p].mx=0;
	s[p].mxp=l;
	if(l==r) return p;
	int mid=(l+r)>>1;
	s[p].ls=build(l,mid);
	s[p].rs=build(mid+1,r);
	return p;
}
void pushd(int p){
	s[s[p].ls].tag+=s[p].tag;
	s[s[p].rs].tag+=s[p].tag;
	s[p].mx=getmx(p);
	s[p].tag=0;
}
void change(int p,int l,int r,ll x){
	if(l>r) return;
	if(s[p].l==l&&s[p].r==r){
		s[p].tag+=x;
		return;
	}
	pushd(p);
	int mid=(s[p].l+s[p].r)>>1;
	if(r<=mid) change(s[p].ls,l,r,x);
	else if(l>mid) change(s[p].rs,l,r,x);
	else{
		change(s[p].ls,l,mid,x);
		change(s[p].rs,mid+1,r,x);
	}
	upd(p);
}
pair<ll,int> query(int p,int l,int r){
	if(l==0) l=1;
	if(s[p].l==l&&s[p].r==r)
		return make_pair(getmx(p),s[p].mxp);
	pushd(p);
	int mid=(s[p].l+s[p].r)>>1;
	if(r<=mid) return query(s[p].ls,l,r);
	else if(l>mid) return query(s[p].rs,l,r);
	else return max(query(s[p].ls,l,mid),query(s[p].rs,mid+1,r));
}
ll x[N];
struct node{
	ll x,y,c;
	bool operator <(const node &b)const
	{
		return min(x,y)<min(b.x,b.y);
	}
}a[N];
int n,m;
int main(){
	srand((unsigned)time(NULL));
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%I64d%I64d%I64d",&a[i].x,&a[i].y,&a[i].c);
		x[i]=max(a[i].x,a[i].y);
	}
	sort(a+1,a+n+1);
	sort(x+1,x+n+1);
	int len=unique(x+1,x+n+1)-(x+1);
	int p1=len,p2=n;
	x[p1+1]=x[p1];
	rt=build(1,len);
	ll ans=0,a1,a2;
	a1=a2=rand()*32768+rand();
	a[0].x=-inf;x[0]=-inf;
	for(i=n;i;){
		while(x[p1]>=min(a[i].x,a[i].y)){
			change(rt,p1+1,len,x[p1]-x[p1+1]);
			p1--;
		}
		while(min(a[i].x,a[i].y)==min(a[p2].x,a[p2].y)){
			int loc=lower_bound(x+1,x+len+1,max(a[i].x,a[i].y))-x;
			change(rt,loc,len,a[i].c);
			i--;
		}
		pair<ll,int> q=query(rt,p1,len);
		q.first-=x[p1+1]-min(a[p2].x,a[p2].y);
		if(q.first>ans){
			ans=q.first;
			a1=min(a[p2].x,a[p2].y);
			a2=x[q.second];
		}
		p2=i;
	}
	cout<<ans<<endl;
	cout<<a1<<" "<<a1<<" "<<a2<<" "<<a2;
	return 0;
}