#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n, ok=0;
        string s;
        cin>>n>>s;
        for(int a=0; a+10<n; a++) if(s[a]=='8') ok=1;
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
}