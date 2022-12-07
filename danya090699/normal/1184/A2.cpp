#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0;
    cin>>n;
    string s;
    cin>>s;
    int q[n+1];
    for(int a=n; a; a--)
    {
        if(n%a==0)
        {
            q[a]=n/a;
            for(int b=a+a; b<=n; b+=a) if(n%b==0) q[a]-=q[b];
            bool ok=1;
            for(int b=0; b<a; b++)
            {
                bool va=0;
                for(int c=b; c<n; c+=a) if(s[c]=='1') va^=1;
                if(va)
                {
                    ok=0;
                    break;
                }
            }
            if(ok) an+=q[a];
        }
    }
    cout<<an;
}