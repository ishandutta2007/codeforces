#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        int q0=0, q1=0, ok=1;
        for(int a=0; a<k; a++)
        {
            int f0=0, f1=0;
            for(int b=a; b<s.size(); b+=k)
            {
                if(s[b]=='0') f0=1;
                if(s[b]=='1') f1=1;
            }
            if(f0 and f1) ok=0;
            if(f0) q0++;
            if(f1) q1++;
        }
        if(q0>k/2 or q1>k/2) ok=0;
        printf(ok ? "YES\n" : "NO\n");
    }
}