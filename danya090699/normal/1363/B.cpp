#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n=s.size(), pref[2][n+1], an=n;
        pref[0][0]=0, pref[1][0]=0;
        for(int a=0; a<n; a++)
        {
            pref[0][a+1]=pref[0][a];
            pref[1][a+1]=pref[1][a];
            pref[s[a]-'0'][a+1]++;
        }
        for(int a=0; a<=n; a++)
        {
            an=min(an, min(pref[0][a], pref[1][a])+min(pref[0][n]-pref[0][a], pref[1][n]-pref[1][a]));
        }
        cout<<an<<"\n";
    }
}