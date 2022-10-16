#include<iostream>  
using namespace std; 
int main()  
{  
    long long ans=0;  
    long long n,k,a,b;  
    cin>>n>>k>>a>>b;
    if(k==1) {  
        cout<<(n-1)*a;  
        return 0;  
    }  
    while(n>1)
	{  
        if(n<k)
		{  
            ans+=(n-1)*a;  
            n=1;  
            break;  
        }  
        long long t=n/k;   
        if(n%k)
		{   
            long long r=n-t*k;  
            ans+=min(r*a+b,(n-t)*a);   
        }
		else  
            ans+=min((n-t)*a,b);   
        n/=k;  
    }
    cout<<ans;
    return 0;  
}