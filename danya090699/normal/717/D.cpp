#include <bits/stdc++.h>
using namespace std;
const int sz=128;
int n, x;
double ar[sz];
struct ma
{
    double m[sz][sz];
};
void um(ma &m1, ma &m2, ma &re)
{
    for(int a=0; a<sz; a++)
    {
        for(int b=0; b<sz; b++)
        {
            re.m[a][b]=0;
            for(int c=0; c<sz; c++) re.m[a][b]+=m1.m[a][c]*m2.m[c][b];
        }
    }
}
ma po(int st)
{
    ma re;
    if(st==0)
    {
        for(int a=0; a<sz; a++) for(int b=0; b<sz; b++) re.m[a][b]=(a==b);
    }
    else
    {
        if(st%2==1)
        {
            ma m1=po(st-1), m2;
            for(int a=0; a<sz; a++) for(int b=0; b<sz; b++) m2.m[a][b]=ar[(a^b)];
            um(m1, m2, re);
        }
        else
        {
            ma m1=po(st/2), m2;
            m2=m1;
            um(m1, m2, re);
        }
    }
    return re;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>x;
    for(int a=0; a<sz; a++) ar[a]=0;
    for(int a=0; a<=x; a++) cin>>ar[a];
    ma an=po(n);
    cout<<fixed<<setprecision(10)<<(1-an.m[0][0]);
}