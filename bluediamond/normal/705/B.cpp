#include <bits/stdc++.h>

using namespace std;

const int nmax=100000;

int n,v[nmax+5],WIN=2;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        if(v[i]%2==0)
            WIN++;
        WIN%=2;
        cout<<2-WIN<<"\n";
    }
    return 0;
}
/**

**/