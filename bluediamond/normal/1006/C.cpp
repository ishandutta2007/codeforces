#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=200000+5;
int n,v[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    int p1=0;
    ll s1=0;
    ll s2=0;
    ll ans=0;
    for(int p2=n+1;p2>=0;p2--)
    {
        s2+=v[p2];
        while(s2>s1 && p1+1<p2)
        {
            p1++;
            s1+=v[p1];
        }
        if(s1==s2)
        {
            ans=s2;
        }
    }
    cout<<ans<<"\n";
    return 0;
}