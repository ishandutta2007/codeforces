#include <bits/stdc++.h>
using namespace std;
const int nmax=100000;
int n,v[nmax+5];
int prefix[nmax+5],sufix[nmax+5];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<=n;i++)prefix[i]=prefix[i-1]+v[i];
    for(int i=n;i>=1;i--)sufix[i]=sufix[i+1]+v[i];
    for(int i=1;i<=n;i++)
        if(prefix[i]>sufix[i])
        {
            cout<<i-1<<" "<<n-i+1;
            return 0;
        }
    cout<<n<<" 0";
    return 0;
}
/**

**/