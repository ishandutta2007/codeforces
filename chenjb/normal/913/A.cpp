#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define N 100005
using namespace std;
long long n,m;
int main(){
	scanf("%I64d%I64d",&n,&m);
	if(n<40)printf("%I64d\n",m%(1ll<<n));else printf("%I64d\n",m);
	return 0;
}