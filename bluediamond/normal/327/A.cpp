#include <bits/stdc++.h>

using namespace std;

int n,v[105];
int p[105],s[105];
int c0[105];
int ans=0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<=n;i++)
        p[i]=p[i-1]+(v[i]==1);
    for(int i=n;i>=1;i--)
        s[i]=s[i+1]+(v[i]==1);
    for(int i=1;i<=n;i++)
        c0[i]=c0[i-1]+(v[i]==0);
    for(int st=1;st<=n;st++)
        for(int dr=st;dr<=n;dr++)
        {
            ans=max(ans,p[st-1]+s[dr+1]+c0[dr]-c0[st-1]);
        }
    cout<<ans<<"\n";
    return 0;
}