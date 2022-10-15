#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=200000;
int n,q;
int cnt[N+5];
int v[N+5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    sort(v+1,v+n+1);
    for(int i=1;i<=q;i++)
    {
        int a,b;
        cin>>a>>b;
        cnt[a]++;
        cnt[b+1]--;
    }
    for(int i=1;i<=n;i++)
    {
        cnt[i]+=cnt[i-1];
    }
    sort(cnt+1,cnt+n+1);
    ll sol=0;
    for(int i=1;i<=n;i++)
    {
        sol+=(ll)v[i]*cnt[i];
    }
    cout<<sol<<"\n";
    return 0;
}
/**

**/