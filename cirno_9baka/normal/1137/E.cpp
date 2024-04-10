#include<bits/stdc++.h>
using namespace std;
const int M=1000000007;
const int N=300005,E=524288;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
ld eps=0.00000001;
int n,m,i,t,a,b,top;
ll ofx,ofy,sx[N],sy[N],k;
int main()
{
	scanf("%d %d",&n,&m);
	k=ofy=0;
	sx[top=1]=0;
	sy[top]=0;
	ofx+=n;
	while(m--)
	{
		scanf("%d %d",&t,&a);
		if(t==1)
		{
			k=ofy=0;
			sx[top=1]=0;
			sy[top]=0;
			ofx+=a;
		}
		if(t==2)
		{
			while(top>1&&((ld)-ofy+k*ofx-sy[top])/(ofx-sx[top])+eps<((ld)sy[top]-sy[top-1])/(sx[top]-sx[top-1]))
				--top;
			sx[++top]=ofx;
			sy[top]=-ofy+k*ofx;
			ofx+=a;
		}
		if(t==3)
		{
			scanf("%d",&b);
			ofy+=a;
			k-=b;
		}
		while(top>1&&((ld)sy[top]-sy[top-1])/(sx[top]-sx[top-1])+eps>k)
			--top;
		printf("%lld %lld\n",sx[top]+1,sy[top]-sx[top]*k+ofy);
	}
}