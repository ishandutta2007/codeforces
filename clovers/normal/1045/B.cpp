#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ull unsigned long long
const int N=200005;
int n;
ull m,a[N],B[N],c[N],base[N],bk[N],fr[N],p=1007;
ull suml(int l,int r)
{
	return fr[r]-fr[l-1]*base[r-l+1];
}

ull sumr(int l,int r)
{
	return bk[l]-bk[r+1]*base[r-l+1];
}

bool judge(int l,int r)
{
	return suml(l,r)==sumr(l,r);
}

int main() 
{
	scanf("%d%llu",&n,&m);
	int ans=0;
	for(int i=1;i<=n;i++) scanf("%llu",&a[i]);
	sort(a+1,a+n+1);
	base[0]=1;
	for(int i=1;i<=n;i++) base[i]=base[i-1]*p;
	for(int i=1;i<n;i++) B[i]=a[i+1]-a[i];
	for(int i=1;i<n;i++) fr[i]=fr[i-1]*p+B[i];
	for(int i=n-1;i>=1;i--) bk[i]=bk[i+1]*p+B[i];
	for(int i=1;i<=n;i++)
	{
		int bl=1;
		if(i!=1) bl&=judge(1,i-1);
		if(i!=n)
		{
			bl&=(a[1]+a[i]==a[i+1]+a[n]-m);
			if(i!=n-1) bl&=judge(i+1,n-1);
		}
		if(bl) c[++ans]=(a[1]+a[i])%m;
	}
	sort(c+1,c+ans+1);
	cout<<ans<<endl;
	for(int i=1;i<=ans;i++) printf("%llu ",c[i]);
	return 0;
}