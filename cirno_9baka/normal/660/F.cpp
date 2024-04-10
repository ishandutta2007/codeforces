#include<bits/stdc++.h>
using namespace std;
int n,a[200005],i,sta[200005];
long long s[200005],e[200005],ans;
struct str{
	long long k,b;
}p[200005],q[200005];
bool cmp(str a,str b)
{
	return a.k<b.k;
}
long double vex(str a,str b)
{
	return ((long double)(b.b-a.b))/(a.k-b.k);
}
void dfs(int l,int r)
{
	if(l==r)
		return;
	int mid=(l+r)/2;
	dfs(l,mid);
	dfs(mid+1,r);
	int i,k=0,top=0,m=0,j;
	for(i=l;i<=mid;i++)
	{
		p[++k].b=e[mid]-e[i-1];
		p[k].k=mid-i+1;
	}
	sort(p+1,p+1+k,cmp);
	for(i=1;i<=k;i++)
	{
		while(top>1&&vex(p[sta[top]],p[sta[top-1]])>vex(p[i],p[sta[top-1]]))
			top--;
		sta[++top]=i;
	}
	for(i=mid+1;i<=r;i++)
		q[++m]=(str){s[i],i};
	sort(q+1,q+1+m,cmp);
	j=1;
	for(i=1;i<=m;i++)
	{
		while(j<top&&p[sta[j+1]].k*q[i].k+p[sta[j+1]].b>p[sta[j]].k*q[i].k+p[sta[j]].b)
			j++;
		ans=max(ans,(p[sta[j]].k+q[i].b-mid-1)*q[i].k+p[sta[j]].b+e[q[i].b-1]-e[mid]);
	}
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i+1]=s[i]+a[i];
		e[i+1]=e[i]-s[i+1];
	}
	dfs(1,n+1);
	cout<<ans;
}