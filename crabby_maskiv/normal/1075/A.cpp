#include<bits/stdc++.h>
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
inline void print(int x) {
	if(x<0){ putchar('-');x=-x;}
	if(x>9) print(x/10);putchar(x%10+'0');
}
ll x,y;
ll n;
int main()
{
	int i,j;
	cin>>n;
	cin>>x>>y;
	ll ansx,ansy;
	ansx=min(x-1,y-1)+max(x-1,y-1)-min(x-1,y-1);
	ansy=min(n-x,n-y)+max(n-x,n-y)-min(n-x,n-y);
	if(ansx<=ansy)
	{
		cout<<"White";
	}
	else
	{
		cout<<"Black";
	}
	return 0;
}