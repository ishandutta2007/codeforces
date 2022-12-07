#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s, t;
    cin>>s>>t;
    int n=s.size();
    int ar[n];
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        ar[a]--;
    }
    int l=0, r=n;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        bool us[n];
        for(int a=0; a<n; a++) us[a]=0;
        for(int a=0; a<mid; a++) us[ar[a]]=1;
        int yk=0;
        for(int a=0; a<n; a++)
        {
            if(us[a]==0 and s[a]==t[yk]) yk++;
            if(yk==t.size()) break;
        }
        if(yk==t.size()) l=mid;
        else r=mid;
    }
    cout<<l;
}