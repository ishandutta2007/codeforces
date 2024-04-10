#include<cstdio>
#include<set>
using namespace std;
int T,n,x;
set<int>st;
int main()
{
	for(int i=1;i<=10005;i++)st.insert(i*i);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int ok=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(st.find(x)==st.end())ok=1;
		}
		if(ok)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}