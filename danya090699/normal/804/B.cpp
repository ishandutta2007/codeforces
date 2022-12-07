#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int n=s.size(), bq=0, ans=0, mod=1e9+7;
    for(int a=n-1; a>=0; a--)
    {
        if(s[a]=='a')
        {
            ans=(ans+bq)%mod;
            bq=(bq*2)%mod;
        }
        else bq=(bq+1)%mod;
    }
    cout<<ans;
}