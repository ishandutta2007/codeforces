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
int n,m;
int p;
int T;
int a[maxn];
int vis[maxn];
int main()
{
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	#ifdef TIME
		clock_t ST=clock();
	#endif
	int cnt=0;
	for(i=3;i<n;i++) 
	{
		if(a[i]==1&&a[i-1]==0&&a[i-2]==1&&a[i+1]==0&&a[i+2]==1)
		{
			a[i]=0;
			cnt++;
		}
	}
	for(i=2;i<n;i++)
	{
		if(a[i]==0&&a[i-1]==1&&a[i+1]==1)
			cnt++;
	}
	cout<<cnt;
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	return 0;
}