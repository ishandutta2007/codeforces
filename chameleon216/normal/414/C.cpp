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
const int MX=1200000;
int W,N,M;
int A[MX],tmp[MX];
ll X[30][2];
int C[30];

void MergeSort(int w,int l,int r)
{
	if(l==r)return;
	int m=(l+r)>>1;
	MergeSort(w-1,l,m);
	MergeSort(w-1,m+1,r);
	
	ll sumx=0,sumy=0;
//	Fr(i,l,r)printf("%d ",A[i]);
	for(int i=l,j=m+1;i<=m;++i)
	{
		while(j<=r&&A[j]<A[i])++j;
		sumx+=j-m-1;
	}
	
	int i=l,c=l;
	for(int j=m+1;j<=r;++j)
	{
		for(;i<=m&&A[i]<A[j];++i)tmp[c++]=A[i];
		sumy+=i-l,tmp[c++]=A[j];
	}
	for(;i<=m;++i)tmp[c++]=A[i];
	
	Fr(j,l,r)A[j]=tmp[j];
	X[w][0]+=sumx,X[w][1]+=sumy;
//	printf("MergeSort{%d} [%d,%d]: sumx=%lld sumy=%lld\n",w,l,r,sumx,sumy);
}




int main()
{
	scanf("%d",&W),N=1<<W;
	Fr(i,1,N)scanf("%d",&A[i]);
	MergeSort(W,1,N);
	scanf("%d",&M);
	Fr(j,1,M)
	{
		int w;
		scanf("%d",&w);
		Fr(i,1,w)C[i]^=1;
		ll sum=0;
		Fr(i,1,W)sum+=X[i][C[i]];
		printf("%lld\n",sum);
	}
	return 0;
}

/*
3
8 4 3 5 2 4 5 7
*/