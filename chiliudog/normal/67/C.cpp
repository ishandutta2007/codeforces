#include<cstdio>
#include<cstring>
#define INF 0x3f3f3f3f
using namespace std;

const int N=4005;
char A[N],B[N];
int t1,t2,t3,t4;
int n,m,f[N][N];
int x[N][30],y[N][30];

inline int min(const int &a,const int &b){return a<b?a:b;}
int main()
{
	scanf("%d%d%d%d",&t1,&t2,&t3,&t4);
	scanf("%s",A+1);
	scanf("%s",B+1);
	n=strlen(A+1);
	m=strlen(B+1);
	for(int i=n;i>=1;i--)
		for(char k='a';k<='z';k++)
			for(int j=i;j>=1;j--)
				if(A[j]==k)
				{
					x[i][k-'a'+1]=j;
					break;
				}
	for(int i=m;i>=1;i--)
		for(char k='a';k<='z';k++)
			for(int j=i;j>=1;j--)
				if(B[j]==k)
				{
					y[i][k-'a'+1]=j;
					break;
				}
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			f[i][j]=INF;
	
	for(int i=0;i<=n;i++)f[i][0]=i*t2;
	for(int i=0;i<=m;i++)f[0][i]=i*t1;
	
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			f[i][j]=min(f[i][j],f[i][j-1]+t1);
			f[i][j]=min(f[i][j],f[i-1][j]+t2);
			f[i][j]=min(f[i][j],f[i-1][j-1]+t3*(A[i]!=B[j]));
			int k=x[i-1][B[j]-'a'+1],l=y[j-1][A[i]-'a'+1];
			if(k&&l)
    			f[i][j]=min(f[i][j],f[k-1][l-1]+t4+t2*(i-k-1)+t1*(j-l-1));
		}
	printf("%d",f[n][m]);
	return 0;
}