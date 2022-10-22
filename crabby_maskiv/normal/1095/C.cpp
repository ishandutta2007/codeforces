#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int maxn=200005;
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
int ans[maxn],len;
int main()
{
	int i,j;
	read(n);read(m);
	#ifdef TIME
		clock_t ST=clock();
	#endif
	if(m>n)
	{
		cout<<"NO";
		return 0;
	}
	int cnt=0;
	for(i=1;i<=n;i*=2)
		if(i&n) ans[len++]=i;
	if(len>m)
	{
		cout<<"NO";
		return 0;
	}
	for(i=0;i<len;i++)
	{
		while(len<m&&ans[i]>1)
		{
			ans[len++]=ans[i]/2;
			ans[i]/=2;
		}
	}
	cout<<"YES"<<endl;
	for(i=0;i<len;i++)print(ans[i],' ');
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	return 0;
}