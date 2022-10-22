#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e6+10,B=N/2;
int T,n,t[N];
char str[N];
bool chk(int x)
{
	if(t[x-1]==0) return 0;
	if(t[x]==0) return 1;
	if(t[x-1]>1) return 1;
	return 0;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",str);
		n=strlen(str);
		for(int i=0,s=0;i<n;i++)
			if(str[i]=='0') s--,t[B+s]++;
			else t[B+s]++,s++;
		for(int i=0,s=0;i<n;i++)
			if(chk(B+s)) t[B+s-1]--,s--,putchar('0');
			else t[B+s]--,s++,putchar('1');
		putchar('\n');
	}
}