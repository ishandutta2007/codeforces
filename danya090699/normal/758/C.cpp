#include <iostream>
#include <fstream>
#define int long long
using namespace std;
int de(int a, int b)
{
	int an=a/b;
	if(a%b!=0) an++;
	return an;
}
main()
{
	ifstream in("input.txt");
	int n, m, k, x, y, ma, mi, se=0;
	cin>>n>>m>>k>>x>>y;
	if(n==1)
	{
		ma=de(k, m), mi=k/m;
		se=k/m;
		if(k%m>=y) se++;
	}
	else if(n==2)
	{
		ma=de(k, m*2), mi=k/(m*2);
		se=mi;
		if(k%(m*2)>=(x-1)*m+y) se++;
	}
	else
	{
		int fp=(n-1)*m, fq, fq1, fq2;
		fq=de(k, fp);
		fq1=de(fq, 2);
		fq2=fq/2;
		if(fq==0) ma=1;
		else
		{
			ma=fq;
			if(k%fp<=m and k%fp!=0) ma--;
			if(ma==0) ma=1;
		}
		mi=fq2;
		if(fq1==fq2 and k%fp!=0 and k%fp<m) mi--;
		if(x!=n)
		{
			se+=fq1;
			if(fq1>fq2 and k%fp!=0)
			{
				if((x-1)*m+y>k%fp) se--;
			}
		}
		if(x!=1)
		{
			se+=fq2;
			if(fq1==fq2 and k%fp!=0)
			{
				if((n-x)*m+y>k%fp) se--;
			}
		}
	}
	cout<<ma<<" "<<mi<<" "<<se;
}