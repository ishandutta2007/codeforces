#include<bits/stdc++.h>
using namespace std;
// if if concept
int main()
{
    string a;
    cin>>a;
    int k,n=0,i=0,e=0,t=0;
    for(k=0;k<a.length();k++)
    {
        if(a[k]=='n')n++;
        if(a[k]=='i')i++;
        if(a[k]=='e')e++;
        if(a[k]=='t')t++;
    }
    cout<<min(i,min(e/3,min(t,(n-1)/2)));
    return 0;
}