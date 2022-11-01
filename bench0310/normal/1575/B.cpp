#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<array<int,2>> v;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        if(x!=0||y!=0) v.push_back({x,y});
        else k--;
    }
    n=v.size();
    vector<double> alpha(n);
    vector<double> d(n);
    const double pi=numbers::pi;
    for(int i=0;i<n;i++)
    {
        auto [x,y]=v[i];
        alpha[i]=atan2(x,y);
        if(alpha[i]<0) alpha[i]+=(2*pi);
        d[i]=hypot(x,y);
    }
    double l=0,r=200000;
    for(int o=0;o<100;o++)
    {
        double m=(l+r)/2;
        vector<pair<double,int>> e;
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(d[i]>2*m) continue;
            double b=acos(d[i]/(2*m));
            double x=alpha[i]-b;
            if(x<0) x+=(2*pi);
            double y=alpha[i]+b;
            if(y>=2*pi) y-=(2*pi);
            e.push_back({x,1});
            e.push_back({y,-1});
            c+=(x>y);
        }
        int mx=c;
        ranges::sort(e);
        int tmp=e.size();
        for(int i=0;i<tmp;i++) e.push_back(e[i]);
        for(auto [x,t]:e)
        {
            c+=t;
            mx=max(mx,c);
        }
        if(mx>=k) r=m;
        else l=m;
    }
    cout << fixed << setprecision(10) << r << "\n";
    return 0;
}