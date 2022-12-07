#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin>>n>>k;
    int an[k];
    for(int a=0; a<k-1; a++)
    {
        for(int b=2; b<=n; b++)
        {
            if(n%b==0)
            {
                an[a]=b, n/=b;
                break;
            }
        }
    }
    if(n==1) cout<<-1;
    else
    {
        an[k-1]=n;
        for(int a=0; a<k; a++) cout<<an[a]<<" ";
    }
}