#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a,ans;
int main()
{
	scanf("%d",&a);
	if(a>>5&1)ans+=32;
	if(a&1)ans+=16;
	if(a>>2&1)ans+=8;
	if(a>>3&1)ans+=4;
	if(a>>1&1)ans+=2;
	if(a>>4&1)++ans;
	printf("%d",ans);
	return 0;
}