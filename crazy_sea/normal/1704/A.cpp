#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
const int N=1e6+10;
char s1[N],s2[N];
int n,m,T;
bool chk()
{
	if(m>n) return 0;
	for(int i=1;i<m;i++)
		if(s1[n-i]!=s2[m-i]) return 0;
	bool p=0;
	for(int i=0;i<=n-m;i++)
		if(s1[i]==s2[0]) p=1;
	return p;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%s%s",&n,&m,s1,s2);
		printf("%s\n",chk()?"YES":"NO");
	}
}