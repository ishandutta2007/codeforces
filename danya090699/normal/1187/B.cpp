#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector <int> sp[26];
    for(int a=0; a<n; a++) sp[s[a]-'a'].push_back(a);
    int m;
    cin>>m;
    for(int a=0; a<m; a++)
    {
        string t;
        cin>>t;
        int q[26];
        for(int b=0; b<26; b++) q[b]=0;
        for(int b=0; b<t.size(); b++)
        {
            q[t[b]-'a']++;
        }
        int an=0;
        for(int b=0; b<26; b++)
        {
            if(q[b])
            {
                an=max(an, sp[b][q[b]-1]+1);
            }
        }
        printf("%d\n", an);
    }
}