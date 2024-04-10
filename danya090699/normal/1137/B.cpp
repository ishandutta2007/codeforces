#include <bits/stdc++.h>
using namespace std;
const int sz=5e5+10;
int pref_func(string &s)
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
int main()
{
    //freopen("input.txt", "r", stdin);
    char ss[sz], tt[sz];
    scanf("%s%s", ss, tt);
    string s, t;
    int le[]={0, 0};
    for(int a=0; ss[a]; a++)
    {
        le[ss[a]-'0']++;
        s.push_back(ss[a]);
    }
    int tq[]={0, 0};
    for(int a=0; tt[a]; a++)
    {
        tq[tt[a]-'0']++;
        t.push_back(tt[a]);
    }
    int l=pref_func(t), q[]={0, 0};
    for(int a=l; a<t.size(); a++) q[t[a]-'0']++;
    string an;
    if(le[0]>=tq[0] and le[1]>=tq[1])
    {
        an+=t, le[0]-=tq[0], le[1]-=tq[1];
        while(1)
        {
            if(le[0]>=q[0] and le[1]>=q[1])
            {
                an+=t.substr(l, t.size()-l);
                le[0]-=q[0], le[1]-=q[1];
            }
            else break;
        }
    }
    while(le[0]) an.push_back('0'), le[0]--;
    while(le[1]) an.push_back('1'), le[1]--;
    cout<<an;
}