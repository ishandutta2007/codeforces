#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MM 50000
#define ML 600000
#define K 19
struct data{int mx,ms;};
inline data operator+(const data&a,const data&b)
{
	data c;
	c.mx=max(a.mx,b.mx);
	c.ms=min(a.mx==c.mx?a.ms:MM,b.mx==c.mx?b.ms:MM);
	return c; 
}
struct node{int l,r;data x;}t[MM*40+5];
char s[ML+5],ss[MM+5];
int l[MM+5],r[MM+5],z[ML+5],zn,lc[ML+5],rc[ML+5],p[ML+5],rt[ML+5],tn;
int A[ML*4+20],*sa=A,*rk=sa+ML+5,*nsa=rk+ML+5,*nrk=nsa+ML+5,c[ML+5],h[K][ML+5],b[ML+5];
vector< pair<int,int> > v[ML+5];
int Q(int l,int r)
{
	int x=b[r-l+1];
	return min(h[x][l],h[x][r-(1<<x)+1]);
}
int tree(int l,int r,int x)
{
	int k=++tn,mid=l+r>>1;
	t[k].x=(data){1,x};
	if(l==r){t[k].l=-1;return k;}
	if(x<=mid)t[k].l=tree(l,mid,x);
	else t[k].r=tree(mid+1,r,x);
	return k;
}
int merge(int x,int y)
{
	if(!x||!y)return x+y;
	int k=++tn;
	if(t[x].l<0){t[k]=(node){-1,0,(data){t[x].x.mx+t[y].x.mx,t[x].x.ms}};return k;}
	t[k].x=t[t[k].l=merge(t[x].l,t[y].l)].x+t[t[k].r=merge(t[x].r,t[y].r)].x;
	return k;
}
data query(int k,int l,int r,int ql,int qr)
{
	if(!k)return (data){0,ql};
	if(l==ql&&r==qr)return t[k].x;
	int mid=l+r>>1;
	if(qr<=mid)return query(t[k].l,l,mid,ql,qr);
	if(ql>mid)return query(t[k].r,mid+1,r,ql,qr);
	return query(t[k].l,l,mid,ql,mid)+query(t[k].r,mid+1,r,mid+1,qr);
}
void build(int k,int l,int r)
{
	if(lc[k])build(lc[k],l,k-1),rt[k]=merge(rt[k],rt[lc[k]]);
	else if(p[l])rt[k]=merge(rt[k],tree(1,MM,p[l]));
	if(rc[k])build(rc[k],k,r),rt[k]=merge(rt[k],rt[rc[k]]);
	else if(p[r])rt[k]=merge(rt[k],tree(1,MM,p[r]));
	v[l].push_back(make_pair(r,k));
}
int main()
{
	int n,m,q,i,j,ql,qr,pl,pr;
	scanf("%s",s+1);n=strlen(s+1);s[++n]='.';
	for(m=read(),i=1;i<=m;++i)
	{
		scanf("%s",ss);
		for(l[i]=n+1,j=0;ss[j];++j)s[++n]=ss[j];
		r[i]=n++;s[n]='#';
	}
	for(i=1;i<=n;++i)++c[s[i]];
	for(i=1;i<256;++i)c[i]+=c[i-1];
	for(i=1;i<=n;++i)sa[c[s[i]]--]=i;
	for(i=1;i<=n;++i)rk[sa[i]]=rk[sa[i-1]]+(s[sa[i]]!=s[sa[i-1]]);
	for(i=1;i<n;i<<=1,swap(sa,nsa),swap(rk,nrk))
	{
		for(j=1;j<=n;++j)c[rk[sa[j]]]=j;
		for(j=n;j;--j)if(sa[j]>i)nsa[c[rk[sa[j]-i]]--]=sa[j]-i;
		for(j=0;j<i;++j)nsa[c[rk[n-j]]--]=n-j;
		for(j=1;j<=n;++j)nrk[nsa[j]]=nrk[nsa[j-1]]+(rk[nsa[j]]!=rk[nsa[j-1]]||rk[nsa[j]+i]!=rk[nsa[j-1]+i]);
	}
	for(i=1,j=0;i<=n;++i,j?--j:0)if(rk[i]>1){while(s[i+j]==s[sa[rk[i]-1]+j])++j;h[0][rk[i]]=j;}
	for(i=1;i<K;++i)for(j=1;j<=n;++j)h[i][j]=min(h[i-1][j],h[i-1][j+(1<<i-1)]);
	for(i=2;i<=n;++i)b[i]=b[i>>1]+1;
	for(i=2;i<=n;++i)
	{
		while(zn&&h[0][i]<h[0][z[zn]])lc[i]=z[zn--];
		rc[z[zn]]=i;z[++zn]=i;
	}
	for(i=1;i<=m;++i)for(j=l[i];j<=r[i];++j)p[rk[j]]=i;
	build(z[1],1,n);
	int x=merge(merge(0,tree(1,MM,1)),tree(1,MM,1));
	for(q=read(),i=1;i<=q;++i)
	{
		ql=read();qr=read();pl=read();pr=read();
		int x=rk[pl],l,r,mid,L,R;
		for(l=1,r=x-1,L=x;l<=r;)
		{
			mid=l+r>>1;
			if(Q(mid+1,x)>=pr-pl+1)L=mid,r=mid-1;else l=mid+1;
		}
		for(l=x+1,r=n,R=x;l<=r;)
		{
			mid=l+r>>1;
			if(Q(x+1,mid)>=pr-pl+1)R=mid,l=mid+1;else r=mid-1;
		}
		if(L==R){printf("%d 0\n",ql);continue;}
		data xx=query(rt[lower_bound(v[L].begin(),v[L].end(),make_pair(R,0))->second],1,MM,ql,qr);
		printf("%d %d\n",xx.ms,xx.mx);
	}
}