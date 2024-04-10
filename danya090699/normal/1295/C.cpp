#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T)
    {
        T--;
        string s, t;
        cin>>s>>t;
        int n=s.size(), ne[n+1][26];
        for(int i=0; i<26; i++) ne[n][i]=-1;
        for(int a=n-1; a>=0; a--)
        {
            for(int i=0; i<26; i++) ne[a][i]=ne[a+1][i];
            ne[a][s[a]-'a']=a+1;
        }
        int p=0, an=1;
        for(int a=0; a<t.size(); a++)
        {
            int sy=t[a]-'a';
            if(ne[p][sy]==-1)
            {
                p=0, an++;
            }
            if(ne[p][sy]==-1)
            {
                an=-1;
                break;
            }
            else p=ne[p][sy];
        }
        cout<<an<<"\n";
    }
}