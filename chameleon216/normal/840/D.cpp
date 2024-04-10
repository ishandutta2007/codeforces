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
const int MX=300100;
int N,M,A[MX];

struct Segment{int v,L,R;}T[MX<<5];
int tc;
#define li T[i].L
#define ri T[i].R
int Copy(int i){T[++tc]=T[i];return tc;}
void Ins(int& i,int l,int r,int a)
{
	i=Copy(i),++T[i].v;
	if(l==r)return;
	int m=(l+r)>>1;
	if(a<=m)Ins(li,l,m,a);
	else Ins(ri,m+1,r,a);
}
int Binary(int x,int y,int l,int r,int val)
{
	if(T[y].v-T[x].v<val)return 0;
	if(l==r)return l;
	int m=(l+r)>>1;
	if(int a=Binary(T[x].L,T[y].L,l,m,val))return a;
	if(int b=Binary(T[x].R,T[y].R,m+1,r,val))return b;
	return 0;
}

int Tr[MX];


int main()
{
	scanf("%d%d",&N,&M);
	Fr(i,1,N)scanf("%d",&A[i]);
	Fr(i,1,N)Tr[i]=Tr[i-1],Ins(Tr[i],1,N,A[i]);
	Fr(i,1,M)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		int val=(r-l+1)/k+1;
		int x=Binary(Tr[l-1],Tr[r],1,N,val);
		printf("%d\n",x?x:-1);
	}
	return 0;
}