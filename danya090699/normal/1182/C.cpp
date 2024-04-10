#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10;
char buf[sz];
void get(string &s)
{
    scanf("%s", buf);
    for(int a=0; buf[a]; a++) s.push_back(buf[a]);
}
void put(string &s)
{
    for(int a=0; a<s.size(); a++) printf("%c", s[a]);
    printf(" ");
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    map <int, map <char, vector <string> > > ma;
    for(int a=0; a<n; a++)
    {
        string s;
        get(s);
        char la;
        int q=0;
        for(int b=0; b<s.size(); b++)
        {
            if(s[b]=='a' or s[b]=='e' or s[b]=='o' or s[b]=='u' or s[b]=='i') q++, la=s[b];
        }
        ma[q][la].push_back(s);
    }
    vector <pair <string, string> > good, bad;
    for(auto it=ma.begin(); it!=ma.end(); it++)
    {
        vector <string> sp;

        map <char, vector <string> > &cu=(*it).second;

        for(auto it2=cu.begin(); it2!=cu.end(); it2++)
        {
            vector <string> &sp2=(*it2).second;

            while(sp2.size()>1)
            {
                good.push_back({sp2.back(), ""});
                sp2.pop_back();
                good.back().second=sp2.back();
                sp2.pop_back();
            }

            if(sp2.size()) sp.push_back(sp2[0]);
        }

        while(sp.size()>1)
        {
            bad.push_back({sp.back(), ""});
            sp.pop_back();
            bad.back().second=sp.back();
            sp.pop_back();
        }
    }
    while(bad.size()<good.size())
    {
        bad.push_back(good.back());
        good.pop_back();
    }
    cout<<good.size()<<"\n";
    for(int a=0; a<good.size(); a++)
    {
        put(bad[a].first);
        put(good[a].first);
        printf("\n");
        put(bad[a].second);
        put(good[a].second);
        printf("\n");
    }
}