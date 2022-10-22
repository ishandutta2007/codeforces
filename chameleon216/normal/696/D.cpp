#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <queue>
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

const int MX=205;
int N,A[MX];
ll L;
char S[MX];

int C[MX][26],F[MX],id[MX],V[MX],ac=1;
int Ins()
{
	int x=1,n=strlen(S);
	Fr(i,0,n-1)
	{
		int k=S[i]-'a';
		if(!C[x][k])C[x][k]=++ac;
		x=C[x][k];
	}
	return x;
}
void Build()
{
	queue<int> q;
	q.push(1);
	Fr(k,0,25)C[0][k]=1;
	int c=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop(),id[++c]=x;
		Fr(k,0,25)
		{
			if(C[x][k])F[C[x][k]]=C[F[x]][k],q.push(C[x][k]);
			else C[x][k]=C[F[x]][k];
		}
	}
}

struct Matrix
{
	ll x[MX][MX];
	Matrix(){memset(x,0xc0,sizeof(x));}
};
Matrix operator*(const Matrix& a,const Matrix& b)
{
	Matrix c;
	Fr(i,1,ac)Fr(j,1,ac)Fr(k,1,ac)
		c.x[i][k]=max(c.x[i][k],a.x[i][j]+b.x[j][k]);
	return c;
}
Matrix Pow(Matrix a,ll b)
{
	Matrix r;
	Fr(i,1,ac)r.x[i][i]=0;
	while(b)
	{
		if(b&1)r=r*a;
		a=a*a,b>>=1;
	}
	return r;
}

int main()
{
	scanf("%d%lld",&N,&L);
	Fr(i,1,N)scanf("%d",&A[i]);
	Fr(i,1,N)scanf("%s",S),V[Ins()]+=A[i];
	Build();
	Fr(i,2,ac)V[id[i]]+=V[F[id[i]]];
	
	Matrix a;
	Fr(x,1,ac)Fr(k,0,25)
		a.x[x][C[x][k]]=V[C[x][k]];
	a=Pow(a,L);
	printf("%lld\n",*max_element(a.x[1]+1,a.x[1]+ac+1));
	
	return 0;
}