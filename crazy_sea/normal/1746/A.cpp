#include<cstdio>
using namespace std;
int n,k,T,a,t[2];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&a),t[a]=1;
		printf("%s\n",(n<k-1)^t[n>=k-1]?"Yes":"No");
		t[0]=t[1]=0;
	}
}