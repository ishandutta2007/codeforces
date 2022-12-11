#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
struct flight
{
	int a,b,d;
	friend bool operator < (flight a,flight b){return a.d<b.d;}
}f[200];
struct matrix
{
	unsigned long long A[150][3],B[3][150];
	void clear(){memset(A,0,sizeof(A)),memset(B,0,sizeof(B));}
	friend matrix operator * (matrix &a,matrix &b)
	{
		#define check(i,j) (a.A[i][0]&b.B[0][j])||(a.A[i][1]&b.B[1][j])||(a.A[i][2]&b.B[2][j])
		static matrix c;
		c.clear();
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				if(check(i,j))c.A[i][j>>6]|=1ull<<(j&63),c.B[i>>6][j]|=1ull<<(i&63);
		return c;
		#undef check
	}
}t,s;
unsigned long long dp[3],nxt[3];
void trans(int p)
{
	#define check(i) (dp[0]&t.B[0][i])||(dp[1]&t.B[1][i])||(dp[2]&t.B[2][i])
	memset(nxt,0,sizeof(nxt));
	for(int i=1;i<=p;++i)
		if(dp[f[i].a>>6]>>(f[i].a&63)&1)nxt[f[i].b>>6]|=1ull<<(f[i].b&63);
	dp[0]=nxt[0],dp[1]=nxt[1],dp[2]=nxt[2];
	#undef check
}
void trans1(int b)
{
	matrix a=t;
	s.clear();
	for(int i=0;i<n;++i)s.A[i][i>>6]|=1ull<<(i&63),s.B[i>>6][i]|=1ull<<(i&63);
	for(;b;b>>=1,a=a*a)
		if(b&1)s=s*a;
	#define check(i) (dp[0]&s.B[0][i])||(dp[1]&s.B[1][i])||(dp[2]&s.B[2][i])
	memset(nxt,0,sizeof(nxt));
	for(int i=0;i<n;++i)
		if(check(i))nxt[i>>6]|=1ull<<(i&63);
	#undef check
	dp[0]=nxt[0],dp[1]=nxt[1],dp[2]=nxt[2];
}
int main()
{
	scanf("%d %d",&n,&m);
	int x,y,w;
	for(int i=1;i<=m;++i)
	{
		scanf("%d %d %d",&x,&y,&w);
		f[i]=flight{x-1,y-1,w};
	}
	sort(f+1,f+1+m);
	if(f[1].d)
	{
		printf("Impossible");
		return 0;
	}
	f[m+1].d=0x3f3f3f3f;
	dp[0]=1;
	for(int i=1;i<=m;++i)
	{
		t.A[f[i].a][f[i].b>>6]|=1ull<<(f[i].b&63);
		t.B[f[i].a>>6][f[i].b]|=1ull<<(f[i].a&63);
		while(i<m&&f[i+1].d==f[i].d)
		{
			++i;
			t.A[f[i].a][f[i].b>>6]|=1ull<<(f[i].b&63);
			t.B[f[i].a>>6][f[i].b]|=1ull<<(f[i].a&63);
		}
		int j,k;
		for(j=f[i].d+1,k=1;k<n&&j<=f[i+1].d;++j,++k)
		{
			trans(i);
			if((dp[(n-1)>>6]>>((n-1)&63))&1)
			{
				printf("%d",j);
				return 0;
			}
		}
		trans1(f[i+1].d+1-j);
	}
	printf("Impossible");
	return 0;
}