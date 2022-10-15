#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n,v[105];
int mi,ma;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    mi=ma=v[1];
    for(int i=2;i<=n;i++)
    {
        mi=min(mi,v[i]);
        ma=max(ma,v[i]);
    }
    int p1,p2;
    for(int i=1;i<=n;i++)
        if(v[i]==ma)
        {
            p1=i;
            break;
        }
    for(int i=n;i>=1;i--)
        if(v[i]==mi)
        {
            p2=i;
            break;
        }
    if(p1<p2)
        cout<<p1-1+n-p2<<"\n";
    else
        cout<<p1-1+n-p2-1<<"\n";
    return 0;
}
/**

**/