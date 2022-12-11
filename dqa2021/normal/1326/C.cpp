#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
#undef G
typedef long long ll;
const int Mod=998244353;

int n,k,p[200010],w[200010];
bool cmp(int x,int y){
	return p[x]>p[y];
}
int main()
{
	n=read(); k=read();
	for (int i=1;i<=n;i++) p[i]=read(),w[i]=i;
	sort(w+1,w+n+1,cmp);
	sort(w+1,w+k+1);
	int ans=1; ll tot=0;
	w[k+1]=n+1;
	for (int i=1;i<=k;i++){
		tot+=p[w[i]];
		if (i^k) ans=1LL*ans*(w[i+1]-w[i])%Mod;
	}
	printf("%lld %d\n",tot,ans);
	return 0;
}