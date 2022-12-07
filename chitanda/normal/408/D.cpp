#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long
#define M 1000000007

int n;
int p[1250],f[1250];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	f[1]=0;
	for(int i=2;i<=n+1;i++)
		f[i]=((2*f[i-1])%M-f[p[i-1]]+2)%M;
	printf("%d\n",(f[n+1]+M)%M);
	return 0;
}