#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, ok=0;
    string s;
    cin>>s;
    n=s.size();
    for(int a=0; a+3<=n; a++)
    {
        set <char> se;
        for(int b=a; b<a+3; b++) if(s[b]!='.') se.insert(s[b]);
        if(se.size()==3) ok=1;
    }
    if(ok) cout<<"Yes";
    else cout<<"No";
}