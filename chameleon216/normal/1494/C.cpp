#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
#define Fill(x,n) memset((x),(n),sizeof(x))
typedef long long ll;
using namespace std;
const int MX=230000,Inf=0x3f3f3f3f;
int N,M,A[MX],B[MX];
int Box(int a,int b)
{
	int l=lower_bound(A+1,A+1+N,a)-A;
	int r=upper_bound(A+1,A+1+N,b)-A-1;
	return max(0,r-l+1);
}

int Pos(int a,int b)
{
	int l=lower_bound(B+1,B+1+M,a)-B;
	int r=upper_bound(B+1,B+1+M,b)-B-1;
	return max(0,r-l+1);
}

int C[MX],cc;
int Ok(int a,int b)
{
	int l=lower_bound(C+1,C+1+cc,a)-C;
	int r=upper_bound(C+1,C+1+cc,b)-C-1;
	return max(0,r-l+1);
}

int mian()
{
	scanf("%d%d",&N,&M);
	Fr(i,1,N)scanf("%d",&A[i]);
	Fr(i,1,M)scanf("%d",&B[i]);
	int b=lower_bound(B+1,B+1+M,0)-B;
//	int a=lower_bound(A+1,A+1+N,0)-A;
	
	Fr(i,1,M)if(Box(B[i],B[i])==1)C[++cc]=B[i];
//	Fr(i,1,cc)printf("%d ",C[i]);
	
	ll ans1=Ok(-Inf,0),ans2=Ok(0,Inf);
	/*printf("Pos %d %d %d %d %d %d\n"
	,Pos(-3,6),Pos(-3,7),Pos(-4,14)
	,Pos(-4,15),Pos(-3,15),Pos(-Inf,Inf));*/
	
	Fr(i,1,b-1)
	{
		int p=B[i];
		ll box=Box(p,0);
		ll pos=Pos(p,p+box-1);
		ll out=Ok(-Inf,p-1);
	//	printf("%d %d %d\n",box,pos,out);
		ans1=max(ans1,pos+out);
	}
	
	Fr(i,b,M)
	{
		int p=B[i];
		ll box=Box(0,p);
		ll pos=Pos(p-box+1,p);
		ll out=Ok(p+1,Inf);
	//	printf("%d %d %d\n",box,pos,out);
		ans2=max(ans2,pos+out);
	}
	printf("%lld\n",ans1+ans2);
	
	return 0;
}

int main()
{
	int t=0;
	scanf("%d",&t);
	while(t--)
	{
		mian();
		Fr(i,1,N)A[i]=0;
		Fr(i,1,M)B[i]=0;
		Fr(i,1,cc)C[i]=0;
		cc=0;
	}
	return 0;
}