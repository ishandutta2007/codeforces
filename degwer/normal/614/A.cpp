#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
    ll l,r,k;
    scanf("%I64d%I64d%I64d",&l,&r,&k);
    ll now=1;
    double n=1.0;
    vector<ll>v;
    for(;;)
    {
        if(n>5e18)break;
        if(l<=now&&now<=r)v.push_back(now);
        now*=k;
        n*=k;
    }
    if(v.size()==0)printf("-1\n");
    else
    {
        for(int i=0;i<v.size();i++)
        {
            if(i!=0)printf(" ");
            printf("%I64d",v[i]);
        }
        printf("\n");
    }
}