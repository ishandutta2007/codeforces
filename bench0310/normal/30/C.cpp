#include <bits/stdc++.h>

using namespace std;

bool comp(tuple<int,int,int,double> &a,tuple<int,int,int,double> &b)
{
    return get<2>(a)<get<2>(b);
}

double dist(double a,double b,double c,double d)
{
    return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<tuple<int,int,int,double> > v;
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        double d;
        cin >> a >> b >> c >> d;
        v.push_back(make_tuple(a,b,c,d));
    }
    sort(v.begin(),v.end(),comp);
    double f[n];
    double res=0;
    long long x[n],y[n],t[n];
    double p[n];
    for(int i=0;i<n;i++)
    {
        x[i]=get<0>(v[i]);
        y[i]=get<1>(v[i]);
        t[i]=get<2>(v[i]);
        p[i]=get<3>(v[i]);
    }
    for(int o=0;o<n;o++)
    {
        f[o]=0;
        for(int i=0;i<o;i++)
        {
            if((double)(t[o]-t[i])>=dist(x[o],y[o],x[i],y[i]))
            {
                f[o]=max(f[o],f[i]);
            }
        }
        f[o]+=p[o];
        res=max(res,f[o]);
    }
    cout << fixed << setprecision(12) << res << endl;
    return 0;
}