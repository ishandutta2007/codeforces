#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int qq;
    cin>>qq;
    while(qq)
    {
        qq--;
        string s, t, p;
        cin>>s>>t>>p;
        int q[26], yk=0, ok=1;
        for(int a=0; a<26; a++) q[a]=0;
        for(int a=0; a<p.size(); a++) q[p[a]-'a']++;
        for(int a=0; a<s.size(); a++)
        {
            while(yk<t.size() and t[yk]!=s[a]) q[t[yk]-'a']--, yk++;
            if(yk==t.size()) ok=0;
            else yk++;
        }
        while(yk<t.size()) q[t[yk]-'a']--, yk++;
        for(int a=0; a<26; a++) if(q[a]<0) ok=0;
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
}