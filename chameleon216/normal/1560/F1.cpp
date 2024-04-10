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

int D[60],dc;
char B[10];

int Solve(int x,int kk)
{
	dc=0;
	for(int y=x;y;y/=10)D[++dc]=y%10;
	
	memset(B,0,sizeof(B));
	Fr(i,1,dc)B[D[i]]=1;
	int s=0;
	Fr(i,0,9)s+=B[i];
	if(s<=kk)return x;
	
	Fr(i,1,dc)Fr(j,D[i]+1,9)
	{
		memset(B,0,sizeof(B));
		B[j]=1;
		Fr(k,i+1,dc)B[D[k]]=1;
		s=0;
		Fr(k,0,9)s+=B[k];
		if(s>kk)continue;
		int b=0;
		if(s==kk)Fr(k,0,9)if(B[k]){b=k;break;}
		int z=0;
		Fl(k,dc,i+1)z=z*10+D[k];
		z=z*10+j;
		Fl(k,i-1,1)z=z*10+b;
		return z;
	}
	return 0;
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		int x,k;
		scanf("%d%d",&x,&k);
		printf("%d\n",Solve(x,k));
	}
	return 0;
}