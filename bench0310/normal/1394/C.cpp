#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int yintercept(int x,int y)
{
    return y-x;
}

array<int,2> horizontal(int x1,int x2,int y,int b)
{
    int x=y-b;
    if(x1<=x&&x<=x2) return {x,y};
    else return {-1,-1};
}

array<int,2> vertical(int x,int y1,int y2,int b)
{
    int y=x+b;
    if(y1<=y&&y<=y2) return {x,y};
    else return {-1,-1};
}

array<int,2> max(array<int,2> a,array<int,2> b)
{
    if(a[0]<0||a[1]<0) return b;
    else if(b[0]<0||b[1]<0) return a;
    else if(a[0]+a[1]>=b[0]+b[1]) return a;
    else return b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int inf=(1<<30);
    int n;
    cin >> n;
    vector<array<int,2>> v(n,{0,0});
    for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        for(char c:s) v[i][c=='N']++;
    }
    auto solve=[&](int d)->array<int,2>
    {
        int x1=-inf;
        int x2=inf;
        int y1=-inf;
        int y2=inf;
        int b1=-inf;
        int b2=inf;
        for(auto [x,y]:v)
        {
            x1=max(x1,x-d);
            x2=min(x2,x+d);
            y1=max(y1,y-d);
            y2=min(y2,y+d);
            b1=max(b1,yintercept(x+d,y));
            b2=min(b2,yintercept(x-d,y));
        }
        if(x1>x2||y1>y2||b1>b2) return {-1,-1};
        array<int,2> a={-1,-1};
        if(b1<=yintercept(x2,y2)&&yintercept(x2,y2)<=b2) a=max(a,{x2,y2});
        a=max(a,horizontal(x1,x2,y2,b1));
        a=max(a,horizontal(x1,x2,y2,b2));
        a=max(a,vertical(x2,y1,y2,b1));
        a=max(a,vertical(x2,y1,y2,b2));
        if(a[0]>=0&&a[1]>=0&&a[0]+a[1]>=1) return a;
        else return {-1,-1};
    };
    int l=-1,r=1000000;
    while(l<r-1)
    {
        int m=(l+r)/2;
        if(solve(m)[0]!=-1) r=m;
        else l=m;
    }
    cout << r << "\n";
    auto [x,y]=solve(r);
    cout << string(x,'B')+string(y,'N') << "\n";
    return 0;
}