#include<cstdio>
#include<algorithm>
using namespace std;
int n,l,r,ql,qr,ans;
int w[100005],sl[100005],sr[100005];
int main()
{
	scanf("%d%d%d%d%d",&n,&l,&r,&ql,&qr);
	for(int i=1;i<=n;i++)
		scanf("%d",w+i),sl[i]=sl[i-1]+w[i]*l;
	for(int i=n;i;i--)
		sr[i]=sr[i+1]+w[i]*r;
	ans=(1u<<31)-1;
	for(int i=0;i<=n;i++)
		ans=min(ans,sl[i]+sr[i+1]+max(i-(n-i)-1,0)*ql+max(n-i-i-1,0)*qr);
	printf("%d\n",ans);
	return 0;
}