#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000005;
const ll mod=998244353;
int n,m;
ll p;
ll a[N],b[N];
int main(){
	int i,j;
	scanf("%d%d%lld",&n,&m,&p);
	for(i=0;i<n;i++) scanf("%lld",&a[i]);
	for(i=0;i<m;i++) scanf("%lld",&b[i]);
	for(i=0;i<n;i++) if(a[i]%p) break;
	for(j=0;j<m;j++) if(b[j]%p) break;
	printf("%d",i+j);
	return 0;
}