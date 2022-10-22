#include<bits/stdc++.h>
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
#define LL long long
#define N 100
#define M 100
using namespace std;
int n,m;
char Map[N+5][M+5];
int read()
{
	int x=0,f=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') f=-1,ch=getchar();
	while(ch>='0'&&ch<='9') (x*=10)+=ch-'0',ch=getchar();
	return x*=f;
}
void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
void read_char(char &ch)
{
	ch=getchar();
	while(ch==' '||ch=='\n') ch=getchar();
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) read_char(Map[i][j]);
	for(int i=1;i<=n;i++) 
		for(int j=1;j<=m;j++)
		{
			if(Map[i][j]=='*') continue;
			int tot=0;
			for(int q=i-1;q<=i+1;q++) for(int p=j-1;p<=j+1;p++) tot+=(Map[q][p]=='*');
			if((Map[i][j]=='.'&&tot)||(Map[i][j]!='.'&&Map[i][j]-'0'!=tot)) return puts("NO"),0;
		}
	puts("YES");
	return 0;
}