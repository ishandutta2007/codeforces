//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int n, k;
    cin>>s>>k;
    n=s.size();
    set <char> se;
    for(int a=0; a<n; a++) se.insert(s[a]);
    if(se.size()>=k) cout<<0;
    else
    {
        if(k<=n) cout<<k-se.size();
        else cout<<"impossible";
    }
}