#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2e5+10;
int T,n,t[300];
char str[N];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",str);
		n=strlen(str);
		for(int i=0;i<n;i++) t[str[i]]++;
		int w=0;
		while(t[str[w]]>1) t[str[w]]--,w++;
		for(int i=w;i<n;i++) putchar(str[i]);
		for(int i='a';i<='z';i++) t[i]=0;
		putchar('\n');
	}
}