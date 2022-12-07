#include <iostream>
#include <fstream>
#define int long long
using namespace std;
struct el
{
	int le=1, lva, rva, pr1=1, pr2=1, su1=1, su2=1, best=1, add=0;
};
int *ar, g1, g2, add;
el *dot;
void push(int nu)
{
	dot[nu*2].add+=dot[nu].add;
	dot[nu*2+1].add+=dot[nu].add;
	dot[nu].add=0;
}
void recalc(int nu)
{
	el &l=dot[nu*2], &r=dot[nu*2+1], &cu=dot[nu];
	cu.le=l.le+r.le;
	cu.lva=l.lva+l.add, cu.rva=r.rva+r.add;
	cu.pr1=l.pr1, cu.pr2=l.pr2, cu.su1=r.su1, cu.su2=r.su2;
	cu.best=max(l.best, r.best);
	if(l.rva+l.add>r.lva+r.add)
	{
		cu.best=max(cu.best, l.su1+r.pr2);
		if(l.pr1==l.le) cu.pr1+=r.pr2;
		if(l.pr2==l.le) cu.pr2+=r.pr2;
		if(r.pr2==r.le) cu.su1+=l.su1;
	}
	else if(l.rva+l.add<r.lva+r.add)
	{
		cu.best=max(cu.best, l.su2+r.pr1);
		if(l.su2==l.le) cu.pr1+=r.pr1;
		if(r.su1==r.le) cu.su1+=l.su2;
		if(r.su2==r.le) cu.su2+=l.su2;
	}
}
void build(int nu, int l, int r)
{
	if(l==r)
	{
		dot[nu].lva=ar[l], dot[nu].rva=ar[l];
	}
	else
	{
		int mi=(l+r)/2;
		build(nu*2, l, mi);
		build(nu*2+1, mi+1, r);
		recalc(nu);
	}
}
void cha(int nu, int l, int r)
{
	if((l>=g1)and(r<=g2)) dot[nu].add+=add;
	else if(!((r<g1)or(l>g2)))
	{
		push(nu);
		int mi=(l+r)/2;
		cha(nu*2, l, mi);
		cha(nu*2+1, mi+1, r);
		recalc(nu);
	}
}
main()
{
	ifstream in("input.txt");
	int n;
	scanf("%lld", &n);
	ar=new int[n], dot=new el[n*4];
	for(int a=0; a<n; a++) scanf("%lld", &ar[a]);
	build(1, 0, n-1);
	int m;
	scanf("%lld", &m);
	for(int a=0; a<m; a++)
	{
		scanf("%lld%lld%lld", &g1, &g2, &add);
		g1--, g2--;
		cha(1, 0, n-1);
		printf("%lld\n", dot[1].best);
	}
}