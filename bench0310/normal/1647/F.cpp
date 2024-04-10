#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int inf=(1<<30);

struct obj
{
    int a=0,b=0; //a>b
    void add(int x)
    {
        if(x>a) a=x;
        else if(x>b) b=x;
        else a=b=inf;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n+2,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    int res=0;
    auto go=[&]()
    {
        int mx=0;
        for(int i=1;i<=n;i++) if(a[i]>a[mx]) mx=i;
        vector<int> l(n+1,inf);
        obj one;
        for(int i=1;i<=mx-1;i++)
        {
            one.add(a[i]);
            if(one.a==inf) break;
            l[i]=(one.a!=a[i]?one.a:one.b);
        }
        obj two;
        for(int i=n;i>=mx+1;i--) two.add(a[i]);
        int u=a[mx],d=two.b;
        for(int i=mx-1;i>=1;i--)
        {
            res+=(l[i]<u&&a[i]>d);
            if(!(d<a[i]||a[i]<u)) break;
            if((d<a[i]&&a[i]<u))
            {
                if(a[i-1]<a[i]) u=a[i];
                else d=a[i];
            }
            else if(d<a[i]) d=a[i];
            else u=a[i];
        }
    };
    go();
    ranges::reverse(a);
    go();
    cout << res << "\n";
    return 0;
}