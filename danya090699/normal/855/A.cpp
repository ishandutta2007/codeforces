//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    set <string> se;
    for(int a=0; a<n; a++)
    {
        string s;
        cin>>s;
        if(se.find(s)!=se.end()) cout<<"YES\n";
        else cout<<"NO\n";
        se.insert(s);
    }
}