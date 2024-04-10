#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        double tc,tm,tp,v;
        cin >> tc >> tm >> tp >> v;
        double e=0;
        const double eps=1e-9;
        function<void(double,double,double)> two=[&](double c,double p,double w)
        {
            e+=w;
            if(c<=v+eps) e+=(w*c);
            else two(c-v,p+v,w*c);
        };
        function<void(double,double,double,double)> three=[&](double c,double m,double p,double w)
        {
            e+=w;
            if(c<=v+eps) two(m+c/2,p+c/2,w*c);
            else three(c-v,m+v/2,p+v/2,w*c);
            if(m<=v+eps) two(c+m/2,p+m/2,w*m);
            else three(c+v/2,m-v,p+v/2,w*m);
        };
        three(tc,tm,tp,1);
        cout << fixed << setprecision(12) << e << "\n";
    }
    return 0;
}