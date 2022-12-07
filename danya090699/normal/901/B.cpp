#include <bits/stdc++.h>
using namespace std;
const int sz=160;
bitset <sz> ar[sz];
int main()
{
    int n;
    cin>>n;
    ar[0][0]=1, ar[1][1]=1;
    for(int a=2; a<=n; a++) ar[a]=(ar[a-1]<<1)^ar[a-2];
    cout<<n<<"\n";
    for(int a=0; a<=n; a++) cout<<ar[n][a]<<" ";
    cout<<"\n"<<n-1<<"\n";
    for(int a=0; a<n; a++) cout<<ar[n-1][a]<<" ";
}