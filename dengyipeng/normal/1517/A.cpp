#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long 
#define maxn 18
using namespace std;

int T,i;
ll n;

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%lld",&n);
		if (n%2050) printf("-1\n"); else {
			int cnt=0; n/=2050;
			while (n) cnt+=n%10,n/=10;
			printf("%d\n",cnt);
		}
	}
}