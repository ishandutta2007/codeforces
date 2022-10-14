#include<bits/stdc++.h>
using namespace std;
unsigned long long MOD=998244353;
unsigned long long power(unsigned long long a,unsigned long long b){
    if (b==0) return 1;
    if (b%2==0){
        unsigned long long t=power(a,b/2)%MOD;
        return t%MOD * t%MOD;
    }
    else{
        unsigned long long t=power(a,b/2)%MOD;
        return t%MOD * t%MOD * a%MOD;
    }
}
int main()
{
	unsigned long long a,b,c,d;
	cin>>a>>b>>c>>d;
	if((a&1) && (b&1))
	{
		cout<<power(d-c+1,a*b);
return 0;
	}
	unsigned long long g=a*b,x=(d>>1)-(c-1>>1),y=d-c+1-x;//
	cout<< (power(d-c+1,g)+power(x-y+998244353LL,g))%998244353LL*power(2LL,998244351LL)%998244353LL;
	return 0;
}