#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

const int MX=4000100,Mod=51123987;
int N,M;
char S[MX],T[MX];
int R[MX];

void Manacher()
{
	M=2*N+1;
	T[0]='$',T[1]='#';
	Fr(i,1,N)T[i*2]=S[i],T[i*2+1]='#';
	
	int m=0,r=0;
	Fr(i,1,M)
	{
		if(i<r)R[i]=min(R[2*m-i],r-i);
		while(T[i-R[i]-1]==T[i+R[i]+1])++R[i];
		if(i+R[i]>r)m=i,r=i+R[i];
	}
}

int Sl[MX],Sr[MX];
inline void Add(int a[],int l,int r){++a[l],--a[r+1];}

int main()
{
	scanf("%d%s",&N,S+1);
	Manacher();
	int sum=0;
	Fr(i,1,M)
	{
		sum=(sum+(R[i]+1)/2)%Mod;
		int l=(i-R[i]+1)/2,r=(i+R[i]-1)/2;
		Add(Sr,l,(l+r)/2);
		Add(Sl,(l+r+1)/2,r);
	}
	Fr(i,1,N)Sr[i]=(Sr[i]+Sr[i-1])%Mod,Sl[i]=(Sl[i]+Sl[i-1])%Mod;
	Fr(i,1,N)Sl[i]=(Sl[i]+Sl[i-1])%Mod;
	int ans=0;
	Fr(i,2,N)ans=(ans+(ll)Sl[i-1]*Sr[i])%Mod;
	printf("%lld\n",((ll)sum*(sum-1)/2-ans+Mod)%Mod);
	return 0;
}