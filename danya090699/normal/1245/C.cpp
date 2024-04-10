#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int n=s.size(), f[n+1], an=1, yk=0;
    f[0]=1, f[1]=1;
    for(int a=2; a<=n; a++) f[a]=(f[a-1]+f[a-2])%mod;
    while(yk<n)
    {
        if(s[yk]=='w' or s[yk]=='m') an=0, yk++;
        else if(s[yk]=='u' or s[yk]=='n')
        {
            char sy=s[yk];
            int q=0;
            while(yk<n)
            {
                if(s[yk]==sy) yk++, q++;
                else break;
            }
            an=(1ll*an*f[q])%mod;
        }
        else yk++;
    }
    cout<<an;
}