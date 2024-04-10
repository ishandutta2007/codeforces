#include <bits/stdc++.h>
#define fo(a,b,c) for (a=b; a<=c; a++)
#define fd(a,b,c) for (a=b; a>=c; a--)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define ll long long
//#define file
using namespace std;

int T,n,i,j,k,l;
ll a[5],ans,s,s1,s2,S;

int main()
{
	#ifdef file
	freopen("e.in","r",stdin);
	#endif
	
	scanf("%d",&T);
	for (;T;--T)
	{
		fo(i,1,4) scanf("%lld",&a[i]);
		ans=0;
		fo(i,1,3)
		{
			fo(j,2,4)
			if (i!=j)
			{
				S=min(a[i],a[j]);s1=s2=0;
				fo(k,1,4)
				if (i!=k && j!=k)
				{
					if (!s1) s1=a[k];
					else s2=a[k];
				}
				s=S*min(s1,s2);
				ans=max(ans,s);
			}
		}
		printf("%lld\n",ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}