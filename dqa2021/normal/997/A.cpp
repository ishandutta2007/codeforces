#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,x,y,top,k;
char str[300010],s[300010];
ll ans;
int main()
{
	scanf("%d%d%d%s",&n,&x,&y,str+1);
	for (int i=1;i<=n;i++) if (i==1||str[i]!=str[i-1]) s[++top]=str[i];
	for (int i=1;i<=top;i++) if (s[i]=='0') k++;
	if (!k){return puts("0"),0;}
	ans=min((ll)(k-1)*x+y,(ll)k*y);
	printf("%I64d\n",ans);
	return 0;
}