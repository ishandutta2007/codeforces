#include <bits/stdc++.h>

using namespace std;

bool prime(int x)
{
    if(x<=1)
        return 0;
    for(int i=2;i*i<=x;i++)
        if(x%i==0)
            return 0;
    return 1;
}

const int N=1000000+5;

bool cp[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i=2;i<N;i++)
        cp[i]=(!prime(i));
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        if(cp[i] && cp[n-i])
        {
            cout<<i<<" "<<n-i<<"\n";
            return 0;
        }
    return 0;
}