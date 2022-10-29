#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 1000005
#define ll long long
#define mo 998244353
using namespace std;

int n,i,j,k;
ll f[maxn],sum;

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++) for(j=i;j<=n;j+=i) f[j]++;
	for(i=1;i<=n;i++) (f[i]+=sum)%=mo,sum+=f[i];
	printf("%lld\n",f[n]);
}