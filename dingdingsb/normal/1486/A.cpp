#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=1e4+10;
int T,a[M],n;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

signed main()
{
	T=read();
	while(T--)
	{
		n=read();int sum=0;
		for (int i=1;i<=n;i++)a[i]=read();
		a[0]=-1;bool f=0;
		for (int i=1;i<=n;i++)
			if (a[i]>a[i-1])
			{
				int k=a[i]-(a[i-1]+1);
				a[i]=a[i-1]+1,a[i+1]+=k;
			}
			else
			{
				puts("No"),f=1;break;
			}
		if (!f)puts("Yes");
	}
	return 0;
	//cout<<"fuck cccccccccccccccccf"
}