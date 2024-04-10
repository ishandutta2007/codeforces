#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
const double EPS=1e-8;
const ll INF=ll(1e18);
typedef pair<int,ll> ill;
int main()
{
    int ty;
    cin>>ty;
    int h,m;
    scanf("%d:%d",&h,&m);
    if(ty==12)
    {
        if(!(h>=1&&h<=12))
        {
            if(h==0)
            {
                h=1;
            }
            else
            {
                h=h%10;
                if(h==0)h=10;
            }
        }
        if(!(m>=0&&m<=59))
        {
            m=m%10+10;
        }
    }
    else
    {
        if(!(h>=0&&h<=23))
        {
            h=h%10;
        }
        if(!(m>=0&&m<=59))
        {
            m=m%10+10;
        }
    }
    printf("%02d:%02d\n",h,m);
}