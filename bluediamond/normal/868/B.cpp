#include <iostream>
using namespace std;
bool in1(double a,double b,double c)
{
    if(a<b)
    {
        if(a<c and c<b)
            return 0;
        return 1;
    }
    if(c<b or c>a)
        return 0;
    return 1;
}
bool in2(double a,double b,double c)
{
    if(a<b)
    {
        if(a<c and c<b)
            return 1;
        return 0;
    }
    if(c>a or c<b)
        return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    double h,m,s,t1,t2,ok=1;
    cin>>h>>m>>s>>t1>>t2;
    h+=(m/60+s/3600);
    h*=5;
    m+=s/60;
    if(h>60)
        h-=60;
    if(m>60)
        m-=60;
    t1*=5;
    t2*=5;
    if(t1>60)
        t1-=60;
    if(t2>60)
        t2-=60;
    ///pe sus
    ok=1;
    ///cout<<t1<<" "<<t2<<"\n";
    ///cout<<h<<" "<<m<<" "<<s<<"\n";
    if(in1(t1,t2,h))ok=0;
    if(in1(t1,t2,m))ok=0;
    if(in1(t1,t2,s))ok=0;
    if(ok)
    {
        cout<<"YES";
        return 0;
    }
    ok=1;
    if(in2(t1,t2,h))ok=0;
    if(in2(t1,t2,m))ok=0;
    if(in2(t1,t2,s))ok=0;
    if(ok)
    {
        cout<<"YES";
        return 0;
    }
    cout<<"NO";
    return 0;
}