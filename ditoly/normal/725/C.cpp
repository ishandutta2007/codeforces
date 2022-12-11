#include<cstdio>
char s[30],ans[2][13];
int f[26];
inline void work(int&x,int&y,char c)
{
	if(x)if(y)y--;else x=0;
	else if(y<12)y++;else x=1;
	ans[x][y]=c;
}
int main()
{
	scanf("%s",s);
	int i,a,b,x,y;
	for(i=0;i<27;i++)
		if(f[s[i]-'A'])a=f[s[i]-'A'],b=i;
		else f[s[i]-'A']=i+1;
	if(a==b)return 0*puts("Impossible");
	ans[x=0][y=12-((b-a)>>1)]=s[b];
	for(i=a;i<b;i++)work(x,y,s[i]);
	for(i=b+1;i<27;i++)work(x,y,s[i]);
	for(i=0;i<a-1;i++)work(x,y,s[i]);
	for(i=0;i<13;i++)putchar(ans[0][i]);puts("");
	for(i=0;i<13;i++)putchar(ans[1][i]);
}