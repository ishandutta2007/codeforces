#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
#undef G

int main()
{
	int T=read();
	while (T--){
		int n=read();
		if (n==1){puts("-1");continue;}
		printf("2");
		for (int i=2;i<=n;i++) printf("3");
		puts("");
	}
	return 0;
}