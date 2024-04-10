#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
using namespace std;
int n,i,j,a[25],b[25],s,t,ma,mi,l,r,x,y;
int main()
{
	cin>>n>>l>>r>>x;
	for (i=1;i<=n;i++) cin>>a[i];
	while (!b[0])
	{
		for (j=n;b[j];j--);
		b[j++]=1;
		for (;j<=n;j++) b[j]=0;y=0;
		t=0;ma=0;mi=2147480000;
		for (j=1;j<=n;j++) 
		{
		    t+=a[j]*b[j];
		    ma=max(ma,a[j]*b[j]);
		    if (b[j]) {mi=min(mi,a[j]);y++;}
                    }
                    if (t>=l&&t<=r&&ma-mi>=x&&y>=2)
                    s++;
          }
          cout<<s;
          return 0;
}