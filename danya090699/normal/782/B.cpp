#include <bits/stdc++.h>
using namespace std;
int n;
double *co, *sp, eps=0.0000001;
double f(double p)
{
    double an=-1e9;
    for(int a=0; a<n; a++) an=max(an, abs(co[a]-p)/sp[a]);
    return an;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    co=new double[n], sp=new double[n];
    for(int a=0; a<n; a++) cin>>co[a];
    for(int a=0; a<n; a++) cin>>sp[a];
    double l=-1, r=2e9;
    for(int a=0; a<100; a++)
    {
        double p1=l+(r-l)/3, p2=r-(r-l)/3;
        if(f(p1)>f(p2)) l=p1;
        else r=p2;
    }
    cout<<fixed<<setprecision(10)<<f(l);
}