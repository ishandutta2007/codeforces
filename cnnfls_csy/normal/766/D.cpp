#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<map>
using namespace std;
map<string,int> c;
int a[200005],b[200005],x,y,z,yy,zz,n,m,s,i,t,q;
string st1,st2;
int find(int x)
{
	if (x!=a[x]) a[x]=find(a[x]);
	return a[x];
}
int main()
{
	 cin>>n>>m>>q;
	 for (i=1;i<=n;i++) 
	 {
	 	cin>>st1;
	 	c[st1]=i;
	 }
	 for (i=1;i<=n*2;i++) a[i]=i;
	 for (i=1;i<=m;i++) 
	 {
	 	cin>>x>>st1>>st2;
	 	if (x==1) 
		{
		 	y=find(c[st1]);
			z=find(c[st2]);
			yy=find(c[st1]+n);
			zz=find(c[st2]+n);
			if (!(a[y]==a[zz]||a[z]==a[yy]))
			{a[y]=z;a[zz]=yy;cout<<"YES"<<endl;}
			else cout<<"NO"<<endl;
		}
		else 
		{
			y=find(c[st1]);
			z=find(c[st2]);
			yy=find(c[st1]+n);
			zz=find(c[st2]+n);
			if (!(a[y]==a[z]||a[yy]==a[zz]))
			{a[y]=zz;a[z]=yy;cout<<"YES"<<endl;}
			else cout<<"NO"<<endl;
		}
	 }
	 for (i=1;i<=q;i++)
	 {
	 	cin>>st1>>st2;
	 	if (find(c[st1])==find(c[st2])) cout<<1<<endl;
	 	else if (find(c[st1]+n)==find(c[st2])||find(c[st1])==find(c[st2]+n)) cout<<2<<endl;
	 	else cout<<3<<endl;
	 }
	 return 0;
}