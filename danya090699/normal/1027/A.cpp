#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int n, ok=1;
        string s;
        cin>>n>>s;
        for(int a=0; a<n-1-a; a++)
        {
            int d=abs(s[a]-s[n-1-a]);
            if(d>2 or d%2==1) ok=0;
        }
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
}