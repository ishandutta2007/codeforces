#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
set<long long> s;
int main()
{
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    long long e=a*b,f=c*d;
    long long g=__gcd(e,f);
    e/=g;
    f/=g;
    while(g%2==0)
        g/=2;
    while(g%3==0)
        g/=3;
    int x=0,y=0,i=0,j=0;
    while(e%2==0)
    {
        x++;
        e/=2;
    }
    while(f%2==0)
    {
        y++;
        f/=2;
    }
    while(e%3==0)
    {
        i++;
        e/=3;
    }
    while(f%3==0)
    {
        j++;
        f/=3;
    }
    if(e!=1||f!=1)
    {
        printf("-1\n");
        return 0;
    }
    int k=abs(i-j)+abs(i+x-j-y);
    cout<<k<<endl;
    while(i>j)
    {
        if(a%3==0)
        {
            a/=3;
            a*=2;
        }
        else
        {
            b/=3;
            b*=2;
        }
        i--;
        x++;
    }
    while(j>i)
    {
        if(c%3==0)
        {
            c/=3;
            c*=2;
        }
        else
        {
            d/=3;
            d*=2;
        }
        j--;
        y++;
    }
    while(x>y)
    {
        if(a%2==0)
            a/=2;
        else
            b/=2;
        x--;
    }
    while(y>x)
    {
        if(c%2==0)
            c/=2;
        else
            d/=2;
        y--;
    }
    cout<<a<<' '<<b<<endl<<c<<' '<<d<<endl;
}