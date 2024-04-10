#include<cstdio>
#define N 1000010
#define write(a) {printf("%d\n",a);return;}
using namespace std;
const int inf=0x3f3f3f3f;
char s[N];
int n,T,ans,lst,s1,s2,s3;
bool chk(int a,int b,char e,char f)
{
	return s[a]==e&&s[b]==f;
}
void work()
{
		for(int i=1;i+1<=n;i++)
		{
			if(s[i]=='a'&&s[i+1]=='a') write(2)
		}
		for(int i=1;i+2<=n;i++)
		{
			if(s[i]=='a'&&s[i+2]=='a') write(3)
		}
		for(int i=1;i+2<=n;i++)
		{
			if(s[i]=='a'&&s[i+3]=='a')
			{
				if(s[i+1]=='b'&&s[i+2]=='c') write(4)
				if(s[i+1]=='c'&&s[i+2]=='b') write(4)
			}
		}
		for(int i=1;i+6<=n;i++)
		{
			if(s[i]=='a'&&s[i+3]=='a'&&s[i+6]=='a')
			{
				if(chk(i+1,i+2,'c','c')&&chk(i+4,i+5,'b','b')) write(7)
				if(chk(i+1,i+2,'b','b')&&chk(i+4,i+5,'c','c')) write(7)
			}
		}
		printf("-1\n");
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%s",&n,s+1);
		work();
	}
}