#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i*=2)
    {
        int q=n/i;
        if(q==3)
        {
            cout<<i<<" "<<i<<" "<<i*3;
            break;
        }
        for(int b=i; b<=n; b+=i*2) printf("%d ", i);
    }
}