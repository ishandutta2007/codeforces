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
	return flg?-x:x;
}
const double eps=1e-9;

double Sy,Sa,Sb;
int n,q;
struct Itv{
	double l,r;
}itv[200010];
double sum[200010];
double findl(double x,double y,int k)
{
	return x+(itv[k].l-x)*(1.0-Sy/y);  //Sy negative
}
double findr(double x,double y,int k)
{
	return x+(itv[k].r-x)*(1.0-Sy/y);
}
int main()
{
	Sy=read(),Sa=read(),Sb=read(),n=read();
	for (int i=1;i<=n;i++) itv[i].l=read(),itv[i].r=read(),sum[i]=sum[i-1]+itv[i].r-itv[i].l;
	q=read(); double x,y;
	while (q--)
	{
		x=read(),y=read();
		if (findr(x,y,n)+eps<Sa||Sb+eps<findl(x,y,1)){printf("%.8lf\n",0.0);continue;}
		int l=1,r=n,mid;
		while (l<r)
		{
			mid=l+r>>1;
			if (Sa<findr(x,y,mid)+eps) r=mid;
			else l=mid+1;
		}
		int leftmost=l;
		l=1,r=n;
		while (l<r)
		{
			mid=l+r+1>>1;
			if (findl(x,y,mid)<Sb+eps) l=mid;
			else r=mid-1;
		}
		int rightmost=l;
		if (leftmost>rightmost){printf("%.8lf\n",0.0);continue;}
		double ans;
		if (leftmost==rightmost) ans=min(findr(x,y,leftmost),Sb)-max(findl(x,y,leftmost),Sa);
		else ans=findr(x,y,leftmost)-max(findl(x,y,leftmost),Sa)+min(findr(x,y,rightmost),Sb)-findl(x,y,rightmost)+(sum[rightmost-1]-sum[leftmost])*(1.0-Sy/y);
		printf("%.8lf\n",ans);
	}
	return 0;
}