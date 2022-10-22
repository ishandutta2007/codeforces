#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <map>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MX=200100;
int T,N,K,A[MX];

void Solve()
{
	scanf("%d%d",&N,&K);
	map<int,int> mp;
	Fr(i,1,N)scanf("%d",&A[i]),mp[A[i]]=i;
	Fr(i,1,N)if(mp.count(A[i]-K)){printf("YES\n");return;}
	printf("NO\n");
}

int main()
{
	scanf("%d",&T);
	Fr(i,1,T)Solve();
	return 0;
}