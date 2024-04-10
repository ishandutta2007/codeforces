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
int a[maxn],b[maxn];
int x[maxn],y[maxn];
map<pair<int,int>,int> mp;
int ansx,ansy;
int main()
{
	int i,j;
	read(n);
	for(i=1;i<=n;i++) 
	{
		read(x[i]);
		read(y[i]);
	}
	for(i=1;i<=n;i++)
	{
		read(a[i]);
		read(b[i]);
	}
	#ifdef TIME
		clock_t ST=clock();
	#endif
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			pair<int,int> p=make_pair(x[i]+a[j],y[i]+b[j]);
			mp[p]++;
			if(mp[p]==n)
			{
				ansx=p.first;
				ansy=p.second;
			}
		}
	}
	cout<<ansx<<" "<<ansy<<endl;
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	return 0;
}