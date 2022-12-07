#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, l=-1e9, r=1e9;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    string s;
    cin>>s;
    for(int a=4; a<n; a++)
    {
        if(s[a-1]=='1' and s[a]=='0')
        {
            for(int b=a; b>=a-4; b--) r=min(r, ar[b]-1);
        }
        if(s[a-1]=='0' and s[a]=='1')
        {
            for(int b=a; b>=a-4; b--) l=max(l, ar[b]+1);
        }
    }
    cout<<l<<" "<<r;
}