#include<cstdio>
int b[101],n,ans,a;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a),b[a]++;
    for(int i=1;i<=100;i++)if(b[i]>ans)ans=b[i];
	printf("%d",ans);
	return 0;
}