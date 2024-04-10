#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n,t;
    cin>>t;cin.get();
    char s[105];
    for(int i=1;i<=t;i++)
    {
        cin.getline(s,105);
        n=strlen(s);
        if(n>10)
            cout<<s[0]<<n-2<<s[n-1]<<"\n";
        else
            cout<<s<<"\n";
    }
    return 0;
}
/**

**/