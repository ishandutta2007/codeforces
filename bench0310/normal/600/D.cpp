#include <bits/stdc++.h>

using namespace std;

const long double pi=3.1415926535897932384626433832795028841;

long long squarell(long long a)
{
    return a*a;
}

long long lensquare(pair<long long,long long> a,pair<long long,long long> b)
{
    return squarell(a.first-b.first)+squarell(a.second-b.second);
}

long double square(long double a)
{
    return a*a;
}

long double len(pair<long double,long double> a,pair<long double,long double> b)
{
    return sqrtl(square(a.first-b.first)+square(a.second-b.second));
}

long double area_sector(long double r,long double alpha)
{
    return alpha*square(r)/2;
}

long double opposite_angle(long double a,long double b,long double op)
{
    return acosl((square(a)+square(b)-square(op))/(2*a*b));
}

int main()
{
    long long x[2],y[2],r[2];
    for(int i=0;i<2;i++) cin >> x[i] >> y[i] >> r[i];
    if(r[0]>r[1])
    {
        swap(x[0],x[1]);
        swap(y[0],y[1]);
        swap(r[0],r[1]);
    }
    cout << fixed << setprecision(14);
    if(lensquare({x[0],y[0]},{x[1],y[1]})>=squarell(r[0]+r[1])) cout << 0 << endl;
    else if(lensquare({x[0],y[0]},{x[1],y[1]})<=squarell(r[1]-r[0])) cout << area_sector(r[0],2*pi) << endl;
    else
    {
        long double d=len({x[0],y[0]},{x[1],y[1]});
        long double alpha=opposite_angle(d,r[0],r[1]);
        long double one=area_sector(r[0],2*alpha)-square(r[0])*cosl(alpha)*sinl(alpha);
        long double beta=opposite_angle(d,r[1],r[0]);
        long double two=area_sector(r[1],2*beta)-square(r[1])*cosl(beta)*sinl(beta);
        cout << one+two << endl;
    }
    return 0;
}