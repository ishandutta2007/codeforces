#include<cstdio>  
using namespace std;  
long long n,k,ans=1;  
int main(){  
    scanf("%I64d%I64d",&n,&k);  
    if(k==1){
		printf("%I64d\n",n);
    }else{
    	while(n>>=1)ans<<=1;
	    printf("%I64d\n",(ans<<1)-1);  
	}
    return 0;  
}