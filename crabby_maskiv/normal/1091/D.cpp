#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int maxn=1000005;
const int inf=0x3f3f3f3f;
const long long mod=998244353;
inline void read(int &x) {
    int f=1;x=0;char c=getchar();
    while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    x*=f;return;
}
inline void print(int x,char ch) {
	if(x<0){ putchar('-');x=-x;}
	if(x>9) print(x/10,'\0');putchar(x%10+'0');
	if(ch!='\0') putchar(ch);return;
}
int n,m;
ll a[maxn];
ll b[maxn]; 
ll ans;
int main()
{
	int i,j;
	read(n);
	a[0]=1;b[0]=1;
	for(i=1;i<=n;i++) a[i]=(a[i-1]*i)%mod;
	for(i=1;i<=n;i++) b[i]=(b[i-1]*(n-i+1))%mod;
	#ifdef TIME
		clock_t ST=clock();
	#endif
	ans=a[n];
	for(i=1;i<n;i++)
	{
		ans+=(a[n]-b[n-i]+mod)%mod;
		ans%=mod;
	}
	cout<<ans;
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	return 0;
}