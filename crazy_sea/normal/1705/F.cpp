#include<cstdio>
#include<vector>
using namespace std;
const int N=2010;
int n,ans[N],f[N][N],k,p;
char s[N];
int ask(int*a)
{
	if(p) return 0;
	int x,y,c=0;
	for(int i=1;i<=n;i++)
		if(a[i]==1) c++,s[i]='F';
		else s[i]='T';
	printf("%s\n",s+1);
	fflush(stdout);
	scanf("%d",&x);
	if(x==n) {p=1;return 0;}
	for(int i=1;i<=n;i++)
		if(a[i]==-1) c--,s[i]='F';
		else s[i]='T';
	printf("%s\n",s+1);
	fflush(stdout);
	scanf("%d",&y);
	if(y==n) {p=1;return 0;}
	return (y+c-x)/2;
}
void solve(vector<int> c,int a,int b,int l)
{
	if(l>=n) return;
	if(a==0)
	{
		ans[l+1]=c[1];
		return;
	}
	b-=a;
	for(int i=1;i<=a;i++)
		ans[l+b+i]=(c[i]+c[i+a])&1;
	for(int i=1;i<=a;i++) c[i]-=ans[l+b+i];
	vector<int> s1,s2;
	s1.resize(a+2);
	s2.resize(a+2);
	for(int i=1;i<=a;i++)
		s1[i]=(c[i]+c[i+a])/2,s2[i]=(c[i]-c[i+a])/2;
	b/=2;
	solve(s1,a/2,b,l);
	solve(s2,a/2,b,l+b);
}
int main()
{
	scanf("%d",&n);
	int a=1,b=1;
	f[1][1]=1;
	while(b<n)
	{
		for(int j=1;j<=a;j++)
			for(int k=1;k<=b;k++)
				f[j][k+b]=f[j+a][k]=f[j][k],f[j+a][k+b]=-f[j][k];
		for(int j=1;j<=a;j++)
			f[j][j+b*2]=1;
		b=b*2+a;
		a*=2;
	}
	vector<int> s;
	s.resize(a*2+2);
	for(int i=1;i<=a;i++) s[i]=ask(f[i]);
	if(p) return 0;
	solve(s,a/2,b,0);
	for(int i=1;i<=n;i++)
		printf("%c",ans[i]?'T':'F');
	printf("\n");
	fflush(stdout);
}