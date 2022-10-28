#include<bits/stdc++.h>
using namespace std;
long int gcd(long int a, long int b) 
{ 
    // Everything divides 0  
    if (a == 0) 
       return b; 
    if (b == 0) 
       return a; 
   
    // base case 
    if (a == b) 
        return a; 
   
    // a is greater 
    if (a > b) 
        return gcd(a-b, b); 
    return gcd(a, b-a); 
}
int main()
{
    long int k,t,x,z;
    cin>>t;
    for(k=0;k<t;k++)
    {
        cin>>x>>z;
        if(gcd(x,z)==1)
        cout<<"Finite\n";
        else cout<<"Infinite\n";
    }
    return 0;
}