#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
LL F(LL a)
{
    LL i=1;
    for(;i*(i-1)<2*a;i++);
    if(i*(i-1)!=2*a)return -1;
    else return i;
}
int main()
{
    LL a,b,c,d;
    while(scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&d)==4)
    {
        LL x=F(a),y=F(d);
        if(a==0)
        {
            if(b==0 && c==0)x=0;
            else x=1;
        }
        if(d==0)
        {
            if(b==0 && c==0)y=0;
            else y=1;
        }
//        cout<<"Y+"<<x<<endl;
//        cout<<"Y+"<<y<<endl;
        if(x==-1 || y==-1)puts("Impossible");
        else if(b+c!=x*y)puts("Impossible");
        else if(x+y>1000000)puts("Impossible");
        else if(!a && !b && !c && !d)puts("0");
        else
        {
            LL i=0,j=0;
            for(;i<x;i++)
            {
                while(c>=x-i && j<y)printf("1"),c-=(x-i),j++;
                printf("0");
            }
            for(;j<y;j++)printf("1");
            puts("");
        }
    }
    return 0;
}