#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define prt(n) cout<<(n)<<endl
#define elif else if
#define str string
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
const int N=100005;
bool a[N];
bool sorted[N];
int indfirst0;
int indlast1=-1;
void solve()
{
	int n,i;
	scanf("%d%d",&n,&i);
	if(n==2)
	{
		#if 0
		for(int j=0;j<5;j++) printf("a[%d]=%d s[%d]=%d\n",j,a[j],j,sorted[j]);
		printf("ind of 1 is %d ans 0 is %d\n",indlast1,indfirst0);
		#else
		printf("%d\n",sorted[i-1]);
		#endif
	}
	else
	{
		if(a[i-1]==1)
		{
			indlast1--;
			indfirst0--;
			sorted[indfirst0]=0;
		}
		else
		{
			indlast1++;
			indfirst0++;
			sorted[indlast1]=1;
		}
		a[i-1]=(!a[i-1]);
		#if 0
		for(int j=0;j<5;j++) printf("a[%d]=%d s[%d]=%d\n",j,a[j],j,sorted[j]);
		printf("ind of 1 is %d ans 0 is %d\n",indlast1,indfirst0);
		#endif
	}
}
int n,q;
bool cmp(bool a,bool b)
{
	return a>b;
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		sorted[i]=a[i];
		if(a[i]==1) indlast1++;
	}
	sort(sorted,sorted+n,cmp);
	indfirst0=indlast1+1; 
	while(q--) solve();
	return 0;
}