#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int maxn=100005;
const int inf=0x3f3f3f3f;
const int mod=1000000007;
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
char a[maxn];
ll sum[maxn];
ll p[maxn];
ll fun(int l,int r)
{
	int len=(r-l+1),s=sum[r]-sum[l-1];
	ll k=(p[s]-1)%mod;
	return (k+(p[len-s]-1)*k)%mod;
}
int main()
{
	int i,j;
	read(n);read(m);
	cin>>a;
	for(i=n;i>0;i--) a[i]=a[i-1];
	#ifdef TIME
		clock_t ST,FI;
		double TOT;
		ST=clock();
	#endif
	for(i=1;i<=n;i++) sum[i]=sum[i-1]+(a[i]-'0');
	p[0]=1;
	for(i=1;i<=n;i++) p[i]=(p[i-1]*2)%mod;
	while(m--)
	{
		int l,r;
		read(l);read(r);
		cout<<fun(l,r)<<endl;
	}
	#ifdef TIME
		FI=clock();
		TOT=double(FI-ST)/CLOCKS_PER_SEC*1000.0;
		printf("\n%.2lf ms",TOT);
	#endif
	return 0;
}