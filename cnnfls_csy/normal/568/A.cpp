#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#define sqr(x) (x)*(x)
using namespace std;
int p,q,l,r,mid,pris[10000005],hws[10000005],i,j,ans,x,tot;
bool ispri[10000005];
string st,st1;
char s[15];
int main()
{
	memset(ispri,1,sizeof(ispri));
	ispri[1]=0;
	for (i=2;i*i<=10000000;i++)
	{
		if (ispri[i])
		{
			for (j=2;i*j<=10000000;j++) ispri[i*j]=0;
		}
	}
	for (i=1;i<=10000000;i++) pris[i]=pris[i-1]+ispri[i];
	for (i=1;i<=10000000;i++) 
	{
		x=i;
		tot=0;
		while (x)
		{
			tot=tot*10+x%10;
			x/=10;
		}
		//cerr<<st<<' '<<st1;
		hws[i]=hws[i-1]+(tot==i);
	}
	//for (i=1;i<=40;i++) cerr<<pris[i]<<' '<<hws[i]<<endl;
	cin>>p>>q;
	if (!p||!q) {cout<<"Palindromic tree is better than splay tree";return 0;}
	/*l=1;r=1000000;
	while (l<r)
	{
		mid=(l+r)/2;
		if (pris[mid]<=((double)p)/q*hws[mid]+0.0000001)
		{
			ans=mid;
			l=mid+1;
		}
		else r=mid;
	}*/
	for (i=10000000;i>0;i--)
	{
		//cerr<<pris[i]<<' '<<hws[i]<<endl;
		if (pris[i]<=((double)p)/q*hws[i]+0.0000001) break;
	}
	cout<<i;
	return 0;
}