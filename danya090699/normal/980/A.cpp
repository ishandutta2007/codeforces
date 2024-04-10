#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int n=s.size(), q=0;
    for(int a=0; a<n; a++) if(s[a]=='o') q++;
    if(q==0) cout<<"YES";
    else
    {
        if((n-q)%q==0) cout<<"YES";
        else cout<<"NO";
    }
}