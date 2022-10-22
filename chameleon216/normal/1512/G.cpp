#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;
const int MX=10000100,W=10000000;

char isp[MX];
int P[MX],pc,sig[MX];
void Euler()
{
	memset(isp,1,sizeof(isp));
	isp[0]=isp[1]=0,sig[1]=1;
	Fr(i,2,W)
	{
		if(isp[i])P[++pc]=i,sig[i]=i+1;
		Fr(j,1,pc)
		{
			int p=P[j];
			if(i*p>W)break;
			isp[i*p]=0;
			if(i%p==0)
			{
				sig[i*p]=sig[i]+(sig[i]-sig[i/p])*p;
				break;
			}
			sig[i*p]=sig[i]*sig[p];
		}
	}
}

int B[MX*5];

int main()
{
	Euler();
	memset(B,0xff,sizeof(B));
	Fl(i,W,1)B[sig[i]]=i;
	int n,x;
	scanf("%d",&n);
	Fr(i,1,n)scanf("%d",&x),printf("%d\n",B[x]);
	return 0;
}