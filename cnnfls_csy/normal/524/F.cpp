#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<set>
#include<iomanip>
#define sqr(x) (x)*(x)
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
//#define T_ long long
using namespace std;
//struct bit{T_ arr[1000005];int lowbit(int x){return x&(-x);}void add(int x,T_ y){for (int i=x;i<=n;i+=lowbit(i)) arr[i]+=y;}T_ query(int x){T_ s=0;for (int i=x;i>0;i-=lowbit(i)) s+=arr[i];return s;}};
//struct seg{struct treedot{int l,r;T_ sum,add;void update(T_ x){sum+=(r-l+1)*x; add+=x;}}c[800005];void pushdown(int id){if (c[id].add){c[id*2].update(c[id].add);c[id*2+1].update(c[id].add);c[id].add=0;}}void pushup(int id){c[id].sum=c[id*2].sum+c[id*2+1].sum;}void build(int id,int l,int r){if (l>r) return;c[id].l=l;c[id].r=r;c[id].sum=0;c[id].add=0;if (l==r) c[id].sum=0;else{int mid=l+(r-l)/2;build(id*2,l,mid);build(id*2+1,mid+1,r);pushup(id);}}void update(int id,int le,int ri,T_ x){if (le>c[id].r||ri<c[id].l) return;if (le<=c[id].l&&c[id].r<=ri) c[id].update(x);else{pushdown(id);update(id*2,le,ri,x);update(id*2+1,le,ri,x);pushup(id);}}T_ query(int id,int le,int ri){if (ri<c[id].l||c[id].r<le) return 0;if (le<=c[id].l&&c[id].r<=ri) return c[id].sum;T_ ans=0;pushdown(id);ans+=query(id*2,le,ri);ans+=query(id*2+1,le,ri);pushup(id);return ans;}};
int n,m,i,j,k,sl[4000005],sr[4000005],sl2[4000005],sr2[4000005],sl3[4000005],sr3[4000005],sl4[4000005],sr4[4000005],sa[4000005],rk[4000005],c[4000005],x[4000005],y[4000005],ans,ans2;
string st;
void solve(int x)
{
	x--;
	int s1=max(sr2[x],sr[x]+sl3[x+1]),s2=max(sl2[x+1],sl[x+1]+sr3[x]);
	if (s1+s2<ans2)
	{
		ans2=s1+s2;
		ans=x;
	}
}
int main()
{
	rdst(st,4000005);
	n=st.length()*2;st=" "+st+st;
	m='}';
	fz1(i,n) x[i]=st[i];
	fz1(i,n) c[x[i]]++;
	fz1(i,m) c[i]+=c[i-1];
	fz1(i,n) sa[c[x[i]]--]=i;
	for (k=1;k<=n;k<<=1)
	{
		int num=0;
		fz(i,n-k+1,n) y[++num]=i;
		fz1(i,n) if (sa[i]>k) y[++num]=sa[i]-k;
		fz1(i,m) c[i]=0;
		fz1(i,n) c[x[i]]++;
		fz1(i,m) c[i]+=c[i-1];
		fd1(i,n) sa[c[x[y[i]]]--]=y[i];
		fz1(i,n) y[i]=0;
		num=1;
		swap(x,y);
		x[sa[1]]=1;
		fz(i,2,n)
		{
			if (y[sa[i]]!=y[sa[i-1]]||y[sa[i]+k]!=y[sa[i-1]+k])
			{
				num++;
			}
			x[sa[i]]=num;
		}
		m=num;
		if (m==n) break;
	}
	n/=2;
	fz1(i,n)
	{
		sr[i]=sr[i-1];
		if (st[i]=='(') sr[i]++; else sr[i]--;
		sr2[i]=max(0,sr2[i-1]);
		if (st[i]=='(') sr2[i]++; else sr2[i]--;
		sr2[i]=max(0,sr2[i]);
		sr4[i]=sr4[i-1];
		if (st[i]==')') sr4[i]++; else sr4[i]--;
		sr3[i]=max(sr3[i],sr4[i]);
	}
	fd1(i,n)
	{
		sl[i]=sl[i+1];
		if (st[i]==')') sl[i]++; else sl[i]--;
		sl2[i]=max(0,sl2[i+1]);
		if (st[i]==')') sl2[i]++; else sl2[i]--;
		sl2[i]=max(0,sl2[i]);
		sl4[i]=sl4[i+1];
		if (st[i]=='(') sl4[i]++; else sl4[i]--;
		sl3[i]=max(sl3[i],sl4[i]);
	}
	ans2=n*15;
	fz1(i,n+n) if (sa[i]<=n) solve(sa[i]);
	int x=ans;
	int s1=max(sr2[x],sr[x]+sl3[x+1]),s2=max(sl2[x+1],sl[x+1]+sr3[x]);
	while (s2--) putchar('(');
	printf("%s%s",st.substr(x+1,n-x).c_str(),st.substr(1,x).c_str());
	while (s1--) putchar(')');
	return 0;
}