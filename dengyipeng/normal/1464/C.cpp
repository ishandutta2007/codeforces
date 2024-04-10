#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define maxn 100005
#define ll long long 
using namespace std;

int n,i,j,k;
ll S,a[maxn];

int main(){
	scanf("%d%lld",&n,&S); 
	char ch=getchar(); while (ch<'a'||ch>'z') ch=getchar();
	for(i=1;i<=n;i++) a[i]=1<<(ch-'a'),ch=getchar();
	S=S-a[n]+a[n-1];
	for(i=1;i<=n-2;i++) S+=a[i],a[i]=a[i]<<1;
	sort(a+1,a+1+n-2);
	for(i=n-2;i>=1;i--) if (S>=a[i]) S-=a[i];
	if (S==0) printf("YES\n"); else printf("NO\n");
}