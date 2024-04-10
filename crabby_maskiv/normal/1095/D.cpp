#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int maxn=300005;
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
int a[maxn],b[maxn];
int ans[maxn];
int next(int id,int dis)
{
	return (id+dis)%n+1;
}
int main()
{
	int i,j;
	read(n);
	for(i=1;i<=n;i++) 
	{
		read(a[i]);read(b[i]);
	}
	ans[1]=1;
	#ifdef TIME
		clock_t ST=clock();
	#endif
	for(i=1;i<n-1;i++)
	{
		ans[i+1]=a[ans[i]];
		ans[i+2]=b[ans[i]];
		if(a[ans[i+2]]==ans[i+1]||b[ans[i+2]]==ans[i+1]) swap(ans[i+1],ans[i+2]);
	}
	for(i=1;i<=n;i++) cout<<ans[i]<<" ";
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	return 0;
}