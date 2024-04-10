#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

const int MX=100100;
int N;
char S[MX];
int Z[MX],V[MX];

int main()
{
	scanf("%s",S+1);
	N=strlen(S+1);
	Z[1]=N;
	int l=0,r=0;
	Fr(i,2,N)
	{
		if(i<=r)Z[i]=min(Z[i-l+1],r-i+1);
		while(S[1+Z[i]]==S[i+Z[i]])++Z[i];
		if(i+Z[i]-1>r)l=i,r=i+Z[i]-1;
	}
	Fr(i,1,N)++V[Z[i]];
	Fl(i,N-1,1)V[i]+=V[i+1];
	int c=0;
	Fl(i,N,1)if(i+Z[i]-1==N)++c;
	printf("%d\n",c);
	Fl(i,N,1)if(i+Z[i]-1==N)
		printf("%d %d\n",N-i+1,V[N-i+1]);
	return 0;
}