#include <bits/stdc++.h>
using namespace std;
bool comp(string &a, string &b){return a.size()<b.size();}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=1;
    cin>>n;
    string s[n];
    for(int a=0; a<n; a++) cin>>s[a];
    sort(s, s+n, comp);
    for(int a=1; a<n; a++)
    {
        bool ok=0;
        for(int b=0; b<=(s[a].size()-s[a-1].size()); b++) if(s[a].substr(b, s[a-1].size())==s[a-1]) ok=1;
        if(ok==0) an=0;
    }
    if(an)
    {
        cout<<"YES\n";
        for(int a=0; a<n; a++) cout<<s[a]<<"\n";
    }
    else cout<<"NO";
}