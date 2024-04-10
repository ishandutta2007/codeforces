#include <bits/stdc++.h>
using namespace std;
int f(string &s)
{
    int n=s.size();
    int pf[n];
    pf[0]=0;
    for(int a=1; a<n; a++)
    {
        int t=pf[a-1];
        while(t)
        {
            if(s[t]!=s[a]) t=pf[t-1];
            else break;
        }
        if(s[t]==s[a]) t++;
        pf[a]=t;
    }
    return pf[n-1];
}
main()
{
    //freopen("input.txt", "r", stdin);
    string re;
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        string s, s2;
        cin>>s;
        s2=s+"#";
        int q=min(re.size(), s.size());
        for(int b=re.size()-q; b<re.size(); b++) s2.push_back(re[b]);
        int same=f(s2);
        for(same; same<s.size(); same++) re.push_back(s[same]);
    }
    cout<<re;
}