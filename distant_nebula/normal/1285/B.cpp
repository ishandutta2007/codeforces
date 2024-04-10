#include <cstdio>
#include <algorithm>
#define ll long long
#define MAXN 100005
int t, n, l, r, l1;
ll ans, s, smin;
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		s=smin=l=r=ans=l1=0;
		scanf("%d", &n);
		for(int i=1, x; i<=n; ++i)
		{
			scanf("%d", &x);
			s+=x;
			if(smin>=s) smin=s, l1=i;
			if(ans<s-smin) l=l1, r=i, ans=s-smin;
			if(ans==s-smin&&l1!=0) l=l1, r=i;
		}
		puts(ans==s?(l!=0||r!=n)?"NO":"YES":"NO");
	}
	return 0;
}