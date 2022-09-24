#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
int n;
ll a[MN],b[MN],s;
int main(){
	srand(time(0)+0x817+0x1926);
	scanf("%d",&n);
	F(i,1,n)scanf("%lld%lld",a+i,b+i),s+=a[i];
	while(1){
		ll x=(((rand()<<14^rand())<<14^rand())<<14^rand())<<14^rand(),S=0;
		x&=(1ll<<62)-1;
		F(i,1,n)S+=__builtin_popcountll(x&b[i])&1?-a[i]:a[i];
		if((S<0&&s>0)||(S>0&&s<0))return printf("%lld\n",x),0;
	}
	return 0;
}