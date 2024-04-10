#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
#define llx(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
//#define rdst(st,len) {char ss[len];scanf("%s",ss);(st)=ss;}
#define rdst(st,len) {char ss[len];gets(ss);(st)=ss;}
using namespace std;
long long n,m,i,j,num[200005],l,r,op,x;
string st;
struct seg
{
	struct ii
	{
		long long mi,l,r,add;
		void update(long long x)
		{
			add+=x;
			mi+=x;
		}
	}tr[800005];
	void pushup(long long x)
	{
		tr[x].mi=min(tr[x*2].mi,tr[x*2+1].mi);
	}
	void pushdo(long long x)
	{
		if (tr[x].add)
		{
			tr[x*2].update(tr[x].add);
			tr[x*2+1].update(tr[x].add);
			tr[x].add=0;
		}
	}
	void build(long long x,long long l,long long r)
	{
		tr[x]=(ii){0,l,r,0};
		if (l==r) tr[x].mi=num[l];
		else
		{
			build(x*2,l,(l+r)/2);
			build(x*2+1,(l+r)/2+1,r);
			pushup(x);
		}
	}
	void update(long long x,long long l,long long r,long long c)
	{
		if (tr[x].l>r||tr[x].r<l) return;
		if (tr[x].l>=l&&tr[x].r<=r)
		{
			tr[x].update(c);
			return;
		}
		pushdo(x);
		update(x*2,l,r,c);
		update(x*2+1,l,r,c);
		pushup(x);
	}
	long long query(long long x,long long l,long long r)
	{
		if (tr[x].l>r||tr[x].r<l) return 0x7f7f7f7f7f7f7fll;
		if (tr[x].l>=l&&tr[x].r<=r)
		{
			return tr[x].mi;
		}
		pushdo(x);
		return min(query(x*2,l,r),query(x*2+1,l,r));
	}
}tr;
int main()
{
	scanf("%I64d",&n);
	for (i=1;i<=n;i++) scanf("%I64d",&num[i]);
	tr.build(1,1,n);
	scanf("%I64d\n",&m);
	for (i=1;i<=m;i++)
	{
		rdst(st,50);
		//cerr<<st<<endl;
		if (((int)(st.substr(st.find(" ")+1).find(" ")))!=-1)
		{
			sscanf(st.c_str(),"%I64d%I64d%I64d",&l,&r,&x);
			x=(int)x;
			l++;
			r++;
			if (l<=r) tr.update(1,l,r,x);
			else
			{
				tr.update(1,1,r,x);
				tr.update(1,l,n,x);
			}
		}
		else
		{
			sscanf(st.c_str(),"%I64d%I64d",&l,&r);
			l++;
			r++;
			if (l<=r) printf("%I64d\n",tr.query(1,l,r));
				else printf("%I64d\n",min(tr.query(1,1,r),tr.query(1,l,n)));
		}
	}
	return 0;
}