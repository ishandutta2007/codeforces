#include<bits/stdc++.h>
using namespace std;
int T=233;
int main(){
	srand(time(NULL));
	cin>>T;
	while(T--){
		long long a,b,c;
		a=rand()*2+2;b=rand()*2+2;
		scanf("%lld%lld",&a,&b);
		if(a>b)
			printf("%lld\n",a*b+b);
		else if(b%a==0)
			printf("%lld\n",a);
		else
			printf("%lld\n",b-b%a/2);
	}
}