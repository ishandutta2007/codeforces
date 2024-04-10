#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, q;
        cin>>n>>q;
        string s;
        cin>>s;
        for(int a=0; a<q; a++)
        {
            int l, r, ok=0;
            cin>>l>>r;
            l--, r--;
            for(int b=0; b<l; b++) if(s[b]==s[l]) ok=1;
            for(int b=r+1; b<n; b++) if(s[b]==s[r]) ok=1;
            if(ok) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}