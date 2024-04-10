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
        int x,y,a,b;
        cin >> x >> y >> a >> b;
        double l=0,r=min(x/a,y/b);
        auto f=[&](double p)->double
        {
            return p+min((x-p*a)/b,(y-p*b)/a);
        };
        for(int e=0;e<1000;e++)
        {
            double m1=l+(r-l)/3;
            double m2=r-(r-l)/3;
            double one=f(m1);
            double two=f(m2);
            if(one<two) l=m1;
            else r=m2;
        }
        int res=0;
        int one=max(0,int(l)-10);
        int two=min({x/a,y/b,int(l)+10});
        for(int i=one;i<=two;i++) res=max(res,i+min((x-i*a)/b,(y-i*b)/a));
        cout << res << "\n";
    }
    return 0;
}