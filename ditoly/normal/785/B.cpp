#include<cstdio>
#include<algorithm>
using namespace std;
char B[1<<26],*S=B,C;int X;
inline int read()
{
	while((C=*S++)<'0'||C>'9');
	for(X=C-'0';(C=*S++)>='0'&&C<='9';)X=(X<<3)+(X<<1)+C-'0';
	return X;
}
#define INF 0x7FFFFFFF
int main()
{
	fread(B,1,1<<26,stdin);
	int n,x0=0,y0=INF,x1=0,y1=INF;
	for(n=read();n--;)x0=max(x0,read()),y0=min(y0,read());
	for(n=read();n--;)x1=max(x1,read()),y1=min(y1,read());
	printf("%d",max(0,max(x1-y0,x0-y1)));
}