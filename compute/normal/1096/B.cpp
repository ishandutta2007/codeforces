#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    long long ans=0;
    if(s[0]!=s[n-1])
    {
        int pos=0;
        while(s[pos]==s[0])
        {
            pos++,ans++;
        }
        pos=n-1;
        while(s[pos]==s[n-1])
        {
            pos--;ans++;
        }
        ans++;
    }
    else{
        long long pre=0,last=0;
        while(pre<n&&s[pre]==s[0])
            pre++;
        pre++;
        while(last<n&&s[n-last-1]==s[0])
            last++;
        last++;
        ans=pre*last%mod;
        if(pre==n+1) ans=1LL*n*(n+1)/2%mod;
    }
    cout<<ans<<endl;

}