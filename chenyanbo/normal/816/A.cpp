#include<cstdio>
int a,b,t;
using namespace std;
inline int read()
{
	unsigned ret=0; char c=getchar();
	while(c>57 || c<48) c=getchar();
	while(c>=48&&c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

int main()
{
//	scanf("10%d:%d",&a,&b);  //1 2    05 39    5 39  //:
scanf("%d:%d",&a,&b);
	while(1)
	{
		if(a%10==b/10 && a/10==b%10)break;
		++t;
		++b;
		if(b==60){
			b=0;
			++a;
		}
		if(a==24)break;
	}
	printf("%d",t);
}