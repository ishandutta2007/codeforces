#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=200000;

int n,k;
int v[N+5];

struct info
{
    int x,ap;
};

info sl[N+5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    sort(v+1,v+n+1);
    int y=0;
    for(int i=1;i<=n;i++)
    {
        if(v[i]!=v[i-1])
        {
            y++;
            sl[y].x=v[i];
        }
        sl[y].ap++;
    }
    int sol=0;
    for(int i=2;i<=y;i++)
    {
        if(sl[i].x<=sl[i-1].x+k)
            sol+=sl[i-1].ap;
    }
    cout<<(n-sol);
    return 0;
}
/**

**/