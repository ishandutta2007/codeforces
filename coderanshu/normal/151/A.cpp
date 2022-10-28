#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,k,l,c,d,p,nl,np;
   cin>>n>>k>>l>>c>>d>>p>>nl>>np;
   cout<<min(p/np,min(c*d,(k*l)/nl))/n;
   
    return 0; 
}