#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 55
int T, n, tp[3];
char t[N];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%s", t+1);
		n=strlen(t+1);
		tp[0]=tp[1]=tp[2]=0;
		tp[t[1]-'A']=1, tp[t[n]-'A']=2;
		int id=(tp[0]?tp[1]?2:1:0);
		tp[id]=1;
		int a=0;
		for(int i=1; i<=n; ++i)
		{
			if(tp[t[i]-'A']==1) ++a;
			else --a;
			if(a<0) break;
		}
		if(!a) { puts("YES"); continue; }
		
		tp[id]=2;
		a=0;
		for(int i=1; i<=n; ++i)
		{
			if(tp[t[i]-'A']==1) ++a;
			else --a;
			if(a<0) break;
		}
		if(!a) { puts("YES"); continue; }
		puts("NO");
	}
	return 0;
}