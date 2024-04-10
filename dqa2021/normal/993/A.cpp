#include<cstdio>
#include<algorithm>
using namespace std;
int a[10][5];
int ulx,uly,drx,dry;
bool isd(int x,int y)
{return x<=drx&&x>=ulx&&y<=dry&&y>=uly;}
bool vis[210];
int numtot;
int pos;
int len;
int abs(int x){return x<0?-x:x;}
bool isd2(int x,int y)
{return abs(x-a[pos][2])+abs(y-a[pos+1][2]+len)<=len;}
bool crss(int a,int b,int c,int d,int e,int f,int g,int h)
{
	if (a>c) swap(a,c);if (b>d) swap(b,d);if (e>g) swap(e,g),swap(f,h);
	if (b==d)
	{
		if (h>f) return b>=f&&b<=h&&e+b-f>=a&&e+b-f<=c;
		return b>=h&&b<=f&&e+f-b>=a&&e+f-b<=c;
	}
	if (h>f) return a>=e&&a<=g&&f+a-e>=b&&f+a-e<=d;
	return a>=e&&a<=g&&f+e-a>=b&&f+e-a<=d;
}
#define node(p,q,x,y) a[p*2-1][1],a[p*2][1],a[q*2-1][1],a[q*2][1],a[x*2-1][2],a[x*2][2],a[y*2-1][2],a[y*2][2]
int main()
{
	int tmp=-0x7fffffff;
	for (int k=1;k<=2;k++)
		for (int i=1;i<=8;i++)
			scanf("%d",&a[i][k]);
	for (int i=1;i<=8;i+=2) if (!vis[a[i][1]+101]) numtot++,vis[a[i][1]+101]=true;
	if (numtot>2) for (int i=1;i<=8;i++) swap(a[i][1],a[i][2]);
	ulx=min(a[1][1],a[5][1]);uly=min(a[2][1],a[6][1]);
	drx=max(a[1][1],a[5][1]);dry=max(a[2][1],a[6][1]);
	if (isd(a[1][2],a[2][2])&&isd(a[3][2],a[4][2])&&isd(a[5][2],a[6][2])&&isd(a[7][2],a[8][2])) return puts("yes"),0;
	for (int i=2;i<=8;i+=2) if (a[i][2]>tmp) tmp=a[i][2],pos=i-1;
	len=abs(a[pos-2<1?pos-2+8:pos-2][2]-a[pos+2>8?pos+2-8:pos+2][2])/2;
	if (isd2(a[1][1],a[2][1])&&isd2(a[3][1],a[4][1])&&isd2(a[5][1],a[6][1])&&isd2(a[7][1],a[8][1])) return puts("yes"),0;
	for (int i=1;i<=4;i++)
		for (int j=1;j<=4;j++)
			if (crss(node(i,(i+1==5?1:i+1),j,(j+1==5?1:j+1))))
				return puts("yes"),0;
	return puts("no"),0;
}