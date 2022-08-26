#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
using namespace std;
int n,a[200005],b[200005],c[200005],i,j,xx,xxx,yy,yyy,ma,mi=2147480000;
void ch(int x)
{
	b[x]++;
	xx=x;
	xxx=x;
	yy=0;
	yyy=0;
	while (xx<ma)
	{
		xx<<=1;
		yy++;
		b[xx]++;
		c[xx]+=yy;
	}
	while(xxx)
    {
        if (xxx%2&&xxx!=1)
        {
            xxx>>=1;
            yyy++;
            b[xxx]++;
            c[xxx]+=yyy;
            int xxxx=xxx,yyyy=yyy;
            while (xxxx<=ma)
            {
                xxxx<<=1;
                yyyy++;
                b[xxxx]++;
                c[xxxx]+=yyyy;
			}
        }
        else
        {
            xxx>>=1;
            yyy++;
            b[xxx]++;
            c[xxx]+=yyy;
        }
    }
}
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	for (i=1;i<=n;i++)
	ch(a[i]);
	for (i=1;i<=2*ma-1;i++)
	if (b[i]==n)
	mi=min(mi,c[i]);
	cout<<mi;
	return 0;
}