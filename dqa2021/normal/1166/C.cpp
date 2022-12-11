#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	if (flg) x=-x;
	return x;
}

int n,a[200010],b[200010];
typedef long long ll;
ll ans;
int main()
{
	n=read();
	for (int i=1,x;i<=n;i++)
	{
		x=read();
		if (x<0) a[++*a]=-x;
		else b[++*b]=x;
	}
	sort(a+1,a+(*a)+1); sort(b+1,b+(*b)+1);
	for (int i=2;i<=(*a);i++)
	{
		if (a[i-1]*2<a[i]) continue;
		int l=1,r=i-1,mid;
		while (l<r)
		{
			mid=l+r>>1;
			if (a[mid]*2>=a[i]) r=mid;
			else l=mid+1;
		}
		ans+=i-l;
//		printf("add1 %d at %d\n",i-l,i);
	}
	for (int i=2;i<=(*b);i++)
	{
		if (b[i-1]*2<b[i]) continue;
		int l=1,r=i-1,mid;
		while (l<r)
		{
			mid=l+r>>1;
			if (b[mid]*2>=b[i]) r=mid;
			else l=mid+1;
		}
		ans+=i-l;
//		printf("add2 %d at %d\n",i-l,i);
	}
	int pos=0;
	for (int i=1;i<=(*a);i++)
	{
		while (pos<(*b)&&b[pos+1]<=a[i]) pos++;
		if (!pos||b[pos]*2<a[i]) continue;
		int l=1,r=pos,mid;
		while (l<r)
		{
			mid=l+r>>1;
			if (b[mid]*2>=a[i]) r=mid;
			else l=mid+1;
		}
		ans+=pos-l+1;
//		printf("add3 %d at %d\n",pos-l+1,i);
	}
	pos=0;
	for (int i=1;i<=(*b);i++)
	{
		while (pos<(*a)&&a[pos+1]<b[i]) pos++;
		if (!pos||a[pos]*2<b[i]) continue;
		int l=1,r=pos,mid;
		while (l<r)
		{
			mid=l+r>>1;
			if (a[mid]*2>=b[i]) r=mid;
			else l=mid+1;
		}
		ans+=pos-l+1;
//		printf("add4 %d at %d\n",pos-l+1,i);
	}
	printf("%I64d\n",ans);
	return 0;
}