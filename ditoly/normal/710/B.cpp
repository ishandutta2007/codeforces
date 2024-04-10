#include<cstdio>
void read(int&x)
{
	x=0;char c;int f=1;
	do{c=getchar();if(c=='-')f=-1;}while(c<'0'||c>'9');
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
#include<algorithm>
using namespace std;
#define MAXN 300000
int x[MAXN+5];
int main()
{
	int n,i;
	read(n);
	for(i=0;i<n;i++)read(x[i]);
	sort(x,x+n);
	printf("%d",x[(n-1)>>1]);
}