#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int maxn=100005;
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
ll n,m;
ll a[maxn];
ll sum;
int main()
{
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	#ifdef TIME
		clock_t ST=clock();
	#endif
	sort(a+1,a+n+1);
	ll cur=0,tmp=a[n];
	for(i=n;i>1;i--)
	{
		if(tmp-a[i-1]<=0)
		{
			cur++;
			if(tmp>1) tmp--;
		}
		else
		{
			cur+=(tmp-a[i-1]);
			tmp-=(tmp-a[i-1]);
		}
	}
	cur+=tmp;
	cout<<sum-cur;
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	return 0;
}