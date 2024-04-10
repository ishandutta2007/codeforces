#include<bits/stdc++.h>
using namespace std;
const long long c=1000000007;
long long power(long long a,long long b){
    if (b==0) return 1;
    if (b%2==0){
        long long t=power(a,b/2)%c;
        return t%c * t%c;
    }
    else{
        long long t=power(a,b/2)%c;
        return t%c * t%c * a%c;
    }
}
int main()
{
	long long n,m;
	//scanf("%I64d%I64d",&n,&m);
	//printf("%I64d",pow(pow(2,m)-1,n));
	cin>>n>>m; cout<<power(power(2,m)-1,n);
	return 0;
}