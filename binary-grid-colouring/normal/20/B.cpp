#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll a,b,c;
   	cin>>a>>b>>c; 
    if(a==0)
    {
        if(b==0)printf("%d",(c==0 ? -1 : 0));
        else printf("1\n%.10f",-1.0*c/b);
    }
    else
    {
        double res[2];
        ll det=b*b-4*a*c;
        if(det<0)printf("0");
        else if(det==0)printf("1\n%.10f",-0.5*b/a);
        else
        {
            res[0]=(-b+sqrt(det))/(2*a);
            res[1]=(-b-sqrt(det))/(2*a);
            sort(res,res+2);
            printf("2\n%.10f\n%.10f",res[0],res[1]);
        }
    }
    return 0;
}