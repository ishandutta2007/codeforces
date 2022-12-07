#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin>>n>>s;
        int pref=0, suf=0;
        while(pref<s.size() and s[pref]=='0') pref++;
        while(suf<s.size() and s[s.size()-1-suf]=='1') suf++;
        for(int a=0; a<pref; a++) cout<<'0';
        if(pref+suf<s.size()) cout<<'0';
        for(int a=0; a<suf; a++) cout<<'1';
        cout<<"\n";
    }
}