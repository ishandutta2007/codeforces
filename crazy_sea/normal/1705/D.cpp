#include<cstdio>
using namespace std;
const int N=2e5+10;
int w1[N],w2[N],l1,l2,n,T;
char s1[N],s2[N];
int abs(int a){return a<0?-a:a;}
long long calc()
{
	if(s1[1]!=s2[1]||s1[n]!=s2[n]) return -1;
	l1=l2=0;
	for(int i=1;i<n;i++)
		if(s1[i]!=s1[i+1]) w1[++l1]=i;
	for(int i=1;i<n;i++)
		if(s2[i]!=s2[i+1]) w2[++l2]=i;
	if(l1!=l2) return -1;
	long long ans=0;
	for(int i=1;i<=l1;i++) ans=(ans+abs(w1[i]-w2[i]));
	return ans;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%s%s",&n,s1+1,s2+1);
		printf("%lld\n",calc());
	}
}