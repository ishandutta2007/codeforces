//  228

#include<bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	ios::sync_with_stdio(0);
	int n;cin>>n;
	int a=1,b=0,ans=INT_MAX,f,s;
	while(a<n)
	{
	    if(4*a<=n and (n-4*a)%7==0)
	     {b=(n-4*a)/7;
	     if(a+b<ans){
	         f=a;
	         s=b;
	         ans=a+b;
	     }}
	     a++;
	}
	if(ans==INT_MAX and n%4 and n%7)cout<<-1<<endl;
	else
	{
	    if(n%4==0)
	    {
	        if(ans>n/4)
	        {
	            f=n/4;
	            s=0;
	        }
	    }
	    if(n%7==0)
	    {
	        if(ans>n/7){
	            s=n/7;
	            f=0;
	        }
	    }
	    while(f--)cout<<4;
	    while(s--)cout<<7;
	    cout<<endl;
	}
	return 0;
}