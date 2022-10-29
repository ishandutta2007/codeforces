#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
typedef double DB;
int n,x;
DB A[500];
void FWT(int l,int r)
{
	if(l+1==r)return;
	int mid=l+r>>1;
	FWT(l,mid);
	FWT(mid,r);
	int d=mid-l;
	DB x,y;
	for(int i=l;i<mid;i++)
	{
		x=A[i];
		y=A[i+d];
		A[i]=x+y;
		A[i+d]=x-y;
	}
}
int main()
{
	//freopen("d.in","r",stdin);
	//freopen("d.out","w",stdout);
	cin>>n>>x;
	for(int i=0;i<=x;i++)
		cin>>A[i];
	FWT(0,256);
	for(int i=0;i<256;i++)
		A[i]=pow(A[i],n);
	FWT(0,256);
	DB ans=0;
	for(int i=1;i<256;i++)
		ans+=A[i]/256.0;
	printf("%.8lf\n",double(ans));
	return 0;
}