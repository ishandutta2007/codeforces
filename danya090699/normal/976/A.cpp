#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    string s;
    cin>>n>>s;
    if(s.size()==1) cout<<s;
    else
    {
        int q=0;
        for(int a=0; a<s.size(); a++) if(s[a]=='0') q++;
        cout<<1;
        for(int a=0; a<q; a++) cout<<0;
    }
}