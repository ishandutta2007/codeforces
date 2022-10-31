#include <cstdio>
#include <iostream>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
string a[1100];
int main()
{
	int n;
	cin>>n;
	a[1]="aeiou"; 
	a[2]="eioua";
	a[3]="iouae";
	a[4]="ouaei";
	a[5]="uaeio";
	for(int i=1;i<=n;i++)
		if (n%i==0)
		{
			int r=i;
			int c=n/i;
			if (r<5 || c<5)continue;
			for(int j=1;j<=r;j++)
			{
				if (j==1)for(int k=6;k<=c;k++)a[j]+='a';
				if (j==2)for(int k=6;k<=c;k++)a[j]+='e';
				if (j==3)for(int k=6;k<=c;k++)a[j]+='i';
				if (j==4)for(int k=6;k<=c;k++)a[j]+='o';
				if (j==5)for(int k=6;k<=c;k++)a[j]+='u';
				if (j>5)
				{
					a[j]="aeiou";
					for(int k=6;k<=c;k++)a[j]+='a';
				}
			}
			for(int i=1;i<=r;i++)cout<<a[i];
			puts("");
			return 0;
		}
	puts("-1");
	return 0;
}