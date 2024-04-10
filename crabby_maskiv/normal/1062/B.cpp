#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int maxn=1000005;
const int inf=0x3f3f3f3f;
inline void read(int &x) {
    int f=1;x=0;char c=getchar();
    while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    x*=f;
}
inline void print(int x) {
	if(x<0){ putchar('-');x=-x;}
	if(x>9) print(x/10);putchar(x%10+'0');
}
int n,m;
int h[maxn];
int main()
{
	int i,j;
	read(n);
	#ifdef TIME
		clock_t ST,FI;
		double TOT;
		ST=clock();
	#endif
	int x=n;
	for(i=2;i<=x;i++)
	{
		while(x%i==0)
		{
			h[i]++;
			x/=i;
		}
	}
	int mx=0,mn=inf,ans=1,cnt=0;
	for(i=2;i<=n;i++)
	{
		if(h[i]) ans*=i;
		mx=max(h[i],mx);
		if(h[i]) mn=min(mn,h[i]);
	}
	if(ans==n)
	{
		cout<<n<<" "<<0;
		return 0;
	}
	x=1;
	while(x<mx)
	{
		x*=2;
		cnt++;
	}
	if(x==mn&&x==mx) 
	{
		cout<<ans<<" "<<cnt;
		return 0;
	}
	cout<<ans<<" "<<cnt+1;
	#ifdef TIME
		FI=clock();
		TOT=double(FI-ST)/CLOCKS_PER_SEC*1000.0;
		printf("\n%.2lf ms",TOT);
	#endif
	return 0;
}