#include <bits/stdc++.h>
using namespace std;
long long n,m,k,a[100005],i,j,z=0,ss;
string st;
int main()
{
	cin>>n>>st;
	n=st.length();
	st=" "+st;
	for (i=1;i<=n;i++)
	{
		if (st[i]!='0') z=1;
		a[i]=st[i]-'0';
		ss+=a[i];
	}
	if (!z){puts("YES");return 0;}
	for (i=1;i<ss;i++)
	{
		int s=0;
		for (j=1;j<=n;j++)
		{
			s+=a[j];
			if (s==i) s=0;
		}
		if (s==0){puts("YES");return 0;}
	}
	puts("NO");
}