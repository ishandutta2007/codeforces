#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=1000+5;
int n,k;
int v[N];
int a,b,c,d;

bool ok()
{
    for(int i=1;i<=n;i++)
    {
        if(v[i]==a)
            if(v[i-1]==b || v[i+1]==b)
                return 0;
        if(v[i]==c)
            if(v[i-1]==d || v[i+1]==d)
                return 0;
    }
    return 1;
}

int ans[N],p=0;

/// aux :
map< pair<int,int> , int >mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    cin>>a>>b>>c>>d;
    v[1]=a;
    v[n]=b;
    int cnt=1;
    for(int i=2;i<n;i++)
    {
        while(cnt==a || cnt==b)
            cnt++;
        v[i]=cnt++;
    }
    bool este=0;
    for(int i=1;i<=1000;i++)
    {
        random_shuffle(v+2,v+n);
        if(ok())
        {
            este=1;
            break;
        }
    }
    if(este==0 || k<n+1)
    {
        cout<<"-1\n";
        return 0;
    }
    int p1,p2;
    for(int i=1;i<=n;i++)
    {
        if(v[i]==c) p1=i;
        if(v[i]==d) p2=i;
    }
    bool s=0;
    if(p1>p2) {
        swap(p1,p2);
        s=1;
    }
    for(int i=p1;i>=1;i--) ans[++p]=v[i];
    for(int i=p1+1;i<p2;i++) ans[++p]=v[i];
    for(int i=n;i>=p2;i--) ans[++p]=v[i];
    if(s)
        reverse(ans+1,ans+n+1);
    for(int i=1;i<=n;i++) cout<<v[i]<<" ";
    cout<<"\n";
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<"\n";

    return 0;
}