#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int a, b;
        cin>>a>>b;
        if(a-b==1)
        {
            int x=a+b, ok=0;
            for(int c=2; c*c<=x; c++)
            {
                if(x%c==0) ok=1;
            }
            if(ok) cout<<"NO\n";
            else cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
}