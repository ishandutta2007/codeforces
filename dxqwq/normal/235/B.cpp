#include<bits/stdc++.h>
using namespace std;
double ch[1000003];
double ans[1000003];
double combo[1000003];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%lf",&ch[i]);
	ans[0]=0;
	combo[0]=0;
	for(int i=1; i<=n; i++)
	{
		combo[i]=(combo[i-1]+1)*ch[i];
		ans[i]=ans[i-1]+(2*combo[i-1]+1)*ch[i];
	}
	printf("%.10f",ans[n]);
	return 0;
}