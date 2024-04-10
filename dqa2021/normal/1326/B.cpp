#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G

int n;
int main()
{
	n=read();
	for (int i=1,t=0;i<=n;i++){
		int w=read()+t;
		printf("%d ",w);
		t=max(t,w);
	}
	return 0;
}