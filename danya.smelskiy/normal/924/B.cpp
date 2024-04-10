#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define ll long long
#define ld long double
const int N = 2e5 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    ll u;
    cin>>n>>u;
    ld res=0;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int pos=1;
    ld ans=0;
    int c=0;
    for (int i=1; i<=n; i++)
    {
        while (a[i]-a[pos]>u)
            pos++;
        if (i-pos>1)
        {
            ld k=(ld)(a[i]-a[pos+1])/(ld)(a[i]-a[pos]);
            if (k+0.0000000001>ans) ans=k;
            c=1;
        }
    }
    pos=n;
    for (int i=n; i>=1; i--)
    {
        while (a[pos]-a[i]>u)
            pos--;
        if (pos-i>1)
        {
            ld k=(ld)(a[pos]-a[i+1])/(ld)(a[pos]-a[i]);
            if (k+0.0000000001>ans) ans=k;
            c=1;
        }
    }
    if (c==0) cout<<"-1"<<endl; else
    {
        cout.precision(10);
        cout<<fixed;
        cout<<ans<<endl;
    }
}