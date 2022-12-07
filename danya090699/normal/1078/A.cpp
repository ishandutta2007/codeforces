#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    double A, B, C, x1, y1, x2, y2;
    cin>>A>>B>>C>>x1>>y1>>x2>>y2;
    double an=abs(x1-x2)+abs(y1-y2);
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            double x3=x1, y3=y1, x4=x2, y4=y2, add;
            bool ok=1;
            if(i==0)
            {
                if(B==0) ok=0;
                else y3=(-1.0*A*x1-C)/B;
            }
            else
            {
                if(A==0) ok=0;
                else x3=(-1.0*B*y1-C)/A;
            }
            if(j==0)
            {
                if(B==0) ok=0;
                else y4=(-1.0*A*x2-C)/B;
            }
            else
            {
                if(A==0) ok=0;
                else x4=(-1.0*B*y2-C)/A;
            }
            if(ok) an=min(an, abs(x1-x3)+abs(y1-y3)+abs(x2-x4)+abs(y2-y4)+sqrt(pow(x3-x4, 2)+pow(y3-y4, 2)));
        }
    }
    cout<<fixed<<setprecision(10)<<an;
}