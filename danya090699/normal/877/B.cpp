#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int n=s.size(), an=0;
    int pref[n+1][2];
    pref[0][0]=0, pref[0][1]=0;
    for(int a=0; a<n; a++)
    {
        pref[a+1][0]=pref[a][0], pref[a+1][1]=pref[a][1];
        if(s[a]=='a') pref[a+1][0]++;
        else pref[a+1][1]++;
    }
    for(int a=0; a<=n; a++)
    {
        for(int b=a; b<=n; b++) an=max(an, pref[a][0]+(pref[b][1]-pref[a][1])+(pref[n][0]-pref[b][0]));
    }
    cout<<an;
}