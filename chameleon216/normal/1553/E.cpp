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

const int MB=1<<20;
struct FastIO
{
	char ib[MB+100],*p,*q;
	char g()
	{
		if(p==q)p=ib,q=ib+fread(ib,1,MB,stdin);
		return p==q?0:*p++;
	}
	template<typename T>
	void d(T& x)
	{
		char c=g(),l=0;
		for(x=0;!isdigit(c);c=g())l=c;
		for(;isdigit(c);c=g())x=x*10-'0'+c;
		if(l=='-')x=-x;
	}
}IO;

const int MX=300100;
int N,M,P[MX],Q[MX],B[MX];
int cnt[MX],id[MX],res[MX],rc;
bool cmp(int a,int b){return cnt[a]>cnt[b];}

bool Check(int k)
{
	Fo(i,0,N)Q[i]=P[(i+k)%N];
	memset(B,0,N*sizeof(int));
	int c=0;
	Fo(i,0,N)if(!B[i])
	{
		++c;
		for(int x=i;!B[x];x=Q[x])B[x]=1;
	}
	return N-c<=M;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		IO.d(N),IO.d(M);
		Fo(i,0,N)IO.d(P[i]),--P[i];
		Fo(i,0,N)++cnt[(i-P[i]+N)%N];
		Fo(i,0,N)id[i]=i;
		nth_element(id,id+2,id+N,cmp);
		Fo(i,0,3)if(Check(id[i]))
			res[++rc]=id[i];
		sort(res+1,res+rc+1);
		printf("%d ",rc);
		Fr(i,1,rc)printf("%d ",res[i]);
		putchar('\n');
		
		memset(cnt,0,N*sizeof(int));
		rc=0;
	}
	return 0;
}