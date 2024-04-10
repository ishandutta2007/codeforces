#include<iostream>
#include<cstdio>
#define maxn 10005
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
inline void read(int &x) {
    int f=1;x=0;char c=getchar();
    while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    x*=f;
}

inline void readll(ll &x) {
    int f=1;x=0;char c=getchar();
    while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    x*=f;
}
int n,m,mx,sum1,sum2;
int a[maxn];
int main()
{
	cin>>n;
	int i,j;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		sum1+=a[i];
		mx=max(mx,a[i]);
	}
	for(i=0;i<n;i++)
		sum2+=mx-a[i];
	int ans=mx;
	while(sum2<=sum1)
	{
		ans++;
		sum2+=n;
	}
	cout<<ans;
	return 0;
}