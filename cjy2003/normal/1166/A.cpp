#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,ans;
int cnt[26]; 
char s[100];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		++cnt[s[1]-'a'];
	}
	for(int i=0;i<26;++i)
		ans+=cnt[i]/2*(cnt[i]/2-1)/2+(cnt[i]-cnt[i]/2)*(cnt[i]-cnt[i]/2-1)/2;
	printf("%d",ans);
	return 0;
}