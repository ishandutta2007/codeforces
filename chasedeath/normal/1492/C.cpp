#include <cstdio>
using namespace std;

const int N=1e6+10;

int n,m;
char s[N],t[N];
int pre[N],suf[N];

int main() {
	scanf("%d%d",&n,&m);
	scanf("%s%s",s+1,t+1);
	for(int i=1;i<=n;++i) pre[i]=pre[i-1]+(s[i]==t[pre[i-1]+1]);
	suf[n+1]=m+1;
	for(int i=n;i;--i) suf[i]=suf[i+1]-(s[i]==t[suf[i+1]-1]);
	int p=1;
	for(int i=2;i<=n;++i) while(p+1<i && pre[i-p-1] && suf[i] && pre[i-p-1]+1>=suf[i]) p++;
	printf("%d\n",p);
}