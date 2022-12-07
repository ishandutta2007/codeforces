#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int be=1e9, bq, an[n];
    for(int a=1; a<=n; a++)
    {
        an[a-1]=a;
        int q=n/a+(n%a>0);
        if(a+q<be)
        {
            be=a+q, bq=a;
        }
    }
    for(int a=0; a<n; a+=bq)
    {
        int rg=min(a+bq, n);
        reverse(an+a, an+rg);
    }
    for(int a=0; a<n; a++) cout<<an[a]<<" ";
}