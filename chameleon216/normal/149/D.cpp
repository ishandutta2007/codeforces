#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <iostream>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
using namespace std;
typedef long long ll;

template<typename T>
void PutArr(T x[],int n,const char* e=" ")
{
	Fo(i,1,n)cout<<x[i]<<e;
	cout<<x[n];
}
#define DArr(x,n) (printf(#x"[%d] = [",n),PutArr(x,n,", "),printf("]\n"))
#define DArr0(x,n) (printf(#x"[%d] = [",n),PutArr(x-1,n,", "),printf("]\n"))

template<typename T,int U>
void PutMat(T a[][U],int n,int m,int s=1)
{
	Fr(i,s,n){Fr(j,s,m)cout<<a[i][j]<<' ';cout<<'\n';}
	cout<<'\n';
}
#define DMat(a,n,m) (printf(#a"[%d][%d]:\n",n,m),PutMat(a,n,m))
#define DMat0(a,n,m) (printf(#a"[%d][%d]:\n",n,m),PutMat(a,n-1,m-1,0))



const int MX=750,Mod=1000000007;
int N;
char S[MX];

int C[MX],stk[MX],tp;
char isok[MX][MX];
void Match()
{
	Fr(i,1,N)
	{
		char c=S[i];
		if(c=='(')stk[++tp]=i;
		else C[i]=stk[tp],C[stk[tp]]=i,--tp;
	}
	Fr(i,1,N)Fr(j,i+1,N)
		if(C[j]==i||isok[i][C[j]-1])isok[i][j]=1;
}

bool Check(int l,int r,int c,int d)
{
	if(C[l]==r&&((c>0)^(d>0))==0)return 0;
	if(r-l==1&&c&&d&&c==d)return 0;
	return 1;
}

ll f[MX][MX][3][3];
void Solve()
{
	Fl(l,N,1)Fr(r,l+1,N)if(isok[l][r])
		Fr(c,0,2)Fr(d,0,2)if(Check(l,r,c,d))
	{
		int len=r-l+1;
		ll& dp=f[l][r][c][d];
		if(len==2)dp=1;
		else if(C[l]==r)
		{
			Fr(i,0,2)Fr(j,0,2)
				if(Check(l,l+1,c,i)&&Check(r-1,r,j,d))
					dp+=f[l+1][r-1][i][j];
		}
		else
		{
			int L=C[r]-1,R=C[r];
			Fr(i,0,2)Fr(j,0,2)
				if(Check(L,R,i,j))
					dp+=f[l][L][c][i]*f[R][r][j][d];
		}
		dp%=Mod;
	}
}


int main()
{
	scanf("%s",S+1),N=strlen(S+1);
	Match();
	Solve();
	ll ans=0;
	Fr(c,0,2)Fr(d,0,2)ans+=f[1][N][c][d];
	printf("%lld\n",ans%Mod);
	return 0;
}