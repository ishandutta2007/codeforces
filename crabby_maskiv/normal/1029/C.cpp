#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
	int id,a;
}l[300010],r[300010];
int n;
bool cmp1(node x,node y)
{
	return x.a>y.a;
}
bool cmp2(node x,node y)
{
	return x.a<y.a;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&l[i].a,&r[i].a);
		l[i].id=i;
		r[i].id=i;
	}
	sort(l+1,l+n+1,cmp1);
	sort(r+1,r+n+1,cmp2);
	if(l[1].id==r[1].id)printf("%d",max(r[2].a-l[2].a,0));
	else printf("%d",max(max(r[2].a-l[1].a,r[1].a-l[2].a),0));
	return 0;
}