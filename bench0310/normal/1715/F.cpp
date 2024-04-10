#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<bool> prime(1001,1);
    vector<int> primes;
    for(int i=2;i<=1000;i++)
    {
        if(prime[i])
        {
            for(int j=i*i;j<=1000;j+=i) prime[j]=0;
            if(i>397&&primes.size()<50) primes.push_back(i);
        }
    }
    int n,m;
    cin >> n >> m;
    const double eps=1e-13;
    auto q=[&](vector<array<double,2>> v)->double
    {
        cout << "? " << v.size() << endl;
        for(auto [x,y]:v) cout << fixed << setprecision(15) << x << " " << y << endl;
        double s;
        cin >> s;
        return s;
    };
    const int N=100;
    auto get_coordinate=[&](int sw)->double
    {
        auto gen_query=[&](double s)->vector<array<double,2>>
        {
            vector<array<double,2>> v;
            v.push_back({N+1,s});
            for(int i=1;i<=50;i++)
            {
                v.push_back({0,s});
                v.push_back({0,s+1});
                v.push_back({N,s+1});
                if(i<50) v.push_back({N,s+2});
                else v.push_back({N+1,s+2});
                s+=2;
            }
            if(sw) for(auto &[x,y]:v) swap(x,y);
            return v;
        };
        double s=q(gen_query(0));
        double t=q(gen_query(1-s));
        if(abs(1-t)<eps) return 1-s;
        else return 1+s;
    };
    double x=get_coordinate(1);
    double y=get_coordinate(0);
    vector<array<double,2>> v;
    v.push_back({N+1,y});
    vector<array<double,3>> e;
    const double scale=1e-7;
    for(int i=1;i<=50;i++)
    {
        v.push_back({x,y});
        int p=primes[i-1];
        v.push_back({N,y+(N-x)*p*scale});
        for(int j=0;j<50;j++) e.push_back({x+2*j,y,(4*j+1)*scale*p/2});
        if(i<50) v.push_back({N,y+2});
        else v.push_back({N+1,y+2});
        y+=2;
    }
    double s=q(v);
    array<double,3> res={1e60,0,0};
    for(auto [tx,ty,area]:e) res=min(res,{abs(area-s),tx,ty});
    assert(res[0]<eps);
    cout << fixed << setprecision(15) << "! " << res[1] << " " << res[2] << endl;
    return 0;
}