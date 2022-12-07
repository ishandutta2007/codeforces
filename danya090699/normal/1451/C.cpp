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
        string s, s2;
        cin>>s>>s2;
        int su=0, ok=1, q[26];
        for(int i=0; i<26; i++) q[i]=0;
        sort(s.begin(), s.end());
        sort(s2.begin(), s2.end());
        for(int a=0; a<n; a++)
        {
            if(s[a]<=s2[a])
            {
                for(int i=s[a]-'a'; i<(s2[a]-'a'); i++) q[i]++;
            }
            else ok=0;
        }
        for(int i=0; i<26; i++) if(q[i]%k) ok=0;
        if(ok) cout<<"Yes\n";
        else cout<<"No\n";
    }
}