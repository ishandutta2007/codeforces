#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=15+5;

int n,l,r,x;

int st[N],cur=0;
int res=0;
int v[N];

void go(int strat,int tot)
{
    if(strat==n)
    {
        if(cur<=1) return;
        if(l<=tot && tot<=r && st[cur]-st[1]>=x)
        {
            res++;
        }
    }
    else
    {
        go(strat+1,tot);
        st[++cur]=v[strat+1];
        go(strat+1,tot+v[strat+1]);
        cur--;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>l>>r>>x;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    sort(v+1,v+n+1);
    go(0,0);
    cout<<res<<"\n";
    return 0;
}
/**

**/