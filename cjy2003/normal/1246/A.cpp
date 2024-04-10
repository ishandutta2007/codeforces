#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,p;
int cnt(int n)
{
	int res=0;
	for(int i=0;i<32;++i)res+=n>>i&1;
	return res;
}
int main()
{
	scanf("%d %d",&n,&p);
	for(int i=0;i<=100;++i,n-=p)
		if(n>=i&&cnt(n)<=i)return printf("%d",i),0;
	printf("-1");
	return 0;
}