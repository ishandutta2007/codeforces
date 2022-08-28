#include<bits/stdc++.h>
#define fz1(i,n) for((i)=1;(i)<=(n);(i)++)
#define fz0k(i,n) for((i)=0;(i)<(n);(i)++)
#define fz0g(i,n) for((i)=0;(i)<=(n);(i)++)
using namespace std;
long long ans[500005];
int n,m,i,j,a[500005],cnt,l,r,rt;
struct ii
{
	int l,r,s;
};
vector<ii> stka,stkb;
vector<pair<int,int> > qry[500005];

int taga[5000005],lc[5000005],rc[5000005];
long long tags[5000005];
struct seg
{
	int mi,s;
	long long ans;
}s[5000005];
seg mrg(seg x,seg y)
{
	seg z;
	z.mi=min(x.mi,y.mi);
	z.s=0;
	if(x.mi==z.mi)z.s+=x.s;
	if(y.mi==z.mi)z.s+=y.s;
	z.ans=x.ans+y.ans;
	return z;
}
void pushup(int x)
{
	s[x]=mrg(s[lc[x]],s[rc[x]]);
}
void upds(int x,int y)
{
//	x=nwnd(x);
//	pushdoa(x);
	s[x].ans+=y;
	tags[x]+=y;
}
void pushdos(int x)
{
	if(tags[x]){
		if(s[x].mi==s[lc[x]].mi) upds(lc[x],tags[x]/s[x].s*s[lc[x]].s);
		if(s[x].mi==s[rc[x]].mi) upds(rc[x],tags[x]/s[x].s*s[rc[x]].s);
		tags[x]=0;
	}
}
void upda(int x,int y)
{
//	x=nwnd(x);
//	pushdos(x);
	s[x].mi+=y;
	taga[x]+=y;
}
void pushdoa(int x)
{
	if(taga[x]){
		upda(lc[x],taga[x]);
		upda(rc[x],taga[x]);
		taga[x]=0;
	}
}
void pushdo(int x)
{
	pushdoa(x);
	pushdos(x);
}
int build(int l,int r)
{
	int t=++cnt;
	if(l==r){
		s[t]=(seg){0x3f3f3f3f,1,0};
		return t;
	}
	int mid=(l+r)/2;
	lc[t]=build(l,mid);
	rc[t]=build(mid+1,r);
	pushup(t);
	return t;
}
void init(int x,int l,int r,int y)
{
	if(l==r){
		s[x].s=1;
		return;
	}
	pushdo(x);
	int mid=(l+r)/2;
	if(y<=mid) init(lc[x],l,mid,y);
	if(y>mid) init(rc[x],mid+1,r,y);
	pushup(x);
}
void updatea(int x,int l,int r,int ql,int qr,int c)
{
//	x=nwnd(x);
	if(ql<=l&&r<=qr){
		upda(x,c);
		return;
	}
	pushdo(x);
	int mid=(l+r)/2;
	if(ql<=mid) updatea(lc[x],l,mid,ql,qr,c);
	if(qr>mid) updatea(rc[x],mid+1,r,ql,qr,c);
	pushup(x);
}
long long query(int x,int l,int r,int ql,int qr)
{
	if(!x){
		return 0;
	}
	if(ql<=l&&r<=qr){
		return s[x].ans;
	}
	pushdo(x);
	int mid=(l+r)/2;
	long long ans=0;
	if(ql<=mid) ans+=query(lc[x],l,mid,ql,qr);
	if(qr>mid) ans+=query(rc[x],mid+1,r,ql,qr);
	return ans;
}
void print(int x,int l,int r)
{
	if(l==r){
		cerr<<s[x].mi<<' ';
		return;
	}
	pushdo(x);
	int mid=(l+r)/2;
	print(lc[x],l,mid);
	print(rc[x],mid+1,r);
}

int main()
{
//	cerr<<(sizeof(qry)+sizeof(s)+sizeof(taga)*4)/1024.0/1024.0<<endl;
//	freopen("large.in","r",stdin);
//	freopen("large.out","w",stdout);
	scanf("%d",&n);
	bool sme=1;
	fz1(i,n){
		scanf("%d",&a[i]);
		sme&=(a[i]==i);
	}
	if(sme)
	{
		scanf("%d",&m);
		while(m--){
			scanf("%d%d",&l,&r);
			int len=r-l+1;
			printf("%lld\n",1ll*len*(len+1)/2);
		}
	}
	
	scanf("%d",&m);
	fz1(i,m){
		scanf("%d%d",&l,&r);
		qry[r].push_back(make_pair(l,i));
	}
	
	rt=build(1,n);
	fz1(i,n){
		init(1,1,n,i);
		if(i>1) updatea(1,1,n,1,i-1,-1);
		updatea(1,1,n,i,i,-0x3f3f3f3f);
		stka.push_back((ii){i,i,a[i]});
		stkb.push_back((ii){i,i,a[i]});
		while(stka.size()>1&&stka[stka.size()-2].s>stka[stka.size()-1].s){
			updatea(1,1,n,stka[stka.size()-2].l,stka[stka.size()-2].r,stka[stka.size()-2].s-stka[stka.size()-1].s);
			stka[stka.size()-2].r=i;
			stka[stka.size()-2].s=stka[stka.size()-1].s;
			stka.pop_back();
		}
		while(stkb.size()>1&&stkb[stkb.size()-2].s<stkb[stkb.size()-1].s){
			updatea(1,1,n,stkb[stkb.size()-2].l,stkb[stkb.size()-2].r,stkb[stkb.size()-1].s-stkb[stkb.size()-2].s);
			stkb[stkb.size()-2].r=i;
			stkb[stkb.size()-2].s=stkb[stkb.size()-1].s;
			stkb.pop_back();
		}
		//print(1,1,n);
		//cerr<<endl;
		if(s[1].mi==0) upds(1,s[1].s);
		for(j=0;j<qry[i].size();j++){
			ans[qry[i][j].second]=query(1,1,n,qry[i][j].first,i);
		}
	}
	
	fz1(i,m){
		printf("%lld\n",ans[i]);
	}
	return 0;
}