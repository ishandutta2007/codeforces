#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100005
int T, n, px, py, cu, cd, cl, cr;
char s[N];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &px, &py);
		scanf("%s", s+1);
		n=strlen(s+1);
		cu=cd=cl=cr=0;
		for(int i=1; i<=n; ++i)
		{
			if(s[i]=='R') ++cr;
			if(s[i]=='L') ++cl;
			if(s[i]=='U') ++cu;
			if(s[i]=='D') ++cd;
		}
		if(-cl>px||cr<px||-cd>py||cu<py) puts("NO");
		else puts("YES");
	}
	return 0;
}