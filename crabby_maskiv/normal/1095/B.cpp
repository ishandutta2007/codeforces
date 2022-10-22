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
int n,m;
int ans=2147483647;
int a[maxn];
int mx,mxp;
int mn=0x3f3f3f3f,mnp;
int main()
{
	int i,j;
	read(n);
	for(i=1;i<=n;i++) read(a[i]);
	#ifdef TIME
		clock_t ST=clock();
	#endif
	for(i=1;i<=n;i++)
	{
		if(a[i]>mx)
		{
			mx=a[i];
			mxp=i;
		}
		if(a[i]<mn)
		{
			mn=a[i];
			mnp=i;
		}
	}
	int tmp=0;
	for(i=1;i<=n;i++)
	{
		if(i==mxp) continue;
		tmp=max(a[i],tmp);
	}
	ans=min(ans,tmp-mn);
	tmp=0x3f3f3f3f;
	for(i=1;i<=n;i++)
	{
		if(i==mnp) continue;
		tmp=min(tmp,a[i]);
	}
	ans=min(ans,mx-tmp);
	print(ans,'\0');
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	return 0;
}