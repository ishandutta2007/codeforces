#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, n2, k, su=0;
    cin>>n>>k;
    n2=n;
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        su+=x;
    }
    while(n*(k*2-1)>su*2)
    {
        su+=k, n++;
    }
    cout<<n-n2;
}