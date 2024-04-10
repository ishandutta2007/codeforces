#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long 
using namespace std;

int n,m,i,j,k;
ll x,y,g;

ll gcd(ll x,ll y){return (x%y==0)?y:gcd(y,x%y);}

int main(){
	scanf("%d%d",&n,&m); scanf("%lld",&x);
	for(i=1;i<n;i++) {
		scanf("%lld",&y);
		if (x!=y) g=(g==0)?abs(x-y):gcd(g,abs(x-y));
	}
	for(i=1;i<=m;i++){
		scanf("%lld",&y);
		printf("%lld ",(g==0)?x+y:gcd(g,x+y));
	}
}