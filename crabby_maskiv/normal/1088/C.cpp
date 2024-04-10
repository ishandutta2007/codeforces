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
    x*=f;return;
}
inline void print(int x,char ch) {
	if(x<0){ putchar('-');x=-x;}
	if(x>9) print(x/10,'\0');putchar(x%10+'0');
	if(ch!='\0') putchar(ch);return;
}
ll n,m;
ll mod;
ll a[maxn];
ll b[maxn];
ll ans[maxn];
int main()
{
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	mod=max(a[n]+1,n);
	cout<<n+1<<endl;
	#ifdef TIME
		clock_t ST=clock();
	#endif
	for(i=n;i>0;i--)
		b[i]=(n-i+1)*mod+((i-1+(mod-n))-(a[i]%mod));
	for(i=n;i>0;i--) ans[i]=b[i]-b[i+1];
	for(i=1;i<=n;i++)
		cout<<1<<" "<<i<<" "<<ans[i]<<endl;
	cout<<2<<" "<<n<<" "<<mod;
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	return 0;
}